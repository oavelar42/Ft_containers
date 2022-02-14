#ifndef STL_HPP
# define STL_HPP

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

#define LET "\033[1m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define OFF "\033[0m"

void print_title(std::string title, std::string subtitle);
void print_header(std::string container_name);
void test_map();
void test_vector();
void test_stack();

#endif
