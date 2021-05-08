#include <iostream>

int main(void) {

	int t;
	std::cin >> t;

	while (t--) {

		int a, b;
		std::cin >> a >> b;
		std::cout << ((a > b) ? ">" : ((a == b) ? "=" : "<")) << std::endl;

	}

	return 0;

}