#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, std::string> hashMap = {
		{"China", "BeiJin"},
		{"American", "Washtong DC"},
		{"Japan", "Tokyo"},
		{"England", "London"}
	};
	
	for(auto itr = hashMap.begin(); itr != hashMap.end(); ++itr)
	{
		std::cout<<itr->first<<"----"<<itr->second<<std::endl;
	}
	
	std::cout<<"capacity: "<<hashMap.max_size()<<std::endl;	
	std::cout<<"load_factor: "<<hashMap.load_factor()<<std::endl;	
	unsigned int bucketCnt = hashMap.bucket_count();
	std::cout<<"bucket count: "<<bucketCnt<<std::endl;
	for(unsigned int index = 0; index < bucketCnt; ++index) {
		std::cout<<"bucket index: "<<index<<std::endl;
		for(auto itr = hashMap.begin(index); itr != hashMap.end(index); ++itr) 
		{
			std::cout<<itr->first<<"------>"<<itr->second<<std::endl;
		}
	}
	std::cout<<std::endl;
	
	hashMap.insert(std::make_pair("France", "Paris"));
	hashMap.insert(std::make_pair("Rusia", "Moscow"));
	std::cout<<"bucket count: "<<hashMap.bucket_count()<<std::endl;
	return 0;
}
