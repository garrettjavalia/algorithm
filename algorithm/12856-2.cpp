#include <iostream>
#include <algorithm>

int weight[101] = { 0 };//무게
int value[101] = { 0 };//가치
int memory[101][1000001] = { 0 };//부분집합의 최대가치

int main(int argc, char* argv[]) {

	std::iostream::sync_with_stdio(false);

	//배낭 문제는 이런 방식으로 풀린다.
	//아이템들을 하나하나 순서대로 포함하는 부분집합을 가정하고, 원소의 갯수가 작은 부분집합부터 아래의 연산을 수행한다.
	//해당 집합이 무게가 0일 때부터 무게가 배낭의 최종 한계까지 가질 수 있는 최대의 무게를 계산한다.
	//단, 계산은 이렇게 이루어진다.
	//1. 이전 집합으로 만들 수 있는 가치 중 자신의 무게를 제외한 것과 포함한 것을 둘 다 사용한다.
	//2. 자신의 무게를 제외한 것과 포함한 것 중 가치를 더 크게 만들 수 있는 쪽을 고른다.
	//모든 부분집합에 대해서 이 과정을 반복한다.
	//배낭채우기 문제에 대해서 백준에서는 항의 수를 제한하지 않고 모두 계산하는 것이 더 빠르게 풀린다.
	
	int n = 0, k = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (weight[i] <= j) {
				memory[i][j] = std::max(memory[i - 1][j], memory[i - 1][j - weight[i]] + value[i]);
			}
			else {
				memory[i][j] = memory[i - 1][j];
			}
		}
	}

	std::cout << memory[n][k] << std::endl;

	return 0;

}