#include <iostream>
#include <algorithm>

/*
 * 이 문제는 짧은 쪽 보다 긴 쪽이 3배 이상일 경우 짧은 쪽을 한 변으로 쓰는 큰 네모 두 개를 쓰는 게 나은지
 * 아니면 그 상자들을 쪼개서 더 작은 상자로 쓰는 게 나은지 이미 모두 검사를 해 본다는 사실을 이용해서 풀어낸다.
 * 즉 small * 3 <= large 인 경우 dp의 결과값이 dp[small][large - small] + 1이 될 수 밖에 없다는 것이다.
 * 다른 사람들은 dp의 결과 행렬을 출력해서 규칙을 찾기도 하는 듯 하다.
 * 그것도 좋은 방법이긴 하다.
 * 남의 정답을 보고 풀었다..
*/

//100이 최대이므로 100에 300까지만 구해두면 모든 크기에 대해서 답을 낼 수 있다.
short dp[101][301] = { 0 };

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;

	std::cin >> n >> m;

	//가능하다면 문제의 크기를 먼저 줄여놓고 시작한다.
	//n을 늘 작은 쪽으로 만든다.
	if (n > m) {
		std::swap(n, m);
	}

	//문제의 크기를 줄이려면 줄인 문제에 얼마를 더해야하는지도 구해야한다.
	//small * 3 <= large 인 경우 dp의 결과값이 dp[small][large - small] + 1
	//이 +1이 몇 번 반복되는지를 구하는 것이다.
	short increase = 0;
	while (n * 3 <= m) {
		increase++;
		m -= n;
	}

	//문제의 크기를 줄였으므로 반복문을 돌린다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) {
				//두 변이 같은 크기면 무조건 1
				dp[i][j] = 1;
			}
			else if (i == 1 || j == 1) {
				//두 변 중 하나만 1이어도 반대쪽이 최소
				dp[i][j] = std::max(i, j);
			}
			else if (i * 3 <= j) {
				//dp의 성질로 이미 계산된 것을 가져오는 것이 나을 때
				dp[i][j] = dp[i][j - i] + 1;
			}
			else if (i > j) {
				//주대각선을 기준으로 값이 똑같을 것이므로 가져온다.
				//std::cout << i << " " << j << "주대각선" << std::endl;
				dp[i][j] = dp[j][i];
			}
			else {
				//계산을 줄일 수 없는 경우일 때에는 어쩔 수 없이 모든 것을 다 조합해본다.
				dp[i][j] = i * j; //엉터리 최소값.
				for (int k = 1; k <= i / 2; k++) {
					dp[i][j] = std::min(dp[i][j], short(dp[k][j] + dp[i - k][j]));
				}
				for (int k = 1; k <= j / 2; k++) {
					dp[i][j] = std::min(dp[i][j], short(dp[i][k] + dp[i][j - k]));
				}
			}
		}
	}

	std::cout << dp[n][m] + increase << std::endl;

}