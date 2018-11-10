#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int sum(100);

void threadFunc()
{
	while(sum > 0)	
	{
		std::cout<<sum--<<std::endl;
	}
}

int main()
{
	std::vector<std::thread> threads;
	for(int i = 0; i < 10; ++i)
	{
		threads.push_back(std::thread(threadFunc));
	}	
	for(auto& thread : threads) 
	{
		thread.join();
	}
	std::cout<<"sum = "<<sum<<std::endl;	
	return 0;
}
