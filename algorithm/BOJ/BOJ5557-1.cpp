#include <iostream>

int count = 0;
int nums[100];

void combination(int depth, int currentnum, int maxdepth) {
	
	if (depth == 0) {
		currentnum = nums[0];
	}
	if(depth < maxdepth){
		if (currentnum + nums[depth + 1] <= 20) {
			//std::cout << "+" << currentnum + nums[depth + 1] << std::endl;
			combination(depth + 1, currentnum + nums[depth + 1], maxdepth);
		}
		if (currentnum - nums[depth + 1] >= 0) {
			//std::cout << "-" << currentnum - nums[depth + 1] << std::endl;
			combination(depth + 1, currentnum - nums[depth + 1], maxdepth);
		}
	}
	else if (depth == maxdepth) {
		if (currentnum == nums[depth + 1]) {
			count++;
		}
	}



}

int main() {

	std::iostream::sync_with_stdio(false);

	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	int maxdepth = n - 2;
	
	combination(0, 0, maxdepth);

	std::cout << count;

	return 0;

}