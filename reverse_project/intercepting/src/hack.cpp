#include <string.h>	// must include head file string.h, or it will not work correctly.
//#include <unistd.h>
#include <iostream>

int strcmp(const char *s1, const char *s2)
{
	return 0;
}

#if 0
/*
 * Intercepting sleep will call std::bad_cast
 */
unsigned int sleep (unsigned int __seconds)
{
	std::cout<<"no sleep"<<std::endl;
	return 1;
}
#endif
