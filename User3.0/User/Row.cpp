#include "StdAfx.h"
#include "Row.h"


CRow1::CRow1(CStringArray* row)
{
	m_row = row; 
}


CRow1::~CRow1()
{
}

int CRow1::getColumnCount(void)  
{  
	return m_row->GetCount();  
}  
CString CRow1::getColumn(int i)  
{  
	return m_row->GetAt(i);  
}  