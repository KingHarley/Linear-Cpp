#include "vector_algos.hpp"
#include <iostream>
#include <string>


// Function that reads integer input from the user until they press Ctrl+Z. Returns a vector with the ints
std::vector<int> read_int_vector()
{
	int x = 0;
	std::vector<int> input;

	std::cout << "Enter as many numbers as you like.\n";
	while (true)
	{
		while (std::cin >> x)
			input.push_back(x);

		if (std::cin.eof())
			break;

		std::string s;
		std::cin.clear();
		std::getline(std::cin, s);
		std::cout << "Warning: Ignoring " << s << "\n";
	}

	return input;
}

// Returns an int corresponding to the sum of elements in a vector 
int sum(std::vector<int> v)
{
	int sum = 0;

	for (auto e : v)
		sum += e;

	return sum;
}

// Returns a vector containing the ints which are greater than x inside vector v
std::vector<int> filter_greater_than(std::vector<int> v, int x)
{
	std::vector<int> result;

	for (auto e : v)
	{
		if (e > x)
			result.push_back(e);
	}

	return result;
}