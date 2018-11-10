#include <iostream>
#include <string>
#include <thread>

void ThreadFunc1()
{
	std::cout<<"Enter ThreadFunc1"<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout<<"Leave ThreadFunc1"<<std::endl;
}

void ThreadFunc2(int count, std::string name) 
{
	std::cout<<"Enter ThreadFunc2"<<std::endl;
	std::cout<<"count: "<<count<<", name: "<<name<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout<<"Leave ThreadFunc2"<<std::endl;
}

int main()
{
	std::thread thread1(ThreadFunc1);
	std::thread thread2(ThreadFunc2, 12, "Apple");
	std::cout<<"Before join\n";
	thread1.join();
	std::cout<<"After join"<<std::endl;
	std::cout<<"Before Detach"<<std::endl;
	thread2.detach();
	std::cout<<"After Detach\n";

	return 0;
}
