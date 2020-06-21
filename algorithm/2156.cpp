#include <iostream>
#include <algorithm>

int main() {

	std::iostream::sync_with_stdio(false);

	//�� �������� �����ش� ������ ���� ��������.
	//1. ������ �ִ밪���� ���ؼ� ����Ѵ�.
	//2. ������ ���� ������ �����ؼ� ����ϹǷ� �ִ밪�� ����Ѵ�.
	//	���� ��ġ -2�� �ִ밪���� �������� ���
	//	���� ��ġ -3�� �ִ밪�� ������ġ -1�� ���� ���ؼ� �������� ���
	//�̷��� �����ظ� ���Ѵ�.

	short steps[10001] = { 0 };
	int dp[10001] = { 0 };

	int stepcount = 0;
	std::cin >> stepcount;
	for (int i = 1; i <= stepcount; i++) {

		std::cin >> steps[i];

	}

	//ù ����� ��� ���� 1���� ��� ���̴�.
	dp[1] = steps[1];
	//2��° ����� ��� ��찡 2�����̳� ��� ������ ��� ���̹Ƿ� �ִ밪�� 1���� ��� ���̴�.
	dp[2] = steps[1] + steps[2];
	//3��° ����� ��� ��찡 2�����̰�, �ִ밪�� ���غ��� �� �� �ִ�.
	dp[3] = std::max(steps[2] + steps[3], steps[1] + steps[3]);
	dp[3] = std::max(dp[2], dp[3]);

	for (int i = 4; i <= stepcount; i++) {
		dp[i] = std::max(dp[i - 2] + steps[i], dp[i - 3] + steps[i - 1] + steps[i]);
		dp[i] = std::max(dp[i - 1], dp[i]);
	}

	std::cout << dp[stepcount] << std::endl;

	return 0;

}