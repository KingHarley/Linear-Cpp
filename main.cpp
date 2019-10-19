#include "vector_algos.hpp"
#include <iostream>


int main()
{
	auto v = read_int_vector();
	auto sorted_v = sort(v);

	std::cout << "You entered:";
	for (auto e : sorted_v)
		std::cout << " " << e;
	std::cout << "\n";

	for (int i = 0; i < 10; ++i)
	{
		if (binary_search(sorted_v, i))
			std::cout << i << " was one of the numbers you entered!\n";
		else
			std::cout << i << " was not one of the numbers you entered!\n";
	}
		

	return 0;
}