#include "Banana.h"
#include <iostream>

int main() {
	Banana<int> list;

	list.AddToTail(1);
	list.AddToTail(2);
	list.AddToTail(3);
	list.Show();

	list.InsertAtPosition(0, 0);
	list.Show();

	list.InsertAtPosition(4, 3);
	list.Show();

	list.DeleteAtPosition(2);
	list.Show();

	int position = list.Search(4);
	std::cout << "Position of 4: " << position << std::endl;

	int replaceCount = list.Replace(4, 5);
	std::cout << "Position" << replaceCount << "element" << std::endl;
	list.Show();

	list.Reverse();
	list.Show();

	list.DeleteAll();
	list.Show();

	return 0;
}