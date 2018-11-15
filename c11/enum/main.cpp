#include <iostream>

enum class Color : char
{
	White = 0,
	Black,
	Green,
	Red,
};

void printColor(Color color)
{
	std::cout<<"color: "<<static_cast<int>(color)<<std::endl;
}

int main()
{
	Color color = Color::Red;
	printColor(color);
	return 0;
}
