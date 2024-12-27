#include"Array(1).h"
#include<iostream>

int main() {

    Array<int> myArray;

    for (int i = 0; i < 15; ++i)
    {
        myArray.add(i);
    }

    std::cout << "Array element: ";
    for (size_t i = 0; i < myArray.getSize(); ++i){
        std::cout << myArray.getAt(i) << " ";
     }
    std::cout << std::endl;

    myArray.removeAt(5);
    std::cout << "After deleted index 5: ";
    for (size_t i = 0; i < myArray.getSize(); ++i){
        std::cout << myArray.getAt(i) << " ";
    }
    std::cout << std::endl;

    myArray.removeAt(5);
    std::cout << "After deleted.Size : " << myArray.getSize() << std::endl;




    return 0;
}