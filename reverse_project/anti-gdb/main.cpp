#include <assert.h>
#include <sys/ptrace.h>
#include <iostream>

int main()
{
	if(ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
	{
		std::cout<<"Debuging....Exit"<<std::endl;
		assert(0);
		return -1;
	}
	
	std::cout<<"Main Function Start"<<std::endl;
	return 0;
}
