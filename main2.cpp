/*

EXPECTED OUTPUT

Output of begin and end: 1 2 3 4 5
Output of rbegin and rend: 5 4 3 2 1

*/

#include <iostream>
#include "vector.hpp"

//using namespace std;
using namespace ft;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	std::cout << "Output of begin and end: ";
	for (vector<int>::iterator i = g1.begin(); i != g1.end(); ++i)
		std::cout << *i << " ";

	std::cout << "\nOutput of rbegin and rend: ";
	for (vector<int>::reverse_iterator ir = g1.rbegin(); ir != g1.rend(); ++ir)
		std::cout << *ir << " ";

	return 0;
}
