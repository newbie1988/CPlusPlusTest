#include <iostream>

class CBase
{
public:
	virtual void print() 
	{
		std::cout<<"CBase::print"<<std::endl;
	}
};

class CDerived : public CBase
{
public:
	void print() override 
	{
		std::cout<<"CDerived::print"<<std::endl;
	}
};

class CDerived2 : public CDerived 
{
public:
	void print() 
	{
		std::cout<<"CDerived2::print"<<std::endl;
	}
};

int main()
{
	CBase* ptr = new CDerived;
	ptr->print();
	delete ptr;
	ptr = nullptr;
	return 0;
}
