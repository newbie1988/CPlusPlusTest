#include <algorithm>
#include <iostream>
#include <map>
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

	for(std::string& elem : strs)
	{
		elem = "1";
	}	
	for(std::string& elem : strs) 
	{
		std::cout<<elem<<" ";	
	}
	std::cout<<std::endl;

	std::for_each(std::begin(strs), std::end(strs), [](std::string elem){ std::cout<<elem<<", ";});
	std::cout<<std::endl;	

	std::map<std::string, int> persons;
	persons["Jack"] = 12;
	persons["Lily"] = 2;
	persons["Mike"] = 5;
	persons["Tim"] = 8;
	for(auto& itr : persons)
	{
		std::cout<<"name: "<<itr.first<<", age: "<<itr.second<<std::endl;
	}
	return 0;
}
