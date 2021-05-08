#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 
*/


int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n = 0, temp = 0;
	std::vector<int> array;
	std::vector<int> lisDP;

	std::cin >> n;

	while (n--) {
		std::cin >> temp;
		array.push_back(temp);
	}

	lisDP.push_back(array[0]);
	for (int i = 1; i < array.size(); i++) {
		if (*(lisDP.rbegin()) < array[i]) {
			lisDP.push_back(array[i]);
		}
		else {
			lisDP[std::lower_bound(lisDP.begin(), lisDP.end(), array[i]) - lisDP.begin()] = array[i];
		}
	}

	std::cout << lisDP.size() << std::endl;

}