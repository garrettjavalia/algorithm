#include <iostream>

int main(void) {

	int k = 1, n, m, x, y;

	std::cin >> k;

	while(k){

		std::cin >> n >> m;

		while (k--) {

			std::cin >> x >> y;

			if (n < x && m < y) {
				std::cout << "NE\n";
			}
			else if (n < x && m > y) {
				std::cout << "SE\n";
			}
			else if (n > x && m < y) {
				std::cout << "NO\n";
			}
			else if (n > x && m > y) {
				std::cout << "SO\n";
			}
			else {
				std::cout << "divisa\n";
			}

		}

		std::cin >> k;

	}

	return 0;

}