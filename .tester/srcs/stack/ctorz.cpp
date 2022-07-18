#include "common.hpp"

typedef std::vector<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

int main(void) {
	t_stack a;
	printSize("a", a);

	return 0;
}
