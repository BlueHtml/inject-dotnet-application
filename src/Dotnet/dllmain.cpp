// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "framework.h"
#include "Dotnet.h"
#include "ConstantUtil.h"
#include <thread>
#include "json/value.h"
using namespace std;

Dotnet dotnet;
bool IsLoaded = false;
thread dotnetThread;
/// <summary>
/// 加载程序集
/// </summary>
void Load(HMODULE hModule)
{
	try
	{
		if (IsLoaded)
			return;
		ConstantUtil util = { hModule };
		int argsLength = 2;
		const char* path = util.GetBasePath();
		string jsonPath;
		jsonPath.assign(path);
		jsonPath.append("\\");
		jsonPath.append(JSONFILENAME);
		Json::Value root = util.ReadJsonFromFile(jsonPath.c_str());

		if (root["dotnet"].isNull())
			return;
		if (root["appPath"].isNull())
			return;
		if (!root["appArgs"].isNull())
		{
			Json::Value args = root["appArgs"];
			argsLength += args.size();
		}
		wstring appPath = util.S2ws(path);
		appPath.append(L"\\");
		appPath.append(util.S2ws(root["appPath"].asCString()));

		const char_t** argv = new const char_t * [argsLength];
		wstring dotnetStr = util.S2ws(root["dotnet"].asCString());
		argv[0] = dotnetStr.c_str();
		argv[1] = appPath.c_str();
		wstring* data = new wstring[root["appArgs"].size()];
		Json::Value args = root["appArgs"];
		for (int i = 0; i < root["appArgs"].size(); i++)
		{
			
			data[i] = util.S2ws(args[i].asString());
			argv[(i + 2)] = data[i].c_str();
		}
		Dotnet dotnet = { path };
		dotnet.Init();
		dotnet.Run(argsLength, argv);
		IsLoaded = true;
	}
	catch (const std::exception& ex)
	{
		MessageBox(NULL, ConstantUtil::S2ws(ex.what()).c_str(), L"", 0);
	}
}

/// <summary>
/// 卸载程序集
/// </summary>
void Unload()
{
	if (!IsLoaded)
		return;
	dotnet.UnInit();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		dotnetThread = thread(Load, hModule);
	case DLL_THREAD_ATTACH:
		Unload();
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

