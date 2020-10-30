#include <iostream>

int main() {

	std::iostream::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int nums[100] = {};
	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	int count = 0;

	long long dp[100][21] = {};

	//첫 수를 만들 수 있는 경우의 수는 1
	dp[0][nums[0]] = 1;
	//마지막 바로 전 숫자까지 대해서 반복
	for (int i = 1; i < n - 1; i++) {
		//이전 숫자까지에 대해서 0~20 사이의 수를 만들 수 있는 경우의 수들
		for (int j = 0; j < 21; j++) {
			//해당 이전 숫자를 만들 수 있다
			if (dp[i - 1][j]) {
				if (j + nums[i] <= 20) {
					dp[i][j + nums[i]] += dp[i - 1][j];
				}
				if (j - nums[i] >= 0) {
					dp[i][j - nums[i]] += dp[i - 1][j];
				}
			}
		}
	}

	/*
	for (int j = 0; j < 21; j++) {
		std::cout << "\t" << j << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 100; i++) {

		for (int j = 0; j < 21; j++) {
			std::cout << "\t" <<dp[i][j] << " ";
		}
		std::cout << std::endl << std::endl;
	}
	*/

	std::cout << dp[n - 2][nums[n - 1]];

	return 0;

}