#include <iostream>
#include <memory>

class CTest 
{
public:
	CTest() 
	{
		std::cout<<"CTest::CTest()"<<std::endl;
	}
	~CTest() 
	{
		std::cout<<"CTest::~CTest()"<<std::endl;	
	}
};

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
	std::shared_ptr<CTestB> m_test;
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
	std::shared_ptr<CTestA> m_test;
};

int main()
{
#if 0
	std::shared_ptr<CTest> test = std::make_shared<CTest>();
	std::cout<<"reference count: "<<test.use_count()<<std::endl;
	{
		std::shared_ptr<CTest> test1(test);
		std::cout<<"reference count1: "<<test.use_count()<<std::endl;
	}
	
	{
		std::shared_ptr<CTestA> testA = std::make_shared<CTestA>();
		testA->SetReference(test);
		std::cout<<"reference count3: "<<test.use_count()<<std::endl;
	}
	std::cout<<"reference count2: "<<test.use_count()<<std::endl;
#else
	std::shared_ptr<CTestB> test;
	{
		std::shared_ptr<CTestA> testA = std::make_shared<CTestA>();
		std::shared_ptr<CTestB> testB = std::make_shared<CTestB>();
		testA->SetReference(testB);
		testB->SetReference(testA);
		test = testB;
	}
	std::cout<<"reference count2: "<<test.use_count()<<std::endl;
#endif
	return 0;
}

