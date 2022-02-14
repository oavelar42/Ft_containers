#include "std.hpp"

void test_stack()
{
	int start = clock();

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
	int end = clock();
	std::cout << "Execution time (stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;
}