#include "Turn-FILO.h"
#include<iostream>

int main() {
	Turn<int> queue;

	for (int i = 0; i < 10; ++i){
		queue.push(i);
	}

	std::cout << "Current size of queue: " << queue.size() << std::endl;

	std::cout << "Top element: " << queue.top() << std::endl;

	queue.pop();
	std::cout << "After popping, top element: " << queue.top() << std::endl;

	queue.clear();
	std::cout << "After clearing, size of queue: " << queue.size() << std::endl;

	return 0;
}