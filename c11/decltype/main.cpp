#include <iostream>

template<class T>
auto myadd(T a, T b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	int a = 5;
	decltype(a) b = a;
	std::cout<<myadd(a, b)<<std::endl;

	std::string aa = R"(\adcbs)";
	decltype(aa) bb = aa;
	std::cout<<myadd(aa, bb)<<std::endl;
	return 0;
}
