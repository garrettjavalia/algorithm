#include <iostream>
#include <cstring>

//fuckin 3d hexagon map, which is from https://www.redblobgames.com/grids/hexagons/ for its structure
// 0 = up, 1 = upleft, 2 = downleft, 3 = down, 4 = downright, 5 = upright
int dx[6] = {0, -1, -1, 0, 1, 1};
int dy[6] = {-1, 0, 1, 1, 0, -1};
int dz[6] = {1, 1, 0, -1, -1, 0};

inline void moveUp(int pos[3]) {

	pos[1] -= 1;
	pos[2] += 1;

}

inline void moveDown(int pos[3]) {

	pos[1] += 1;
	pos[2] -= 1;

}

inline void moveUpRight(int pos[3]) {

	pos[0] += 1;
	pos[1] -= 1;

}

inline void moveDownRight(int pos[3]) {

	pos[0] += 1;
	pos[2] -= 1;

}

inline void moveUpLeft(int pos[3]) {

	pos[0] -= 1;
	pos[2] += 1;

}

void moveDownLeft(int pos[3]) {

	pos[0] -= 1;
	pos[1] += 1;

}

void setNextResource(int map[300][300][300], int pos[3], int resourceCounter[6]) {
	int possibleResources[6] = { 0, 1, 1, 1, 1, 1 };
	//주변의 모든 자원을 얻어온다.
	int poscopy[6][3];
	for (int i = 0; i < 6; i++) {
		poscopy[i][0] = pos[0];
		poscopy[i][1] = pos[1];
		poscopy[i][2] = pos[2];
	}
	moveUp(poscopy[0]);
	moveUpRight(poscopy[1]);
	moveUpLeft(poscopy[2]);
	moveDown(poscopy[3]);
	moveDownRight(poscopy[4]);
	moveDownLeft(poscopy[5]);

	for (int i = 0; i < 6; i++) {
		possibleResources[map[poscopy[i][0]][poscopy[i][1]][poscopy[i][2]]] = 0;
	}

	int minresourcecnt = 999999999;
	for (int i = 1; i < 6; i++) {
		if (possibleResources[i] && resourceCounter[i] <= minresourcecnt) {
			minresourcecnt = resourceCounter[i];
		}
	}
	for (int i = 1; i < 6; i++) {
		if (possibleResources[i] && resourceCounter[i] == minresourcecnt) {
			
			map[pos[0]][pos[1]][pos[2]] = i;
			resourceCounter[i]++;
			break;
		}
	}


}

int(* hexagonMap)[300][300] = nullptr;

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 0;
	std::cin >> t;

	//begin from cente
	hexagonMap = new int[300][300][300]();
	int answer[10000] = {0};
	int pos[3] = { 150, 150, 150};
	int resourceCounter[6] = {0};

	int count = 0;
	int level = 1;
	int direction = 5;// 0 = up, 1 = upleft, 2 = downleft, 3 = down, 4 = downright, 5 = upright
	int step = 0;
	while (count < 10000) {

		//해당 칸에 기록
		setNextResource(hexagonMap, pos, resourceCounter);
		answer[count] = hexagonMap[pos[0]][pos[1]][pos[2]];

		if (direction == 0) {
			if (step == level - 1) {
				moveUpLeft(pos);
				direction = 1;
				step = 1;
			}
			else {
				moveUp(pos);
				step++;
			}
		}
		else if (direction == 1) {
			if (step == level - 1) {
				moveDownLeft(pos);
				direction = 2;
				step = 1;
			}
			else {
				moveUpLeft(pos);
				step++;
			}
		}
		else if (direction == 2) {
			if (step == level - 1) {
				moveDown(pos);
				direction = 3;
				step = 1;
			}
			else {
				moveDownLeft(pos);
				step++;
			}
		}
		else if (direction == 3) {
			if (step == level - 1) {
				moveDownRight(pos);
				direction = 4;
				step = 1;
			}
			else {
				moveDown(pos);
				step++;
			}
		}
		else if (direction == 4) {
			if (step == level - 1) {
				moveUpRight(pos);
				direction = 5;
				step = 1;
			}
			else {
				moveDownRight(pos);
				step++;
			}
		}
		else if (direction == 5) {
			if (step == level - 1) {
				moveUpRight(pos);
				direction = 0;
				step = 1;
				level++;
			}
			else {
				moveUpRight(pos);
				step++;
			}
		}

		count++;

	}
		
	while (t--) {

		int n = 0;
		std::cin >> n;
		n--;
		std::cout << answer[n] << (t != -1 ? "\n" : "");

	}

	delete[] hexagonMap;

	return 0;

}