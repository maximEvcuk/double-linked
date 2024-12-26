#include "Turn-FILO.h"
#include<iostream>

int main() {
	
	Turn<int> queue1;
	Turn<int> queue2;

	// Список 1
	for (int i = 0; i < 10; ++i){
		queue1.push(i);
	}

	// Список 2
	for (int i = 5; i < 15; ++i) {
		queue2.push(i);
	}
	
	Banana<int>  clonedQueue = queue1.clone();
	std::cout << "Cloned Queue: ";
	clonedQueue.Show();

	Turn<int> combinedQueue = queue1 + queue2;
	std::cout << "Combined Queue: ";
	combinedQueue.Show();

	Turn<int>  commonQueue = queue1 * queue2;
	std::cout << "Common Queue: ";
	commonQueue.Show();


	return 0;
}