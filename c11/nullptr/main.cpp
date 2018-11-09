#include <iostream>

//#define NULL 0

class CTest
{
public:
void print(int p)
{
	std::cout<<"NULL"<<std::endl;
}

void print(int* ptr)
{
	std::cout<<"nullptr"<<std::endl;
}
};

int main()
{
	CTest test;
//	test.print(NULL);  compile error, print is ambigous
	std::cout<<"----------------------\n";
	test.print(nullptr);	
	return 0;
}
