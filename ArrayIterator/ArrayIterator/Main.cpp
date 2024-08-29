#include <iostream>
#include "Array.h"


int main()
{
	Array<int, 2> array;

	array[0] = 1;
	array[1] = 4;


	for (int i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << std::endl;
	}

	for (Array<int, 2>::Iterator it = array.begin(); it != array.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (int value : array)
	{
		std::cout << value << std::endl;
	}

	std::cin.get();
}
