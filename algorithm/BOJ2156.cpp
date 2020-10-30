#include <iostream>
#include <algorithm>

int main() {

	std::iostream::sync_with_stdio(false);

	//이 문제에서 최적해는 다음과 같이 구해진다.
	//1. 언제나 최대값만을 구해서 기록한다.
	//2. 언제나 이전 값들을 참고해서 계산하므로 최대값을 기록한다.
	//	현재 위치 -2의 최대값에서 가져오는 방법
	//	현재 위치 -3의 최대값과 현재위치 -1의 값을 더해서 가져오는 방법
	//이렇게 최적해를 구한다.

	short steps[10001] = { 0 };
	int dp[10001] = { 0 };

	int stepcount = 0;
	std::cin >> stepcount;
	for (int i = 1; i <= stepcount; i++) {

		std::cin >> steps[i];

	}

	//첫 계단을 밟는 경우는 1가지 경우 뿐이다.
	dp[1] = steps[1];
	//2번째 계단은 밟는 경우가 2가지이나 계단 점수가 양수 뿐이므로 최대값은 1가지 경우 뿐이다.
	dp[2] = steps[1] + steps[2];
	//3번째 계단은 밟는 경우가 2가지이고, 최대값은 비교해봐야 알 수 있다.
	dp[3] = std::max(steps[2] + steps[3], steps[1] + steps[3]);
	dp[3] = std::max(dp[2], dp[3]);

	for (int i = 4; i <= stepcount; i++) {
		dp[i] = std::max(dp[i - 2] + steps[i], dp[i - 3] + steps[i - 1] + steps[i]);
		dp[i] = std::max(dp[i - 1], dp[i]);
	}

	std::cout << dp[stepcount] << std::endl;

	return 0;

}