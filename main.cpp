#include "vector_algos.hpp"
#include <iostream>


int main()
{
	auto v = read_int_vector();

	std::cout << "Average: " << average(v) << "\n";
	std::cout << "Sum: " << sum(v) << "\n";

	std::cout << "Elements greater than 5: ";
	for (auto e : filter_greater_than(v, 5))
		std::cout << " " << e;
	std::cout << "\n";

	return 0;
}