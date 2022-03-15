#include "Dotnet.h"



Dotnet::Dotnet()
{
}

Dotnet::Dotnet(const char* hostfxrPath)
{
	std::stringstream libPath;
	libPath << hostfxrPath << "\\" << HOSTFXRNAME;
	m_hostfxrFullPath = _strdup(libPath.str().c_str());

}

int Dotnet::Init()
{
	HMODULE m_libIntptr = LoadLibraryA(m_hostfxrFullPath);
	if (m_libIntptr == nullptr)
	{
		return -1;
	}
	m_mainFunction = (hostfxr_main_fn)GetProcAddress(m_libIntptr, MAINFUNCTIONName);
	if (m_mainFunction == nullptr)
	{
		FreeLibrary(m_libIntptr);
		return -1;
	}
	return 0;
}

int Dotnet::UnInit()
{
	if (m_libIntptr == nullptr)
		return -1;
	return FreeLibrary(m_libIntptr);
}

int Dotnet::Run(const int argc, const char_t** argv)
{
	try
	{
		if (m_mainFunction == nullptr)
			return -1;
		return m_mainFunction(argc, argv);
	}
	catch (const std::exception&)
	{

	}

}
