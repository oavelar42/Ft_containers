#include "std.hpp"

void test_stack()
{
	//int start = clock();

	std::cout << std::endl;
	std::cout << YELLOW "DEFAULT CONSTRUCTOR:" OFF << " stack" << std::endl;
	std::stack<int> stack;

	std::cout << std::endl;
	std::cout << YELLOW "SIZE:" << OFF << std::endl;
	std::cout << "stack size: " << stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW "EMPTY:" << OFF << std::endl;
	std::cout << "stack empty() (1: true 0: false): " << stack.empty() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW "PUSH:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
	stack.push(42 * i);
	std::cout << YELLOW "TOP:" << OFF << stack.top() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW "SIZE:" << OFF << std::endl;
	std::cout << "stack size: " << stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW "EMPTY:" << OFF << std::endl;
	std::cout << "stack empty() (1: true 0: false): " << stack.empty() << std::endl;
(
	std::cout) << std::endl;

	std::cout << YELLOW "COPY CONSTRUCTOR:" << OFF << std::endl;
	std::stack<int> stack_copy(stack);

	std::cout << std::endl;

	std::cout << YELLOW "POP:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
	std::cout << YELLOW "TOP:" << OFF << stack.top() << std::endl;
	stack.pop();
	}

	std::cout << std::endl;

	std::cout <<YELLOW "ASSIGNATION OPERATOR:" << OFF << std::endl;
	stack_copy = stack;

	std::cout << std::endl;

	std::cout << YELLOW "OPERATIONAL OPERATOR:" << OFF << std::endl;
	std::cout << "(stack == stack_copy) : " << (stack == stack_copy) << std::endl;
	std::cout << "(stack != stack_copy) : " << (stack != stack_copy) << std::endl;
	std::cout << "(stack < stack_copy) : " << (stack < stack_copy) << std::endl;
	std::cout << "(stack <= stack_copy) : " << (stack <= stack_copy) << std::endl;
	std::cout << "(stack > stack_copy) : " << (stack > stack_copy) << std::endl;
	std::cout << "(stack >= stack_copy) : " << (stack >= stack_copy) << std::endl;

	std::cout << std::endl;
	//int end = clock();
	//std::cout << "Execution time (stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;

	std::cout << std::endl;
}