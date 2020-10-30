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

		//지금 줄을 입력받되, 이전 줄의 최고값에 이미 더한 수를 계산한다.
		for (int linenum = 1; linenum <= i; linenum++) {

			//이전줄의 최고값들 중 필요한 것 까지만 위로 올린다.
			dp[0][linenum] = dp[1][linenum];
			int v = 0;
			std::cin >> v;

			//오른쪽 가장자리가 범위를 벗어날 경우는 존재하지 않는다.
			dp[1][linenum] = std::max(dp[0][linenum - 1], dp[0][linenum]) + v;
			dpmax = (dpmax < dp[1][linenum]) ? dp[1][linenum] : dpmax;

		}

	}

	std::cout << dpmax << std::endl;

	return 0;

}