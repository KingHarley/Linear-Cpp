#include "vector_algos.hpp"
#include <iostream>
#include <string>
#include <iterator>

using iterator = std::vector<int>::iterator;  // This is like a typedef, wherever we see iterator we will get what is on the right (How namespaces work I think)

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

// Function that sorts a given vector using QuickSort!
std::vector<int> sort(std::vector<int> v)
{
	// Given a range it will rearrange the first element and return the partition of that elements final place
	iterator partition(iterator begin, iterator end);
	
	// Function that performs most of the sort work
	void sort_impl(iterator begin, iterator end);

	sort_impl(v.begin(), v.end());

	return v;
}

void sort_impl(iterator begin, iterator end)
{
	// Need to redeclare partiton as it was declared in the scope of sort
	iterator partition(iterator begin, iterator end);

	// First check if range is empty or only 1 (end and begin are just like indexes of an element, even though end doesn't correspond to an element, but a sort of imaginary element)
	if (end - begin <= 1)
		return;

	// Rearrange the first element and obtain it's final position
	auto pivot = partition(begin, end);

	// Now let us sort the subranges as well 
	sort_impl(begin, pivot);
	sort_impl(pivot + 1, end);
}

iterator partition(iterator begin, iterator end)
{
	// The increment is weird here. pivot = old begin, while begin = old begin + 1. ie. pivot is one less than begin now.
	auto pivot = begin++;

	for (; begin != end; ++begin)
	{
		if (*pivot > *begin)
		{
			std::swap(*pivot, *begin);
			++pivot;
			std::swap(*pivot, *begin);
		}
	}
	return pivot;
}


// Function that checks if given int is inside given vector
bool binary_search(std::vector<int> v, int x)
{
	iterator bottom = v.begin(), top = v.end();

	while (bottom != top)
	{
		auto mid = (bottom + (top - bottom) / 2);

		if (x < *mid)
			top = mid;
		else if (x > *mid)
			bottom = ++mid;   // If you don't increment mid here then we get stuck in a forever loop
		else
			return true;
	}

	return false;
}

