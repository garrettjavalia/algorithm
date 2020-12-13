#include <iostream>
#include <sstream>
#include <string>

int main() {

	double h, u, d, f;
	
	while (true) {
		
		std::cin >> h >> u >> d >> f;

		if (h == 0) {
			break;
		}

		int day = 1;
		double pos = 0.0;
		double fatigueFactor = 0.0;
		double climb = u;

		while(true){

			//day
			if (climb > 0) {
				pos += (climb);//problem said that our snail never climbs neg value(no sliding during the day)
			}
			//if u use code that calculates fatigueFactor below, it will bring you into hard to find floating point calculation miss match.
			//it leads you to countless failure.
			//he made it
			if (pos > h) {
				break;
			}
			fatigueFactor += (f * 0.01);//snail got tired.
			climb -= u / 100 * f;
			//night
			pos -= d;
			//day passes

			//he failed
			if (pos < 0) {
				break;
			}
			//std::cout << "day status " << day << " " << pos << " " << fatigueFactor << std::endl;

			day++;

		}

		std::cout << ((pos > h) ? "success" : "failure") << " on day " << day << std::endl;

	}

	return 0;

}