// print_list by idebtor@gmail.com

#include <iostream>
void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}
