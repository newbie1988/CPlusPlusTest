#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> strs;
	strs.push_back("hello");
	strs.push_back("this");
	strs.push_back("is");
	strs.push_back("an");
	strs.push_back("apple");

	for(std::string elem : strs)
	{
		std::cout<<elem<<" ";
	}
	std::cout<<std::endl;
	
	std::for_each(std::begin(strs), std::end(strs), [&](std::string elem){ std::cout<<elem<<", ";});
	std::cout<<std::endl;	

	return 0;
}
