#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::condition_variable cv;
std::mutex mtx;
bool bReady = false;

void run(int i)
{
	std::unique_lock<std::mutex> lock(mtx);
	while(!bReady) 
	{
		cv.wait(lock);
	}
	std::cout<<"i = "<<i<<std::endl;
}

void start()
{
	std::unique_lock<std::mutex> lock(mtx);
	bReady = true;
	std::cout<<"send ready signal"<<std::endl;
	cv.notify_all();
}

int main()
{
	std::vector<std::thread> threads;
	for(int i = 0; i < 10; ++i)
	{
		threads.push_back(std::thread(run, i));
	}
	std::this_thread::sleep_for(std::chrono::seconds(5));
	start();
	for(auto& thread: threads)
	{
		thread.join();
	}

	return 0;
}
