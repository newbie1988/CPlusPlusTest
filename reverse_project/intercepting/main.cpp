#include <string.h>
#include <unistd.h>
#include <iostream>

int main() 
{
	const char* str1 = "ok";
	const char* str2 = "OK";
	if(0 == strcmp(str1, str2))
	{
		std::cout<<"equal\n";
	}
	else
	{
		std::cout<<"not equal\n";
	}
	
	sleep(3);
	return 0;
}	
