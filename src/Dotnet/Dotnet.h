#pragma once
#include "hostfxr.h"
#include <sstream>
#include "framework.h"

//dll����
#define HOSTFXRNAME "hostfxr.dll"
//��ں�������
#define MAINFUNCTIONName "hostfxr_main"

class Dotnet
{

public:

	Dotnet();
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="hostfxrPath">hostfxrPath</param>
	Dotnet(const char* hostfxrPath);

	/// <summary>
	/// ��ʼ��
	/// </summary>
	int Init();

	/// <summary>
	/// ж��
	/// </summary>
	int UnInit();

	/// <summary>
	/// ����Ӧ�ó���
	/// </summary>
	/// <param name="argc">��������</param>
	/// <param name="argv">����</param>
	int Run(const int argc, const char_t** argv);

private:
	/// <summary>
	/// �Ƿ��ʼ��
	/// </summary>
	bool m_isInited;

	/// <summary>
	/// hostfxr����·��
	/// </summary>
	char* m_hostfxrFullPath;

	/// <summary>
	/// ����ָ��
	/// </summary>
	HMODULE m_libIntptr;

	/// <summary>
	/// ��������ڷ���
	/// </summary>
	hostfxr_main_fn m_mainFunction;

};

