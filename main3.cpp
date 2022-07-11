// C++ program to illustrate the
// capacity function in vector
#include <iostream>
#include "vector.hpp"
  
using namespace ft;
  
int main()
{
    vector<int> g1;
  
    for (int i = 1; i <= 5; i++) {
        g1.push_back(i);
	}
  
	std::cout << "Size : " << g1.size();
	std::cout << "\nCapacity : " << g1.capacity();
	std::cout << "\nMax_Size : " << g1.max_size();
  
    // resizes the vector size to 4
    g1.resize(4);
  
    // prints the vector size after resize()
	std::cout << "\nSize : " << g1.size();
  
    // checks if the vector is empty or not
    if (g1.empty() == false)
        std::cout << "\nVector is not empty";
    else
        std::cout << "\nVector is empty";

    return 0;
}
