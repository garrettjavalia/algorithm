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

	//ù ���� ���� �� �ִ� ����� ���� 1
	dp[0][nums[0]] = 1;
	//������ �ٷ� �� ���ڱ��� ���ؼ� �ݺ�
	for (int i = 1; i < n - 1; i++) {
		//���� ���ڱ����� ���ؼ� 0~20 ������ ���� ���� �� �ִ� ����� ����
		for (int j = 0; j < 21; j++) {
			//�ش� ���� ���ڸ� ���� �� �ִ�
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