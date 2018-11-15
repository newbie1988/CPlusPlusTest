#include <iostream>
#include <type_traits>

template<class T>
auto add(T t1, T t2) -> decltype(t1)
{
	static_assert(std::is_integral<T>::value, "required integeral");
	return t1 + t2;
}

int main()
{
	int a = 2, b = 5;
	add(a, b);

	return 0;
}


