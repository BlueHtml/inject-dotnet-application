#include "ConstantUtil.h"


#pragma comment(lib,"jsoncpp_static.lib")

using namespace std;

void TCHAR2Char(const TCHAR* tchar, char* _char)
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//��tcharֵ����_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

string GetInstanceFolderPath(HMODULE inptr)
{
	string exePath = "";
	TCHAR tcFullPath[MAX_PATH];
	char* pChPath = new char[MAX_PATH];
	memset(pChPath, '\0', MAX_PATH);
	/** ��ȡ��ǰ�����ִ��·��exe·�� */
	GetModuleFileName(inptr, tcFullPath, MAX_PATH);
	/** ��tcharתΪchar */
	TCHAR2Char(tcFullPath, pChPath);
	exePath = string(pChPath);

	string dirPath = "";
	size_t iPos = exePath.rfind("\\");
	dirPath = exePath.substr(0, iPos);
	/** �ͷ���Դ */
	delete[] pChPath;
	return dirPath;
}



ConstantUtil::ConstantUtil()
{
	m_basePath = _strdup(GetInstanceFolderPath(NULL).c_str());
}

ConstantUtil::ConstantUtil(HMODULE inptr)
{
	//��ȡ��ǰ·��
	m_basePath = _strdup(GetInstanceFolderPath(inptr).c_str());

}

Json::Value ConstantUtil::ReadJsonFromFile(const char* path)
{
	Json::Reader reader;// ����json��Json::Reader   
	Json::Value root; // Json::Value��һ�ֺ���Ҫ�����ͣ����Դ����������͡���int, string, object, array         

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
	//���ֽڱ���ת���ɿ��ֽڱ���
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';//����ַ�����β
	//ɾ��������������ֵ
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







