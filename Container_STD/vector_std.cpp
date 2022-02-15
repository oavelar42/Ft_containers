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
	std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << std::endl;
	std::cout << name << " empty() (1: true 0: false): " << vector.empty() << std::endl;
}

void contructors()
{
	print_title("DEFAULT CONSTRUCTOR", "vector");
	std::vector<int> vector;
	print_size(vector, "vector");

	print_title("FILL CONSTRUCTOR", "vector");
	std::vector<int> vector_fill(10, 42);
	print_size(vector_fill, "vector_fill");
	print_vector(vector_fill, "vector_fill");

	print_title("RANGE CONSTRUCTOR", "vector");
	std::vector<int> vector_range(vector_fill.begin(), vector_fill.end());
	print_size(vector_range, "vector_range");
	print_vector(vector_range, "vector_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "vector");
	std::vector<int> vector_copy(vector_range);
	print_size(vector_copy, "vector_copy");
	print_vector(vector_copy, "vector_copy");

	print_title("COPY CONSTRUCTOR WITH STRING", "vector");
	std::vector<std::string> cop(5, "yo");
	std::vector<std::string> copy(cop);
	std::vector<std::string>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
		std::cout << LET << *copyIt++ << ' ';
	std::cout << std::endl;

	print_title("ASSIGNATION OPERATOR", "vector");
	std::vector<int> vector_assignation;
	vector_assignation = vector_copy;
	print_size(vector_assignation, "vector_assignation");
	print_vector(vector_assignation, "vector_assignation");

	print_title("ASSIGNATION OPERATOR WITH STRING", "vector");
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
	print_title("ITERATOR TEST", "vector");

	std::vector<char> vector;

	for (int i = 65; i < 80; i++)
		vector.push_back(i);

	std::cout << "vector (ITERATOR): ";
	for (std::vector<char>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "vector (CONST_ITERATOR): ";
	for (std::vector<char>::const_iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "vector (REVERSE_ITERATOR): ";
	for (std::vector<char>::reverse_iterator rit = vector.rbegin(); rit != vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;
	std::cout << std::endl;
	
	std::cout << "vector (CONST_REVERSE_ITERATOR): ";
	for (std::vector<char>::const_reverse_iterator rit = vector.rbegin(); rit != vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n";
}

void capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	
	std::vector<int> tab(5, 10);
	print_title("BEFORE RESIZE", "vector");
	std::cout << LET << "size : " << tab.size() << std::endl;

	tab.resize(10, 10);
	print_title("AFTER RESIZE", "(10)");
	std::cout << LET << "size : " << tab.size() << std::endl;

	print_title("VECTOR EMPTY()", "vector");
	print_size(tab, "vector");

	print_title("VECTOR RESERVE", "(20)");
	tab.reserve(20);
	std::cout << LET << "size : " << tab.size() 
		<< LET << ", capacity : " << tab.capacity() << std::endl;
	std::cout << std::endl;
}

void	access()
{
	print_title("ELEMENT ACCESS" , "vector");
	std::vector<int> tab;
	for (int i = 65; i < 80; i++)
		tab.push_back(i);
	print_vector(tab, "vector");

	print_title("VECTOR AT()" , "vector");
	std::cout << LET << "tab at 5 : " << tab.at(5) << std::endl;

	print_title("VECTOR FRONT()", "vector");
	std::cout << LET << "front : " << tab.front() << std::endl;

	print_title("VECTOR BACK()", "vector");
	std::cout << LET << "back : " << tab.back() << std::endl;

	std::cout << std::endl;
}

void	modifiers()
{
	print_title("MODIFIERS", "vector");

	std::vector<int> tab(3, 2);
	
	print_vector(tab, "vector(tab)");
	
	print_title("VECTOR PUSH_BACK", "(5)");
	tab.push_back(5);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR POP_BACK()", "Remove 5");
	tab.pop_back();
	print_vector(tab, "vector(tab)");

	print_title("VECTOR ASSIGN(n, val)", "assign two 3 : ");
	tab.assign(2, 3);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR INSERT", "(insert 1");
	tab.insert(tab.begin(), 1);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR ERASE(position)", "erase 1");
	tab.erase(tab.begin());
	print_vector(tab, "vector(tab)");

	print_title("VECTOR CLEAR()", "All");
	tab.clear();
	print_size(tab, "vector after clear()");

	std::vector<int> a(3, 10);
	std::vector<int> b(5, 7);
	
	print_title("BEFORE SWAP", "vector");
	std::cout << LET << "a : ";
	print_vector(a, "vector(a)");
	std::cout  << "b : ";
	print_vector(b, "vector(b)");
	print_title("AFTER SWAP", "vector");
	a.swap(b);
	std::cout << LET << "a : ";
	print_vector(a, "vector(a)");
	std::cout << "b : ";
	print_vector(b, "vector(b)");

	std::cout << std::endl;
}

void operators()
{
	print_title("OPERATIONAL OPERATOR", "vector");

	std::vector<int> vect (100);
	std::vector<int> copy(50);
	
	std::cout << "0-> (vect == copy) |==| " << (vect == copy) << std::endl;
	std::cout << "1-> (vect != copy) |!=| " << (vect != copy) << std::endl;
	std::cout << "2-> (vect < copy)  |< | " << (vect < copy) << std::endl;
	std::cout << "3-> (vect <= copy) |<=| " << (vect <= copy) << std::endl;
	std::cout << "4-> (vect > copy)  | >| " << (vect > copy) << std::endl;
	std::cout << "5-> (vect >= copy) |>=| " << (vect >= copy) << std::endl;
	std::cout << "6->  vect[0] 	   |[]| " << vect[0] << std::endl;
	
	print_title("OPERATIONAL OPERATOR", "different operations");
	std::vector<int> str(50);
	std::cout << "7-> (str == copy)  |==| " << (str == copy) << std::endl;
	std::cout << "8-> (str != copy)  |!=| " << (str != copy) << std::endl;
	std::cout << "9-> (str < copy)   |< | " << (str < copy) << std::endl;
	std::cout << "10-> (str <= copy) |<=| "  << (str <= copy) << std::endl;
	std::cout << "11-> (str > copy)  | >| " << (str > copy) << std::endl;
	std::cout << "12-> (str >= copy) |>=| " << (str >= copy) << std::endl;
	std::cout << "13->  str[0]	   |[]| " << str[0] << std::endl;
}

void test_vector()
{
	//int start = clock();
	
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();

	std::cout << "\n";
	//int end = clock();
	//std::cout << RED "Execution time (vector): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "\n";
}