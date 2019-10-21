#include <iostream>
#include <string>
#include "vector_algos.hpp"

void reference_practice()
{
	int x = 5;   // Basic int variable
	int& y = x;  // y is a reference and is bound to x (an alias)

	std::cout << "int x = 5;\n";
	std::cout << "int y& = x;\n";
	std::cout << "> x == " << x << "\n";
	std::cout << "> y == " << y << "\n";

	y = 2;   // Here both x and y should become 2

	std::cout << "\ny = 2;\n";
	std::cout << "> x == " << x << std::endl;
	std::cout << "> y == " << y << std::endl;

	x = 3;   // Now both x and y should become 3

	std::cout << "\nx = 3;\n";
	std::cout << "> x == " << x << std::endl;
	std::cout << "> y == " << y << std::endl;

	// Auto assumes your variable shouldn't be a reference unless you explicitly tell it to be
	auto z1 = y;
	auto& z2 = y;

	x = 8;

	std::cout << "\nauto z1 = y;\n";
	std::cout << "auto& z2 = y;\n";
	std::cout << "x = 8;\n";
	std::cout << ">x == " << x << std::endl;
	std::cout << ">y == " << y << std::endl;
	std::cout << ">z1 == " << z1 << std::endl;
	std::cout << ">z2 == " << z2 << std::endl;

	// We can declare functions inside other functions but cannot define them. We can define functions inside classes though

	void takes_a_reference(int& i);
	std::cout << std::endl;

	std::cout << "> x == " << x << std::endl;
	std::cout << "takes_a_reference(x);\n";
	takes_a_reference(x);
	std::cout << "> x == " << x << std::endl;

	const int& c = x;
	std::cout << std::endl;
	std::cout << "const int& c = x;\n";

	// We can't change x via c, but we can change c via x
	std::cout << ">c == " << c << std::endl;
	x = 5;
	std::cout << "\nx = 5;\n";
	std::cout << "> c == " << c << std::endl;

	void takes_a_reference_to_const(const int& i);

	std::cout << std::endl;
	std::cout << "> x == " << x << std::endl;
	std::cout << "takes_a_reference_to_const(x);\n";
	takes_a_reference_to_const(x);
	std::cout << "> x == " << x << std::endl;

	std::cout << std::endl;
	void print(const std::string & str);
	std::cout << "print(\"I'm a string literal but can be converted to a string!\");\n"; // A "string literal" is not a string  but can be converted
	print("I'm a string literal but can be converted to a string!");

	// The following is not intended?
	std::cout << std::endl;
	std::cout << "const double& d = x;\n";
	const double& d = x;  // x is an int
	std::cout << "> x == " << x << std::endl;
	std::cout << "> d == " << d << std::endl;
	x = 15;
	std::cout << "x = 15;\n";
	std::cout << "> x == " << x << std::endl;
	std::cout << "> d == " << d << std::endl;  // d does not reference to x as x is an int. Instead d references to a temporary double

}

void takes_a_reference(int& i)
{
	std::cout << "> i == " << i << "\n";
	i = 7;
	std::cout << "i = 7;\n";
}

void takes_a_reference_to_const(const int& i)
{
	std::cout << "i == " << i << std::endl;
	std::cout << "Cannot change i since it is const. Therefore cannot change the value!\n";
}

void print(std::string const& str)
{
	std::cout << str << std::endl;
}

int main()
{
	reference_practice();
	std::cout << std::endl;

	auto v = sort(read_int_vector());

	std::cout << "You entered: ";
	for (auto e : v)
	{
		std::cout << " " << e; 
	}
	std::cout << std::endl;

	for (int i = 0; i < 50; i += 5)
	{
		auto it = binary_search(v, i);
		if (it == v.end())
		{
			std::cout << i << " was not amongst the numbers you entered.\n";
		}
		else
		{
			std::cout << "You entered " << (it - v.begin()) << " numbers less than " << i << std::endl;
		}
	}

	std::cout << "Average: " << average(v) << std::endl;
	std::cout << "Sum: " << sum(v) << std::endl;

	std::cout << "Elements greater than 5:";
	for (auto e : filter_greater_than(v, 5))
	{
		std::cout << " " << e;
	}
	std::cout << std::endl;

	return 0;
}