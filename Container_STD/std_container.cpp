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

void print_map(std::map<char, int> map, std::string name)
{
	std::cout << name << ":\n";
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_size(std::map<char, int> map, std::string name)
{
	std::cout << name << " size: " << map.size() << ", max_size: " << map.max_size() << std::endl;
	std::cout << name << " empty() (1: true 0: false): " << map.empty() << std::endl;
	std::cout << std::endl;
} 

void test_map(void)
{
 print_title("CONSTRUCTOR", "std::map");
	std::map<char, int> std_map;
	print_size(std_map, "std_map");

	char c = 'a';
	for (int i = 1; i <= 13; i++, c++)
	{
	std_map[c] = i;
	}
	print_map(std_map, "std_map");
	print_size(std_map, "std_map");

	print_title("RANGE", "std::map");
	std::map<char, int> std_map_range(std_map.begin(), std_map.end());
	print_size(std_map_range, "std_map_range");
	print_map(std_map_range, "std_map_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "std::map");
	std::map<char, int> std_map_copy(std_map_range);
	print_size(std_map_copy, "std_map_copy");
	print_map(std_map_copy, "std_map_copy");


	print_title("ASSIGNATION OPERATOR", "std::map");
	std::map<char, int> std_map_assignation;
	std_map_assignation = std_map_copy;
	print_size(std_map_assignation, "std_map_assignation");
	print_map(std_map_assignation, "std_map_assignation");


	print_title("ITERATORS TESTS", "-");
	std::cout << "std_map (iterator): ";
	for (std::map<char, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << "\n" << std::endl;

	std::cout << "std_map (const_iterator): ";
	for (std::map<char, int>::const_iterator it = std_map.begin(); it != std_map.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << "\n" << std::endl;

	std::cout << "std_map (reverse_iterator): ";
	for (std::map<char, int>::reverse_iterator rit = std_map.rbegin(); rit != std_map.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << "\n" << std::endl;

	std::cout << "std_map (const_reverse_iterator): ";
	for (std::map<char, int>::const_reverse_iterator rit = std_map.rbegin(); rit != std_map.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << "\n" << std::endl;

	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty");
	print_size(std_map, "std_map");

	print_title("MAP INSERT(val)", "-");
	for (int i = 14; i <= 19; i++, c++)
	{
	std_map.insert(std::make_pair(c, i));
	}
	print_map(std_map, "std_map");
	print_size(std_map, "std_map");

	print_title("MAP INSERT(position, val)", "-");
	for (int i = 20; i <= 26; i++, c++)
	{
	std_map.insert(std::make_pair(c, i));
	}
	print_map(std_map, "std_map");
	print_size(std_map, "std_map");

	print_title("MAP INSERT(first, last)", "map -> map_copy");
	print_title("BEFORE INSERT", "-");
	print_map(std_map_copy, "std_map_copy");

	print_title("AFTER INSERT", "-");
	std_map_copy.insert(std_map.begin(), std_map.end());
	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");

	print_title("MAP ERASE(position)", "erasing first half of map_copy");
	std::map<char, int>::iterator std_it_half = std_map_copy.find('n');
	for (std::map<char, int>::iterator it = std_map_copy.begin(); it != std_it_half; it++)
	std_map_copy.erase(it);
	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");

	print_title("MAP ERASE(key)", "erasing another half of map_copy");
	c = 'n';
	for (int i = 0; i < 6; i++, c++)
	{
		std_map_copy.erase(c);
	}

	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");

	print_title("MAP ERASE(first, last)", "finishing the job map_copy");
	std_map_copy.erase(std_map_copy.begin(), std_map_copy.end());
	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");

	print_title("MAP SWAP() (MEMBER)", "swaping map_range and map_copy");
	print_title("BEFORE SWAP", "-");
	print_map(std_map_range, "std_map_range");
	print_map(std_map_copy, "std_map_copy");
	std_map_range.swap(std_map_copy);
	print_title("AFTER SWAP", "-");
	print_map(std_map_range, "std_map_range");
	print_map(std_map_copy, "std_map_copy");

	print_title("MAP CLEAR", "clearing map copy again");
	print_title("BEFORE", "-");
	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");
	std_map_copy.clear();
	print_title("AFTER", "-");
	print_map(std_map_copy, "std_map_copy");
	print_size(std_map_copy, "std_map_copy");

	print_title("MAP FIND(key) const and non_const", "-");
	std::map<char, int>::iterator find_a = std_map.find('a');
	std::map<char, int>::const_iterator find_z = std_map.find('z');
	std::cout << "find('a'): " << (*find_a).first << " = " << (*find_a).second << '\n';
	std::cout << "find('z'): " << (*find_z).first << " = " << (*find_z).second << '\n';

	print_title("MAP COUNT(key)", "-");
	std::cout << 'a';
	if (std_map.count('a') > 0)
	std::cout << " is an element of std_map.\n";
	else
	std::cout << " is not an element of std_map.\n";
	std::cout << '1';
	if (std_map.count('1') > 0)
	std::cout << " is an element of std_map.\n";
	else
	std::cout << " is not an element of std_map.\n";

	print_title("MAP LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g");
	std::map<char,int>::iterator itlow = std_map.lower_bound('b');
	std::map<char,int>::iterator itup = std_map.upper_bound('g');
	std_map.erase(itlow, itup);
	print_map(std_map, "std_map");
	print_size(std_map, "std_map");

	print_title("MAP EQUAL_RANGE", "for h");
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = std_map.equal_range('h');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	print_title("MAP KEY_COMP AND VALUE_COMP", "display everything lower than m");
	std::map<char,int>::key_compare mycomp = std_map.key_comp();

	char highest_key = 'm';
	std::pair<char,int> highest = *std_map.find('m');

	std::map<char,int>::iterator it = std_map.begin();
	while (std_map.value_comp()(*it, highest) \
	&& mycomp((*it).first, highest_key))
	{
	std::cout << it->first << " => " << it->second << '\n';
	it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;
}






void print_vector(std::vector<int> vector, std::string name)
{
	std::cout << name << ": ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print_size(std::vector<int> vector, std::string name)
{
	std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max_size: " << vector.max_size() << std::endl;
	std::cout << name << " empty() (1: true 0:false): " << vector.empty() << std::endl;
}

void test_vector()
{
	print_title("DEFAULT CONSTRUCTOR", "std::vector");
	std::vector<int> std_vector;
	print_size(std_vector, "std_vector");

	print_title("FILL CONSTRUCTOR", "std::vector");
	std::vector<int> std_vector_fill(10, 42);
	print_size(std_vector_fill, "std_vector_fill");
	print_vector(std_vector_fill, "std_vector_fill");

	print_title("RANGE CONSTRUCTOR", "std::vector");
	std::vector<int> std_vector_range(std_vector_fill.begin(), std_vector_fill.end());
	print_size(std_vector_range, "std_vector_range");
	print_vector(std_vector_range, "std_vector_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "std::vector");
	std::vector<int> std_vector_copy(std_vector_range);
	print_size(std_vector_copy, "std_vector_copy");
	print_vector(std_vector_copy, "std_vector_copy");

	print_title("ASSIGNATION OPERATOR", "std::vector");
	std::vector<int> std_vector_assignation;
	std_vector_assignation = std_vector_copy;
	print_size(std_vector_assignation, "std_vector_assignation");
	print_vector(std_vector_assignation, "std_vector_assignation");

	std_vector = std_vector_assignation;

	print_title("ITERATOR TEST", " ");

	std::cout << "std_vector (iterator): ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
	
	std::cout << "std_vector (const_iterator): ";
	for (std::vector<int>::const_iterator it = std_vector.begin(); it != std_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
 
	std::cout << "std_vector (reverse_iterator): ";
	for (std::vector<int>::reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;
 
	std::cout << "std_vector (const_reverse_iterator): ";
	for (std::vector<int>::const_reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;


	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	print_title("BEFORE RESIZE", " ");
	print_size(std_vector, "std_vector");

	print_title("AFTER RESIZE(20)", " ");
	std_vector.resize(20);
	print_size(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");

	print_title("AFTER RESIZE(20, 42)", " ");
	std_vector.resize(40, 42);
	print_size(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");


	print_title("VECTOR EMPTY()", " ");
	print_size(std_vector, "std_vector");

	print_title("VECTOR RESERVE(50)", " ");
	std_vector.reserve(50);
	print_size(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");

	print_title("VECTOR [] OPERATOR", " ");

	std::cout << "std_vector : ";
	for (int i = 0; std_vector[i]; i++)
		std::cout << std_vector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	print_title("VECTOR AT()", " ");

	std::vector<int> vec;
	for (int i = 0; i <= 10; i++)
	{
		vec.push_back(i);
	}
	print_vector(vec, "ft_vector ");

	std::cout << vec.at(2) << std::endl;
	vec.at(2) = 42;
	std::cout << vec.at(2) << std::endl;
	std::cout << std::endl;

	print_title("VECTOR FRONT()", " ");
	std::cout << "std_vector : " << std_vector.front() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR BACK()", " ");
	std::cout << "std_vector : " << std_vector.back() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR ASSIGN(first, last)", " ");
	std_vector.assign(std_vector_fill.begin(), std_vector_fill.end());
	print_size(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");

	print_title("VECTOR ASSIGN(n, val)", " ");
	std_vector.assign(10, 42);
	print_size(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");

	print_title("VECTOR PUSH_BACK(i * 42)", " ");
	for (int i = 0; i <= 10; i++)
	{
	std_vector.push_back(i * 42);
	print_size(std_vector, "std_vector");
	}
	std::cout << std::endl;
	print_vector(std_vector, "std_vector");

	print_title("VECTOR POP_BACK()", " ");
	for (int i = 0; i < 10; i++)
	{
	std_vector.pop_back();
	print_size(std_vector, "std_vector");
	}
	std::cout << std::endl;
	print_vector(std_vector, "std_vector");

	print_title("VECTOR INSERT(position, n, val)", " ");
	std_vector.insert(std_vector.begin(), 5, 420);
	std::cout << "std_vector : ";
	print_vector(std_vector, "std_vector");

	print_title("VECTOR INSERT(position, first, last)", " ");
	std_vector.insert(std_vector.end(), std_vector_fill.begin(), std_vector_fill.end());
	print_vector(std_vector, "std_vector");

	print_title("VECTOR ERASE(position)", "erasing first half");
	for (std::vector<int>::iterator it = (std_vector.begin() + (std_vector.size() / 2)); it != std_vector.end() - 1 ; it++)
	std_vector.erase(it);
	print_vector(std_vector, "std_vector");

	print_title("VECTOR SWAP() (MEMBER)", "swaping vector and range vector");
	print_title("BEFORE SWAP", " ");
	print_vector(std_vector, "std_vector");
	print_vector(std_vector_range, "std_vector_range");
	std_vector.swap(std_vector_range);
	print_title("AFTER SWAP", " ");
	print_vector(std_vector, "std_vector");
	print_vector(std_vector_range, "std_vector_range");

	print_title("VECTOR SWAP() (NON MEMBER)", "swaping vector and range vector again");
	print_title("BEFORE SWAP", " ");
	print_vector(std_vector, "std_vector");
	print_vector(std_vector_range, "std_vector_range");
	std::swap(std_vector, std_vector_range);
	print_title("AFTER SWAP", " ");
	print_vector(std_vector, "std_vector");
	print_vector(std_vector_range, "std_vector_range");


	print_title("OPERATIONAL OPERATOR", "std_vector & std_vector_copy");
	print_vector(std_vector, "std_vector");
	print_vector(std_vector, "std_vector");
	std::cout << "std_vector == std_vector_copy: " << (std_vector == std_vector_copy) << std::endl;
	std::cout << "std_vector != std_vector_copy: " << (std_vector != std_vector_copy) << std::endl;
	std::cout << "std_vector < std_vector_copy: " << (std_vector < std_vector_copy) << std::endl;
	std::cout << "std_vector <= std_vector_copy: " << (std_vector <= std_vector_copy) << std::endl;
	std::cout << "std_vector > std_vector_copy: " << (std_vector > std_vector_copy) << std::endl;
	std::cout << "std_vector >= std_vector_copy: " << (std_vector >= std_vector_copy) << std::endl;
	std::cout << std::endl;

	print_title("OPERATIONAL OPERATOR", "std_vector_assignation & std_vector_copy");
	print_vector(std_vector_assignation, "std_vector_assignation");
	print_vector(std_vector_copy, "std_vector_copy");
	std::cout << "std_vector_assignation == std_vector_copy: " << (std_vector_assignation == std_vector_copy) << std::endl;
	std::cout << "std_vector_assignation != std_vector_copy: " << (std_vector_assignation != std_vector_copy) << std::endl;
	std::cout << "std_vector_assignation < std_vector_copy: " << (std_vector_assignation < std_vector_copy) << std::endl;
	std::cout << "std_vector_assignation <= std_vector_copy: " << (std_vector_assignation <= std_vector_copy) << std::endl;
	std::cout << "std_vector_assignation > std_vector_copy: " << (std_vector_assignation > std_vector_copy) << std::endl;
	std::cout << "std_vector_assignation >= std_vector_copy: " << (std_vector_assignation >= std_vector_copy) << std::endl;

	std::cout << std::endl;

	print_title("VECTOR CLEAR()", " ");
	print_size(std_vector, "std_vector before clear()");
	print_size(std_vector_range, "std_vector_range before clear()");
	std_vector.clear();
	print_size(std_vector, "std_vector after(clear)");
	print_size(std_vector_range, "std_vector_range after(clear)");


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;
}






void test_stack()
{
	std::cout << "DEFAULT CONSTRUCTOR:" << "std::stack"<< std::endl;
	std::stack<int> std_stack;

	std::cout << std::endl;

	std::cout << "SIZE:" << std::endl;
	std::cout << "std_stack size: " << std_stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << "EMPTY:" << std::endl;

	std::cout << "std_stack empty() (1: true 0: false): " << std_stack.empty() << std::endl;

	std::cout << std::endl;

	std::cout << "PUSH:" << std::endl;
	for (int i = 0; i <= 10; i++)
	{
	std_stack.push(42 * i);
	std::cout << "TOP:" << " std = " << std_stack.top() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "SIZE:" << std::endl;
	std::cout << "std_stack size: " << std_stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << "EMPTY:" << std::endl;
	std::cout << "std_stack empty() (1: true 0: false): " << std_stack.empty() << std::endl;
(
	std::cout) << std::endl;

	std::cout << "COPY CONSTRUCTOR:" << std::endl;
	std::stack<int> std_stack_copy(std_stack);

	std::cout << std::endl;

	std::cout << "POP:" << std::endl;
	for (int i = 0; i <= 10; i++)
	{
	std::cout << "TOP:" << " std = " << std_stack.top() << std::endl;
	std_stack.pop();
	}

	std::cout << std::endl;

	std::cout << "ASSIGNATION OPERATOR:" << std::endl;
	std_stack_copy = std_stack;

	std::cout << std::endl;

	std::cout << "OPERATIONAL OPERATOR:" << std::endl;
	std::cout << "(std_stack == std_stack_copy) : " << (std_stack == std_stack_copy) << std::endl;
	std::cout << "(std_stack != std_stack_copy) : " << (std_stack != std_stack_copy) << std::endl;
	std::cout << "(std_stack < std_stack_copy) : " << (std_stack < std_stack_copy) << std::endl;
	std::cout << "(std_stack <= std_stack_copy) : " << (std_stack <= std_stack_copy) << std::endl;
	std::cout << "(std_stack > std_stack_copy) : " << (std_stack > std_stack_copy) << std::endl;
	std::cout << "(std_stack >= std_stack_copy) : " << (std_stack >= std_stack_copy) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;

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