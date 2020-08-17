#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = 0;

	std::cin >> n;

	int digits = 0;
	int temp = n;
	while (temp > 0) {
		digits++;
		temp = temp / 10;
	}

	for (int i = n - digits * 9; i < n; i++) {
		int sum = i;
		int temp = i;
		while (temp > 0) {
			sum += temp % 10;
			temp = temp / 10;
		}
		if (sum == n) {
			std::cout << i;
			return 0;
		}
	}
	std::cout << 0;
	return 0;

}