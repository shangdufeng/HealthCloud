#include "StdAfx.h"
#include "Sheet.h"


CSheet1::CSheet1(void)
{
}


CSheet1::~CSheet1(void)
{
	for (int i = 0; i<m_rows.GetCount(); i++)  
	{  
		delete m_rows.GetAt(i);  
	} 
}

int CSheet1::loadFrom(std::ifstream& in)  
{  
	int lines = 0;  
	while(!in.eof())  
	{  
		//读取其中一行  
		char line[256] = {0};  
		in.getline(line, 255);  
		CString s = /*(CString)*/static_cast<CString>(line);  

		//空白行则跳过  
		if (s.IsEmpty())  
			continue;  
		//#为注释标记，跳过  
		if (s[0]=='#')  
			continue;  
		CStringArray* pRow = new CStringArray();  
		int i = 0;  
		CString token = s.Tokenize(_T(",\t"), i);  
		while (token!=_T(""))  
		{  
			pRow->Add(token);  
			token = s.Tokenize(_T(",\t"), i);  
		}  
		m_rows.Add(pRow);  
		lines++;  
	}  
	return lines;  
}  
int CSheet1::getRowCount(void)  
{  
	return m_rows.GetCount();  
}  
CRow1 CSheet1::getRow(int i)  
{  
	return CRow1(m_rows.GetAt(i));  
}  
