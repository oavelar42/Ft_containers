#include "std.hpp"

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

void contructors()
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

	print_title("COPY CONSTRUCTOR WITH STRING", "std::vector");
	std::vector<std::string> cop(5, "yo");
	std::vector<std::string> copy(cop);
	std::vector<std::string>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
		std::cout << LET << *copyIt++ << ' ';
	std::cout << std::endl;

	print_title("ASSIGNATION OPERATOR", "std::vector");
	std::vector<int> std_vector_assignation;
	std_vector_assignation = std_vector_copy;
	print_size(std_vector_assignation, "std_vector_assignation");
	print_vector(std_vector_assignation, "std_vector_assignation");

	print_title("ASSIGNATION OPERATOR WITH STRING", "std::vector");
	std::vector<std::string> o1(5, "cy");
	std::vector<std::string> o3 = o1;
	std::vector<std::string>::iterator oit = o3.begin();

	while (oit != o3.end())
		std::cout << LET << *oit++ << ' ';
	std::cout << std::endl;
	std::cout << std::endl;
}

void iterators()
{
	print_title("ITERATOR TEST", "std::vector");

	std::vector<char> std_vector;

	for (int i = 65; i < 80; i++)
		std_vector.push_back(i);
	//std::vector<char>::iterator it = std_vector.begin();
	

	std::cout << "std_vector (ITERATOR): ";
	for (std::vector<char>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "std_vector (CONST_ITERATOR): ";
	for (std::vector<char>::const_iterator it = std_vector.begin(); it != std_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "std_vector (REVERSE_ITERATOR): ";
	for (std::vector<char>::reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;
	std::cout << std::endl;
	
	std::cout << "std_vector (CONST_REVERSE_ITERATOR): ";
	for (std::vector<char>::const_reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n";
}

void capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	
	std::vector<int> tab(5, 10);
	print_title("BEFORE RESIZE", "std::vector");
	std::cout << LET << "size : " << tab.size() << std::endl;

	tab.resize(10, 10);
	print_title("AFTER RESIZE", "(10)");
	std::cout << LET << "size : " << tab.size() << std::endl;

	print_title("VECTOR EMPTY()", "std::vector");
	print_size(tab, "std_vector");

	print_title("VECTOR RESERVE", "(20)");
	tab.reserve(20);
	std::cout << LET << "size : " << tab.size() 
		<< LET << ", capacity : " << tab.capacity() << std::endl;
	std::cout << std::endl;
}

void	access()
{
	print_title("ELEMENT ACCESS" , "std::vector");
	std::vector<int> tab;
	for (int i = 65; i < 80; i++)
		tab.push_back(i);
	print_vector(tab, "std_vector");

	print_title("VECTOR AT()" , "std::vector");
	std::cout << LET << "tab at 5 : " << tab.at(5) << std::endl;

	print_title("VECTOR FRONT()", "std::vector");
	std::cout << LET << "front : " << tab.front() << std::endl;

	print_title("VECTOR BACK()", "std::vector");
	std::cout << LET << "back : " << tab.back() << std::endl;

	std::cout << std::endl;
}

void	modifiers()
{
	print_title("MODIFIERS", "std::vector");

	std::vector<int> tab(3, 2);
	
	print_vector(tab, "std_vector(tab)");
	
	print_title("VECTOR PUSH_BACK", "(5)");
	tab.push_back(5);
	print_vector(tab, "std_vector(tab)");

	print_title("VECTOR POP_BACK()", "Remove 5");
	tab.pop_back();
	print_vector(tab, "std_vector(tab)");

	print_title("VECTOR ASSIGN(n, val)", "assign two 3 : ");
	tab.assign(2, 3);
	print_vector(tab, "std_vector(tab)");

	print_title("VECTOR INSERT", "(insert 1");
	tab.insert(tab.begin(), 1);
	print_vector(tab, "std_vector(tab)");

	print_title("VECTOR ERASE(position)", "erase 1");
	tab.erase(tab.begin());
	print_vector(tab, "std_vector(tab)");

	print_title("VECTOR CLEAR()", "All");
	tab.clear();
	print_size(tab, "std_vector after clear()");

	std::vector<int> a(3, 10);
	std::vector<int> b(5, 7);
	
	print_title("BEFORE SWAP", "std::vector");
	std::cout << LET << "a : ";
	print_vector(a, "std_vector(a)");
	std::cout  << "b : ";
	print_vector(b, "std_vector(b)");
	print_title("AFTER SWAP", "std::vector");
	a.swap(b);
	std::cout << LET << "a : ";
	print_vector(a, "std_vector(a)");
	std::cout << "b : ";
	print_vector(b, "std_vector(b)");

	std::cout << std::endl;
}

void operators()
{
	print_title("OPERATIONAL OPERATOR", "std::vector");

	std::vector<int> vect (3,100);
	std::vector<int> copy(vect);
	
	std::cout << "0#  == " << (vect == copy) << std::endl;
	std::cout << "1#  != " << (vect != copy) << std::endl;
	std::cout << "2#  <  " << (vect < copy) << std::endl;
	std::cout << "3#  <= " << (vect <= copy) << std::endl;
	std::cout << "4#  >  " << (vect > copy) << std::endl;
	std::cout << "5#  >= " << (vect >= copy) << std::endl;
	std::cout << "6#  [] " << vect[0] << std::endl;
	
	print_title("OPERATIONAL OPERATOR", "different operations");
	copy.erase(copy.begin());
	std::cout << "7#  == " << (vect == copy) << std::endl;
	std::cout << "8#  != " << (vect != copy) << std::endl;
	std::cout << "9#  <  " << (vect < copy) << std::endl;
	std::cout << "10# <= " << (vect <= copy) << std::endl;
	std::cout << "11# >  " << (vect > copy) << std::endl;
	std::cout << "12# >= " << (vect >= copy) << std::endl;
	std::cout << "13# [] " << vect[0] << std::endl;
}

void test_vector()
{
	int start = clock();
	
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();

	std::cout << "\n";
	int end = clock();
	std::cout << RED "Execution time (vector): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "\n";
}