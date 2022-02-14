# include <set>
# include <iostream>
# include <functional>
# include <string>
# include <iomanip>
# include <memory>
# include <cstddef>
# include <utility>
# include <limits>
# include <stack>
# include <map>
# include <vector>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include "std.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define OFF "\033[0m"

void print_title(std::string title, std::string subtitle)
{
	std::cout << std::endl;
		std::cout << title << ": " << " " << subtitle << "\n" << std::endl;
}

void print_header(std::string container_name)
{
	std::cout << std::endl;
	std::cout << container_name << " TESTS:" << " press enter to continue\n";
}

int main()
{
	print_header("MAP");
	while (std::cin.get() != '\n') {}
	test_map();
	
	print_header("VECTOR");
	while (std::cin.get() != '\n') {}
	test_vector();

	print_header("STACK");
	while (std::cin.get() != '\n') {}
	test_stack();

	return 0;
}