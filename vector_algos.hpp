
// Check whether this header has been included already
#ifndef CHAPTER_08_VECTOR_ALGOS_HPP
#define CHAPTER_08_VECTOR_ALGOS_HPP    //Define the macro prevent inclusion of the header a second time.

#include <vector>


// Function that reads integer input from the user until they press Ctrl+Z. Returns a vector with the ints
std::vector<int> read_int_vector();

// Returns an int corresponding to the sum of elements in a vector 
int sum(std::vector<int> v);

// Returns a vector containing the ints which are greater than x inside vector v
std::vector<int> filter_greater_than(std::vector<int> v, int x);

// Returns the average of the elements of a vector
inline int average(std::vector<int> v)
{
	if (v.empty())
		return 0;
	int size = v.size();
	return sum(v) / size;
}


#endif