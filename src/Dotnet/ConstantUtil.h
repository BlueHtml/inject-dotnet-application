#pragma once 

#include "hostfxr.h"
#include <direct.h>
#include <string>
#include <stringapiset.h>
#include "json/reader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "framework.h"

#define JSONFILENAME "dotnet.config"

class ConstantUtil
{
public:

	ConstantUtil();

	ConstantUtil(HMODULE inptr);
	/// <summary>
	/// 获取当前路径
	/// </summary>
	/// <returns>当前路径</returns>
	const char* GetBasePath() { return m_basePath; };

	/// <summary>
	/// 读取json文件
	/// </summary>
	Json::Value ReadJsonFromFile(const char* path);

	/// <summary>
	/// 将cstring转wchat_t*
	/// </summary>
	static std::wstring S2ws(std::string str);

	/// <summary>
	/// 拼接字符串
	/// </summary>
	static const wchar_t* AppendWchar(const wchar_t* a, const wchar_t* b);
private:
	const char* m_basePath;
};

