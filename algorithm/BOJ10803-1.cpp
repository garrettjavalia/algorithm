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

//n, m ũ��� ���� �� �ִ� �ּ� ���� ���簢���� �����ش�.
int solve(int n, int m) {

	//std::cout << "solve ȣ���" << n << " " << m << std::endl;

	//n�� ������ ���� ���� �־��ش�.
	if (n > m) {
		std::swap(n, m);
	}

	if (dp[n][m]) {
		//std::cout << "solve " << n << " " << m << "�� " << dp[n][m] << "���� ����." << std::endl;
		return dp[n][m];
	}
	else {

		//�ڽ��� n�� 1�̸� m�� �����ָ� �ȴ�. �����ϰ� ��������.
		if (n == 1) {
			//std::cout << "solve " << n << " " << m << "�� " << m << "���� ����." << std::endl;
			return dp[n][m] = m;
		}

		//�ڽ��� n�� m�� �ִ������� ������ �� �ִٸ� �׷��� ������ ���� ���� ���� ����� �ñ��.
		short gcd = getGCDMemo(n, m);
		if (gcd != 1) {
			short dn = n / gcd, dm = m / gcd;
			dp[n][m] = solve(dn, dm);
			//std::cout << "solve " << n << " " << m << "�� " << dp[n][m] << "���� ����." << std::endl;
			return dp[n][m];
		}

		int minResult = n * m;//this is fucked up answer.
		//�ڸ��� ���� ���������� �ڸ��� ��� ���� �� ���� ���̴�.
		//�ڽ��� n�� ��ĭ�� �߶󰡸鼭 ��� ����� ���� ���Ѵ�.
		for (int i = 1; i <= n / 2; i++) {
			minResult = std::min(minResult, solve(i, m) + solve(n - i, m));
		}

		//�ڽ��� m�� �� ĭ�� �߶󰡸鼭 ��� ����� ���� ���Ѵ�.
		for (int i = 1; i <= m / 2; i++) {
			minResult = std::min(minResult, solve(n, i) + solve(n, m - i));
		}

		//std::cout << "solve " << n << " " << m << "�� " << minResult << "���� ����." << std::endl;
		return dp[n][m] = minResult;

	}

}

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;

	std::cin >> n >> m;

	//�����ϴٸ� ������ ũ�⸦ ���� �ٿ����� �����Ѵ�.
	short gcd = getGCDMemo(n, m);
	n /= gcd;
	m /= gcd;

	//������ ũ�⸦ �ٿ����� ����� �����Ѵ�.
	std::cout << solve(n, m) << std::endl;

}