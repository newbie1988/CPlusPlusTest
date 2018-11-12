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

int main()
{
	std::shared_ptr<CTest> test = std::make_shared<CTest>();
	std::cout<<"reference count: "<<test.use_count()<<std::endl;
	{
		std::shared_ptr<CTest> test1(test);
		std::cout<<"reference count1: "<<test.use_count()<<std::endl;
	}
	std::cout<<"reference count2: "<<test.use_count()<<std::endl;
	return 0;
}

