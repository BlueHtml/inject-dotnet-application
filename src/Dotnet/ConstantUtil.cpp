#include "ConstantUtil.h"


#pragma comment(lib,"jsoncpp_static.lib")

using namespace std;

void TCHAR2Char(const TCHAR* tchar, char* _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

string GetInstanceFolderPath(HMODULE inptr)
{
	string exePath = "";
	TCHAR tcFullPath[MAX_PATH];
	char* pChPath = new char[MAX_PATH];
	memset(pChPath, '\0', MAX_PATH);
	/** 获取当前程序的执行路径exe路径 */
	GetModuleFileName(inptr, tcFullPath, MAX_PATH);
	/** 将tchar转为char */
	TCHAR2Char(tcFullPath, pChPath);
	exePath = string(pChPath);

	string dirPath = "";
	size_t iPos = exePath.rfind("\\");
	dirPath = exePath.substr(0, iPos);
	/** 释放资源 */
	delete[] pChPath;
	return dirPath;
}



ConstantUtil::ConstantUtil()
{
	m_basePath = _strdup(GetInstanceFolderPath(NULL).c_str());
}

ConstantUtil::ConstantUtil(HMODULE inptr)
{
	//获取当前路径
	m_basePath = _strdup(GetInstanceFolderPath(inptr).c_str());

}

Json::Value ConstantUtil::ReadJsonFromFile(const char* path)
{
	Json::Reader reader;// 解析json用Json::Reader   
	Json::Value root; // Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array         

	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string contents(buffer.str());
	t.close();
	if (reader.parse(_strdup(contents.c_str()), root, FALSE))
	{
		return root;
	}

	return NULL;
}

std::wstring ConstantUtil::S2ws(std::string str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//多字节编码转换成宽字节编码
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';//添加字符串结尾
	//删除缓冲区并返回值
	wstring return_value;
	return_value.append(buffer);
	delete[]buffer;
	return return_value;
}

const wchar_t* ConstantUtil::AppendWchar(const wchar_t* a, const wchar_t* b)
{

	wstring str;
	str.append(a);
	str.append(b);
	return str.c_str();
}







