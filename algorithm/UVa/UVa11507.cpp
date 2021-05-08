#include <iostream>
#include <sstream>
#include <string>

int main() {

	int length = 0;

	while (true) {

		std::cin >> length;

		if (length == 0) {
			break;
		}

		std::string direction = "+x";

		for (int i = 1; i < length; i++) {

			std::string cmd;
			std::cin >> cmd;

			if (cmd == "+y") {
				if (direction == "+y") {
					direction = "-x";
				}
				else if (direction == "-y") {
					direction = "+x";
				}
				else if (direction == "+x") {
					direction = "+y";
				}
				else if (direction == "-x") {
					direction = "-y";
				}
			}else if (cmd == "-y") {
				if (direction == "+y") {
					direction = "+x";
				}
				else if (direction == "-y") {
					direction = "-x";
				}
				else if (direction == "+x") {
					direction = "-y";
				}
				else if (direction == "-x") {
					direction = "+y";
				}
			}else if (cmd == "+z") {
				if (direction == "+z") {
					direction = "-x";
				}
				else if (direction == "-z") {
					direction = "+x";
				}
				else if (direction == "+x") {
					direction = "+z";
				}
				else if (direction == "-x") {
					direction = "-z";
				}
			}else if (cmd == "-z") {
				if (direction == "+z") {
					direction = "+x";
				}
				else if (direction == "-z") {
					direction = "-x";
				}
				else if (direction == "+x") {
					direction = "-z";
				}
				else if (direction == "-x") {
					direction = "+z";
				}
			}

		}

		std::cout << direction << std::endl;

	}

	return 0;

}