#pragma once
#include "hostfxr.h"
#include <sstream>
#include "framework.h"

//dll名称
#define HOSTFXRNAME "hostfxr.dll"
//入口函数名称
#define MAINFUNCTIONName "hostfxr_main"

class Dotnet
{

public:

	Dotnet();
	/// <summary>
	/// 构造函数
	/// </summary>
	/// <param name="hostfxrPath">hostfxrPath</param>
	Dotnet(const char* hostfxrPath);

	/// <summary>
	/// 初始化
	/// </summary>
	int Init();

	/// <summary>
	/// 卸载
	/// </summary>
	int UnInit();

	/// <summary>
	/// 运行应用程序
	/// </summary>
	/// <param name="argc">参数长度</param>
	/// <param name="argv">参数</param>
	int Run(const int argc, const char_t** argv);

private:
	/// <summary>
	/// 是否初始化
	/// </summary>
	bool m_isInited;

	/// <summary>
	/// hostfxr绝对路径
	/// </summary>
	char* m_hostfxrFullPath;

	/// <summary>
	/// 程序集指针
	/// </summary>
	HMODULE m_libIntptr;

	/// <summary>
	/// 程序主入口方法
	/// </summary>
	hostfxr_main_fn m_mainFunction;

};

