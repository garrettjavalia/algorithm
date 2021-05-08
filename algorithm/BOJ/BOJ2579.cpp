#include <iostream>

int main() {

	int steps[301] = { 0 };
	int dp[301][2] = { 0 };

	int stepcount = 0;
	std::cin >> stepcount;
	for (int i = 1; i <= stepcount; i++) {

		std::cin >> steps[i];

	}

	dp[1][0] = steps[1];
	for (int i = 2; i <= stepcount; i++) {

		//1계단 연속으로 오른 상태인 것은 2계단 전의 것 중 많은 것을 취하고, 거기에 자신의 수를 더한다.
		if (dp[i - 2][0] > dp[i - 2][1]) {

			dp[i][0] = dp[i - 2][0] + steps[i];

		}
		else {
			dp[i][0] = dp[i - 2][1] + steps[i];
		}

		//2계단 연속 오른 상태인 것은 1계단 전의 것 중 1계단 연속 오른 것만을 취할 수 있다.
		dp[i][1] = dp[i - 1][0] + steps[i];

	}
	/*
	for (int i = 1; i <= stepcount; i++) {
		std::cout << steps[i] << " ";

	}
	std::cout << std::endl;
	
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= stepcount; j++) {
			std::cout << dp[j][i] << " ";
		}
		std::cout << std::endl;
	}
	*/

	std::cout << (dp[stepcount][0] > dp[stepcount][1] ? dp[stepcount][0] : dp[stepcount][1]) << std::endl;


	return 0;

}