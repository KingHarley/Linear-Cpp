#include "vector_algos.hpp"
#include <iostream>
#include <string>

using iterator = std::vector<int>::iterator;

// Don't repeat default value here as it is known from the header
std::vector<int> read_int_vector(std::istream& stream) // Don'
{
	int x = 0;
	std::vector<int> input;

	while (true)
	{
		while (stream >> x)
			input.push_back(x);

		if (stream.eof())
			break;

		std::string s;
		stream.clear();
		std::getline(stream, s);
		std::cout << "Warning: Ignoring " << s << "\n";
	}

	return input;
}

int sum(std::vector<int> const& v)
{
	int total = 0;
	
	for (auto e : v)
	{
		total += e;
	}
	return total;
}

std::vector<int> filter_greater_than(std::vector<int> const& v, int x)
{
	std::vector<int> result;

	for (auto e : v)
	{
		if (e > x)
		{
			result.push_back(e);
		}
	}
	return result;
}

// Given a range it will rearrange the first element and return the partition of that elements final place
iterator partition(iterator begin, iterator end);
// Function that performs most of the sort work
void sort_impl(iterator begin, iterator end);

// Function that sorts a given vector using QuickSort!
std::vector<int> sort(std::vector<int> v)
{	
	sort_impl(v.begin(), v.end());
	return v;
}

void sort_impl(iterator begin, iterator end)
{
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
std::vector<int>::const_iterator binary_search(std::vector<int> const& v, int x)
{
	auto bottom = v.begin(), top = v.end();

	while (bottom != top)
	{
		auto mid = (bottom + (top - bottom) / 2);

		if (x < *mid)
			top = mid;
		else if (x > *mid)
			bottom = ++mid;   // If you don't increment mid here then we get stuck in a forever loop
		else
			return mid;
	}

	return v.end();
}

