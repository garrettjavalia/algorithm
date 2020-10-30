#include <iostream>
#include <algorithm>

short GCDMemo[10001][101] = { 0 };

short getGCD(int n, int m) {
	return m ? getGCD(m, n % m) : n;
}

short getGCDMemo(int n, int m){
	
	if (!GCDMemo[n][m]) {
		GCDMemo[n][m] = getGCD(n, m);
	}

	return GCDMemo[n][m];

}

int dp[101][10001] = { 0 };

//n, m 크기로 얻을 수 있는 최소 갯수 정사각형을 돌려준다.
int solve(int n, int m) {

	//std::cout << "solve 호출됌" << n << " " << m << std::endl;

	//n에 무조건 작은 쪽을 넣어준다.
	if (n > m) {
		std::swap(n, m);
	}

	if (dp[n][m]) {
		//std::cout << "solve " << n << " " << m << "은 " << dp[n][m] << "으로 계산됌." << std::endl;
		return dp[n][m];
	}
	else {

		//자신의 n이 1이면 m을 돌려주면 된다. 저장하고 돌려주자.
		if (n == 1) {
			//std::cout << "solve " << n << " " << m << "은 " << m << "으로 계산됌." << std::endl;
			return dp[n][m] = m;
		}

		//자신의 n과 m이 최대공약수로 나눠질 수 있다면 그렇게 나눠서 나온 작은 값에 계산을 맡긴다.
		short gcd = getGCDMemo(n, m);
		if (gcd != 1) {
			short dn = n / gcd, dm = m / gcd;
			dp[n][m] = solve(dn, dm);
			//std::cout << "solve " << n << " " << m << "은 " << dp[n][m] << "으로 계산됌." << std::endl;
			return dp[n][m];
		}

		int minResult = n * m;//this is fucked up answer.
		//자르는 것은 반절까지만 자르면 모든 것을 다 구한 셈이다.
		//자신의 n을 한칸씩 잘라가면서 모든 경우의 수를 구한다.
		for (int i = 1; i <= n / 2; i++) {
			minResult = std::min(minResult, solve(i, m) + solve(n - i, m));
		}

		//자신의 m을 한 칸씩 잘라가면서 모든 경우의 수를 구한다.
		for (int i = 1; i <= m / 2; i++) {
			minResult = std::min(minResult, solve(n, i) + solve(n, m - i));
		}

		//std::cout << "solve " << n << " " << m << "은 " << minResult << "으로 계산됌." << std::endl;
		return dp[n][m] = minResult;

	}

}

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;

	std::cin >> n >> m;

	//가능하다면 문제의 크기를 먼저 줄여놓고 시작한다.
	short gcd = getGCDMemo(n, m);
	n /= gcd;
	m /= gcd;

	//문제의 크기를 줄였으니 계산을 시작한다.
	std::cout << solve(n, m) << std::endl;

}