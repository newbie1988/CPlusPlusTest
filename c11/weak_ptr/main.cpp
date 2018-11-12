#include <iostream>
#include <memory>

class CTestB;
class CTestA
{
public:
	~CTestA() 
	{
		std::cout<<"CTestA::~CTestA()"<<std::endl;
	}
	void SetReference(const std::shared_ptr<CTestB>& test)
	{
		m_test = test;
	}

private:
	std::weak_ptr<CTestB> m_test;
};

class CTestB
{
public:
	~CTestB()
	{
		std::cout<<"CTestB::~CTestB()"<<std::endl;
	}
	void SetReference(const std::shared_ptr<CTestA>& test)
	{
		m_test = test;
	}
private:
	std::weak_ptr<CTestA> m_test;
};

int main()
{
	std::shared_ptr<CTestA> testA = std::make_shared<CTestA>();
	std::shared_ptr<CTestB> testB = std::make_shared<CTestB>();
	testA->SetReference(testB);
	testB->SetReference(testA);
	std::cout<<"CTestA referenct count: "<<testA.use_count()<<std::endl;
	std::cout<<"CTestB referenct count: "<<testB.use_count()<<std::endl;
	
	return 0;
}

