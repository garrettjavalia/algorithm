#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {

	int t,  tn = 1;

	std::cin >> t;

	while (t--) {

		std::vector<int> v;
		int temp;
		for (int i = 0; i < 3; i++) {
			std::cin >> temp;
			v.push_back(temp);
		}
		std::sort(v.begin(), v.end());

		std::cout << "Case " << tn++ << ": " << v[1] << "\n";

	}

	return 0;

}