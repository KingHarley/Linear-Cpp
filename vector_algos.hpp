
// Check whether this header has been included already
#ifndef CHAPTER_09_VECTOR_ALGOS_HPP
#define CHAPTER_09_VECTOR_ALGOS_HPP    //Define the macro prevent inclusion of the header a second time.

#include <vector>

// Function that reads integer input from the user until they press Ctrl+Z. Returns a vector with the ints
std::vector<int> read_int_vector();

// Function that sorts a vector
std::vector<int> sort(std::vector<int> v);

// Function that checks if an int is in a vector
bool binary_search(std::vector<int> v, int x);

#endif