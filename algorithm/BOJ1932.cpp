#include <iostream>
#include <algorithm>

int dp[2][501] = { 0 };

int main(int argc, char* argv[]) {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = 0;
	int dpmax = 0;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {

		//���� ���� �Է¹޵�, ���� ���� �ְ��� �̹� ���� ���� ����Ѵ�.
		for (int linenum = 1; linenum <= i; linenum++) {

			//�������� �ְ��� �� �ʿ��� �� ������ ���� �ø���.
			dp[0][linenum] = dp[1][linenum];
			int v = 0;
			std::cin >> v;

			//������ �����ڸ��� ������ ��� ���� �������� �ʴ´�.
			dp[1][linenum] = std::max(dp[0][linenum - 1], dp[0][linenum]) + v;
			dpmax = (dpmax < dp[1][linenum]) ? dp[1][linenum] : dpmax;

		}

	}

	std::cout << dpmax << std::endl;

	return 0;

}