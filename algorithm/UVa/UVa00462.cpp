#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <tuple>

bool compareFunc(std::tuple<int, int> a, std::tuple<int, int> b){
	return std::get<1>(a) > std::get<1>(b);
}

int main() {

	std::string buffer;
	
	while (true) {

		std::getline(std::cin, buffer);

		if (buffer == "") {
			break;
		}

		bool cardSet[4][14] = { 0 };
		int cardCount[4] = { 0 };
		int stopSet[4] = { 0 };

		std::stringstream ss(buffer);
			
		for (int i = 0; i < 13; i++) {

			std::string card;
			ss >> card;

			int suit = 0;//0 for spades, 1 for hearts, 2 for diamonds, 3 for clubs

			if (card[1] == 'S') {
				suit = 0;
			}
			else if (card[1] == 'H') {
				suit = 1;
			}
			else if (card[1] == 'D') {
				suit = 2;
			}
			else if (card[1] == 'C') {
				suit = 3;
			}

			int num = 1;
			if (card[0] == 'A') {
				num = 1;
			}else if (card[0] == 'T') {
				num = 10;
			}
			else if (card[0] == 'J') {
				num = 11;
			}
			else if (card[0] == 'Q') {
				num = 12;
			}
			else if (card[0] == 'K') {
				num = 13;
			}
			else {
				num = card[0] - '0';//0 has ascii code, subtracting it gives you number. yea.
			}

			cardSet[suit][num] = true;
			cardCount[suit]++;

		}

		int score = 0;
		int additionalScore = 0;

		for (int i = 0; i < 4; i++) {

			//rule 1

			if (cardSet[i][1]) {
				score += 4;
			}
			if (cardSet[i][13]) {
				score += 3;
			}
			if (cardSet[i][12]) {
				score += 2;
			}
			if (cardSet[i][11]) {
				score += 1;
			}

			//rule 2
			if (cardSet[i][13] && cardCount[i] == 1) {
				score -= 1;
			}

			//rule 3
			if (cardSet[i][12] && cardCount[i] <= 2) {
				score -= 1;
			}

			//rule 4
			if (cardSet[i][11] && cardCount[i] <= 3) {
				score -= 1;
			}

			//rule 5
			if (cardCount[i] == 2) {
				additionalScore += 1;
			}

			//rule 6
			if (cardCount[i] == 1) {
				additionalScore += 2;
			}

			//rule 7
			if (cardCount[i] == 0) {
				additionalScore += 2;
			}

			//stop calculating
			if (cardSet[i][1] || (cardSet[i][13] && cardCount[i] > 1) || (cardSet[i][12] && cardCount[i] > 2)) {
				stopSet[i] = true;
			}

		}

		if (score + additionalScore < 14) {
			std::cout << "PASS" << std::endl;
		}
		else if(score >= 16 && stopSet[0] && stopSet[1] && stopSet[2] && stopSet[3]){
			std::cout << "BID NO-TRUMP" << std::endl;
		}
		else {
			std::vector<std::tuple<int, int>> bidCandidates;
			for (int i = 0; i < 4; i++) {
				bidCandidates.push_back(std::tuple<int, int>(i, cardCount[i]));
			}
			std::sort(bidCandidates.begin(), bidCandidates.end(), compareFunc);

			std::cout << "BID ";

			if (std::get<0>(bidCandidates[0]) == 0) {
				std::cout << "S";
			}else if (std::get<0>(bidCandidates[0]) == 1) {
				std::cout << "H";
			}else if(std::get<0>(bidCandidates[0]) == 2) {
				std::cout << "D";
			}else {
				std::cout << "C";
			}

			std::cout << std::endl;

		}

	}

	return 0;

}