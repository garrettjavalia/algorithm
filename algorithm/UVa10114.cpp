#include <iostream>
#include <algorithm>
#include <vector>

int main() {

	while (true) {

		int months, depreciationCount;
		double downPayment, loan;
		std::cin >> months >> downPayment >> loan >> depreciationCount;

		if (months >= 0) {
			std::vector<int> depreciationMonth;
			std::vector<double> depreciationValue;
			std::vector<double> calculatedDepreciation;

			int ti;
			double tf;

			for (int i = 0; i < depreciationCount; i++) {
				std::cin >> ti >> tf;
				depreciationMonth.push_back(ti);
				depreciationValue.push_back(tf);
			}

			for (int i = 0; i < depreciationCount; i++) {
				for (int j = depreciationMonth[i]; j <= months && (i == depreciationCount - 1 ? true : j < depreciationMonth[i + 1]); j++) {
					calculatedDepreciation.push_back(depreciationValue[i]);
				}
			}

			double totalCarPrice = downPayment + loan;
			double originalPrice = totalCarPrice;
			double rePayPerMonth = months == 0 ? loan : loan / months;

			bool handled = false;
			for (int i = 0; i <= months; i++) {

				if (i != 0) {
					loan -= rePayPerMonth;
				}

				totalCarPrice *= (1.0 - calculatedDepreciation[i]);

				if (totalCarPrice >= loan) {
					std::cout << i << (i != 1 ? " months" : " month") << std::endl;
					handled = true;
					break;
				}

			}

		}
		else {
			break;
		}

	}

	return 0;

}