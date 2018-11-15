#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	auto func = [](int a, int b) {
			return a + b;
		     };
	int sum = func(2, 3);
	std::cout<<"sum = "<<sum<<std::endl;
	auto func2 = [=] (int a) mutable {
			sum += a;
			return sum;
		      };
	int sum1 = func2(sum);
	std::cout<<"sum = "<<sum<<std::endl;
	std::cout<<"sum1 = "<<sum1<<std::endl;	
	
	auto func3 = [&] (int a) mutable {
			sum += a;
			return sum;
		     };
	int sum2 = func3(sum);
	std::cout<<"sum = "<<sum<<std::endl;
	std::cout<<"sum2 = "<<sum<<std::endl;

	
	std::vector<int> nums;
	for(int i = 0; i < 10; ++i) 
	{
		nums.push_back(i);
	}
	
	auto itr = std::find_if(nums.begin(), nums.end(), [](int val) ->bool {
								return val == 12;
							    }
							  );
	if(nums.end() != itr)
	{
		std::cout<<"find"<<std::endl;
	}
	else
	{
		std::cout<<"not find"<<std::endl;
	}

	std::map<std::string, int> counts;
	counts["Jack"] = 12;
	counts["Lucy"] = 5;
	counts["Lily"] = 8;
	counts["Mike"] = 30;
	
	std::map<std::string, int>::iterator itr1 = std::find_if(counts.begin(), counts.end(), [](const std::map<std::string, int>::value_type& val) {
								return val.second == 30;});	
	if(itr1 != counts.end())
	{
		std::cout<<"name: "<<itr1->first<<", age: "<<itr1->second<<std::endl;
	}
	return 0;
}
