#include <iostream>
#include <sstream>
#include <string>

int main() {

	int t;
	std::cin >> t;
	std::string buffer;
	std::getline(std::cin, buffer);

	for (int i = 1; i <= t; i++) {

		std::getline(std::cin, buffer);
		std::stringstream ss(buffer);

		int maxNum = -1;

		while (true) {
			int tempSpeed;
			ss >> tempSpeed;
			if (maxNum == -1 || tempSpeed > maxNum) {
				maxNum = tempSpeed;
			}
			if (ss.eof()) {
				break;
			}
		}

		std::cout << "Case " << i << ": " << maxNum << std::endl;

	}

	return 0;

}