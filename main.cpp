#include <iostream>
#include <algorithm>
#include "vector_algos.hpp"

bool custom_comparison(int x, int y)
{
	return x * x < y * y;
}

int main()
{
	std::cout << "Enter at least one number:\n";
	auto v = read_int_vector();

	if (v.empty())
	{
		std::cout << "Must enter at least one number!\n";
		return -1;
	}
	//std::max_element returns iterator to the maximum element between two iterators. To get the value at the iterator we dereference with * operator
	std::cout << "Maximum element: " << *std::max_element(v.begin(), v.end()) << std::endl; 

	// std::min_element and std::max_element can take a custom comparison function. This even allows us to change the comparison min does allowing us to change it to max for example
	std::cout << "Minimum element (normal): " << *std::min_element(v.begin(), v.end()) << std::endl;
	std::cout << "Minimum element (custom comparison): " << *std::min_element(v.begin(), v.end(), custom_comparison) << std::endl;

	std::cout << "Sum: " << sum(v) << std::endl;
	std::cout << "Average: " << average(v) << std::endl;

	// Need to write this function which checks if any negative values are present in list
	if (all_positive(v))
	{
		std::cout << "All numbers you entered are positive!\n";
	}
	else
	{
		std::cout << "You entered at least one negative number!\n";
	}

	//Part of the algorithm's library. Sorts between the iterators. This allows for sorting of partial lists as well
	std::sort(v.begin(), v.end());
	
	std::cout << "Your input, sorted: ";
	display_range(v.begin(), v.end());
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), custom_comparison);
	return 0;
}