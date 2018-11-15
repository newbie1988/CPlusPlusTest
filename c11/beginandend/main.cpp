#include <algorithm>
#include <iostream>

int main()
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
	auto first = std::begin(array);
	std::cout<<"first element: "<<*first<<std::endl;
	auto last  = std::end(array);
	auto itr = std::find(first, last, 10);
	if(itr != last)
	{
		std::cout<<"find"<<std::endl;
	}
	else 
	{
		std::cout<<"not find"<<std::endl;
	}
	return 0;
}
