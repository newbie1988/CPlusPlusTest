#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ints(10, 1);
	for(auto itr = ints.begin(); itr != ints.end(); ++itr)
	{
		std::cout<<*itr<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
