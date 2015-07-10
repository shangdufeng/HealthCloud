#pragma once
#include "Row.h"
#include <fstream>
class CSheet1
{
public:
	CSheet1(void);
	~CSheet1(void);

	int loadFrom(std::ifstream& in);  
	int getRowCount(void);  
	CRow1 getRow(int i);  
private:  
	CTypedPtrArray<CPtrArray, CStringArray*> m_rows;  
};

