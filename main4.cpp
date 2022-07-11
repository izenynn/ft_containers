/*

EXPECTED OUTPUT

Reference operator [g] : g1[2] = 30
at : g1.at(4) = 50
front() : g1.front() = 10
back() : g1.back() = 100
The first element is 10

*/

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

    return 0;
}
