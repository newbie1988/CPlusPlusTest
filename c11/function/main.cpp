#include <functional>
#include <iostream>

typedef std::function<int(int, int)> Func;

class CTest
{
public:
	int sum(const Func& func, int a, int b)
	{
		return func(a, b);
	}
};

class CSum
{
public:
	int sum(int a, int b)
	{
		return a + b + 3;
	}
};

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 1, b = 1;
	CTest test;
	int sum1 = test.sum(sum, a, b);
	std::cout<<"sum1 = "<<sum1<<std::endl;
	CSum sumInst;
	int sum2 = test.sum(std::bind(&CSum::sum, &sumInst, std::placeholders::_1, std::placeholders::_2), a, b);
	std::cout<<"sum2 = "<<sum2<<std::endl;
}
