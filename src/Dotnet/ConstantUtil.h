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
	/// ��ȡ��ǰ·��
	/// </summary>
	/// <returns>��ǰ·��</returns>
	const char* GetBasePath() { return m_basePath; };

	/// <summary>
	/// ��ȡjson�ļ�
	/// </summary>
	Json::Value ReadJsonFromFile(const char* path);

	/// <summary>
	/// ��cstringתwchat_t*
	/// </summary>
	static std::wstring S2ws(std::string str);

	/// <summary>
	/// ƴ���ַ���
	/// </summary>
	static const wchar_t* AppendWchar(const wchar_t* a, const wchar_t* b);
private:
	const char* m_basePath;
};

