#include <iostream>
#include <algorithm>

int weight[101] = { 0 };//무게
int value[101] = { 0 };//가치
int memory[101][1000001] = { 0 };//부분집합의 최대가치... 분할정복한다...
bool handled[101][1000001] = { false };//dp 계산 필요 여부 값

void Solver(int citem, int cweight) {

	//std::cout << "solver" << citem << " " << cweight << std::endl;

	if (!handled[citem][cweight]) {

		if (citem == 1) {

			if (cweight >= weight[citem]) {
				memory[citem][cweight] = value[citem];
			}
			else{
				memory[citem][cweight] = 0;
			}

			//std::cout << "계산된 최대가치 " << memory[citem][cweight] << std::endl;

		}
		else {

			Solver(citem - 1, cweight - weight[citem] > 0 ? cweight - weight[citem] : 0);//자기 무게를 제외한 이전 집합의 최대값
			Solver(citem - 1, cweight);//자기 무게를 포함한 이전 집합의 최대값

			if (cweight >= weight[citem]) {
				memory[citem][cweight] = std::max(memory[citem - 1][cweight], memory[citem - 1][cweight - weight[citem]] + value[citem]);
			}
			else {
				memory[citem][cweight] = memory[citem - 1][cweight];
			}

			//std::cout << "계산된 최대가치 " << memory[citem][cweight] << std::endl;


		}

		handled[citem][cweight] = true;

	}

}

int main(int argc, char* argv[]) {

	std::iostream::sync_with_stdio(false);

	//배낭 문제는 이런 방식으로 풀린다.
	//아이템들을 하나하나 순서대로 포함하는 부분집합을 가정하고, 원소의 갯수가 작은 부분집합부터 아래의 연산을 수행한다.
	//해당 집합이 무게가 0일 때부터 무게가 배낭의 최종 한계까지 가질 수 있는 최대의 무게를 계산한다.
	//단, 계산은 이렇게 이루어진다.
	//1. 이전 집합으로 만들 수 있는 가치 중 자신의 무게를 제외한 것과 포함한 것을 둘 다 사용한다.
	//2. 자신의 무게를 제외한 것과 포함한 것 중 가치를 더 크게 만들 수 있는 쪽을 고른다.
	//모든 부분집합에 대해서 이 과정을 반복한다.

	//우리는 필요한 행만 계산하는 개선된 알고리즘을 사용할 것이다.
	//dp풀이는 모든 칸에 대해서 연산을 수행하므로 상당히 느려진다.
	//분할정복은 메모리를 크게 갖지 않으면 결국 중복연산을 한다.
	//두 개의 문제점을 해결하기 위해서, 메모이제이션을 하는 재귀 분할정복 기법을 사용한다.
	int n = 0, k = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> weight[i] >> value[i];
	}

	Solver(n, k);

	std::cout << memory[n][k] << std::endl;

	return 0;

}