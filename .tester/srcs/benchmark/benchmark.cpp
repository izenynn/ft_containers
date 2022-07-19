/*
 * bencharmk for ft_containers
 *
 * this bencharmk consist of three tests for each container
 *     1. insert lots of elements
 *     2. use copy constructor to create a copy, and then destroy de copy
 *     3. erase all inserted elements
 * there is an extra test for the map, find the inserted element :)
 *
 */

#include <iostream>
#include <ctime>

#define FT
#include "../tester.hpp"
#include <stack>
#include <vector>
#include <map>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer {
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#define value_type foo<int>

typedef std::vector<foo<int> > stack_container_type;
#define std_stack std::stack<foo<int>, stack_container_type>
#define ft_stack ft::stack<foo<int>, stack_container_type>

#define std_vector std::vector<foo<int> >
#define ft_vector ft::vector<foo<int> >

#define std_map std::map<foo<int>, bool>
#define ft_map ft::map<foo<int>, bool>

namespace {
	void results(const std::string& name, const std::clock_t& std, const std::clock_t& ft) {
		if (((double)ft / (double)std) < 20.0) {
			std::cout << " ✅ | ft::" << name << " is " << (double)ft / (double)std << " times slower" << std::endl;
		} else {
			std::cout << " ❌ | ft::" << name << " is " << (double)ft / (double)std << " times slower" << std::endl;
		}
	}
}

void benchStack()
{
	std::clock_t	stdTime;
	std::clock_t	ftTime;
	std_stack		std;
	ft_stack		ft;

	stdTime = std::clock();
	for (int i = 0; i < COUNT; ++i) std.push(i);
	{ std_stack tmp(std); }
	for (int i = 0; i < COUNT; ++i) std.pop();
	stdTime = std::clock() - stdTime;

	ftTime = std::clock();
	for (int i = 0; i < COUNT; ++i) ft.push(i);
	{ ft_stack tmp(ft); }
	for (int i = 0; i < COUNT; ++i) ft.pop();
	ftTime = std::clock() - ftTime;

	results("stack", stdTime, ftTime);
}

void benchVector()
{
	std::clock_t	stdTime;
	std::clock_t	ftTime;
	std_vector		std;
	ft_vector		ft;

	stdTime = std::clock();
	for (int i = 0; i < COUNT; ++i) std.push_back(i);
	{ std_vector tmp(std); }
	std.erase(std.begin(), std.end());
	stdTime = std::clock() - stdTime;

	ftTime = std::clock();
	for (int i = 0; i < COUNT; ++i) ft.push_back(i);
	{ ft_vector tmp(ft); }
	ft.erase(ft.begin(), ft.end());
	ftTime = std::clock() - ftTime;

	results("vector", stdTime, ftTime);
}

void benchMap()
{
	std::clock_t	stdTime;
	std::clock_t	ftTime;
	std_map			std;
	ft_map			ft;

	// inserting a growing range, worst-case scenario for an unbalanced map
	// inserting with operator[] takes longer because it tries to find the element first

	stdTime = std::clock();
	for (int i = 0; i < COUNT; ++i) { std[i] = true; std.find(i); }
	{ std_map tmp(std); }
	std.clear();
	stdTime = std::clock() - stdTime;

	ftTime = std::clock();
	for (int i = 0; i < COUNT; ++i) { ft[i] = true; ft.find(i); }
	{ ft_map tmp(ft); }
	ft.clear();
	ftTime = std::clock() - ftTime;

	results("map", stdTime, ftTime);
}

int main(void) {
	benchStack();
	benchVector();
	benchMap();
}
