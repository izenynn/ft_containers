#include <bits/stdc++.h>
#include "vector.hpp"
using namespace ft;
  
int main()
{
    vector<int> g1;
  
    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);
  
	std::cout << "\nReference operator [g] : g1[2] = " << g1[2];
  
	std::cout << "\nat : g1.at(4) = " << g1.at(4);
  
	std::cout << "\nfront() : g1.front() = " << g1.front();
  
	std::cout << "\nback() : g1.back() = " << g1.back();
  
    // pointer to the first element
    //int* pos = g1.data();
  
    //cout << "\nThe first element is " << *pos;
    return 0;
}
