#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	while (true) {

		int manCount, budget, hotels, weeks;

		std::cin >> manCount >> budget >> hotels >> weeks;

		//finish code in the end of input.
		if (std::cin.eof()) {
			return 0;
		}


		//-1 means failure.
		int minBudget = -1;

		//search for all hotels
		for (int i = 0; i < hotels; i++) {

			int hotelPrice;
			std::cin >> hotelPrice;

			for (int j = 0; j < weeks; j++) {
				int rooms;
				std::cin >> rooms;
				int tempPrice = hotelPrice * manCount;
				if (rooms >= manCount && (minBudget == -1 || minBudget > tempPrice) && tempPrice <= budget) {
					minBudget = hotelPrice * manCount;
				}
			}

		}

		if (minBudget == -1) {
			std::cout << "stay home\n";
		}
		else {
			std::cout << minBudget << std::endl;
		}

	}

	return 0;

}