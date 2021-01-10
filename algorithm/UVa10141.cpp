#include <iostream>
#include <sstream>
#include <string>

int main() {

	int requirements = 0, candidates = 0;
	int caseNum = 1;

	std::string buffer;

	while (true) {

		std::getline(std::cin, buffer);
		std::stringstream ss(buffer);

		ss >> requirements >> candidates;

		if (requirements == 0 && candidates == 0) {
			break;
		}


		//ignore inputs.....name of requirements are actually useless.
		for (int i = 0; i < requirements; i++) {
			std::getline(std::cin, buffer);
		}

		std::string name = "";
		float price = 0.0;
		float compliance = 0.0;
		

		for (int i = 0; i < candidates; i++) {

			std::string tempName;
			float tempPrice = 0.0;
			float tempCompiance = 0.0;

			std::getline(std::cin, tempName);
			std::getline(std::cin, buffer);
			std::stringstream ss(buffer);
			ss >> tempPrice >> tempCompiance;

			for (int j = 0; j < tempCompiance; j++){
				std::getline(std::cin, buffer);
			}

			if (i == 0 || (tempCompiance / requirements > compliance) || ((tempCompiance / requirements >= compliance) && tempPrice < price)) {
				name = tempName;
				price = tempPrice;
				compliance = tempCompiance / requirements;
			}

		}

		if (caseNum != 1) {
			std::cout << "\n";//printing two new lines on here and not printing newline of line 60 caused Wrong Answer. damn i hate this.
		}
		std::cout << "RFP #" << caseNum << "\n" << name << "\n";

		caseNum++;

	}

	return 0;

}