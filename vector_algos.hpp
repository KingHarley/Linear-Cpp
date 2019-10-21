
// Check whether this header has been included already
#ifndef CHAPTER_10_VECTOR_ALGOS_HPP
#define CHAPTER_10_VECTOR_ALGOS_HPP    //Define the macro prevent inclusion of the header a second time.

#include <vector>
#include <iostream>

// Function that reads integer input from the user until they press Ctrl+Z. Returns a vector with the ints
std::vector<int> read_int_vector(std::istream& stream = std::cin); //This sets the default value of the argument for a reference to a stream as std::cin

// Function that sums the values of a vector v. Here we pass in a reference to that vector so don't end up copying it
int sum(std::vector<int> const& v);

// Function that returns the values greater than x inside vector v
std::vector<int> filter_greater_than(std::vector<int> const& v, int x);

// Function that averages the values of vector v
inline int average(std::vector<int> const& v)
{
	if (v.empty())
	{
		return 0; 
	}

	return sum(v) / int(v.size());
}

// Function that sorts a vector
std::vector<int> sort(std::vector<int> v);

// Function that checks if an int is in a vector
std::vector<int>::const_iterator binary_search(std::vector<int> const& v, int x);

#endif