#pragma once
class CRow1
{
public:
	CRow1(CStringArray* row);
	~CRow1();

	int getColumnCount(void);  
	CString getColumn(int i);  
private:  
	CStringArray* m_row;  
};

