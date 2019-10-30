#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "vector_algos.hpp"

using iterator = std::vector<int>::iterator;

// Don't repeat default value here as it is known from the header
std::vector<int> read_int_vector(std::istream& stream) // Don'
{
	std::vector<int> input;

	while (true)
	{
		std::copy(std::istream_iterator<int>{stream}, std::istream_iterator<int>{}, std::back_inserter(input));

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
	return std::accumulate(v.begin(), v.end(), 0);
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

bool is_positive(int x)
{
	return x > 0;
}

bool all_positive(std::vector<int> const& v)
{
	return std::all_of(v.begin(), v.end(), is_positive);
}

void display_range(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	std::cout << "{ ";
	std::copy(begin, end, std::ostream_iterator<int>(std::cout, " ")); //std::ostream_iterator is an output iterator that writes to a certain stream
	std::cout << " }\n";
}
