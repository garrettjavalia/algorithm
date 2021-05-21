#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

int main(){

    int c, s;
    int setNum = 1;

    while(true){

        std::cin >> c >> s;
        if(!std::cin.eof()){

            std::vector<int> massList;
            int temp;
            int totalMass = 0;
            float avgMass;
            float imbalance = 0.0;
            for(int i = 0; i < s; i++){
                std::cin >> temp;
                massList.push_back(temp);
                totalMass += temp;
            }

            avgMass = static_cast<float>(totalMass) / c;
            for(int i = s; i < 2 * c; i++){
                massList.push_back(0);
            }

            std::sort(massList.begin(), massList.end());

            std::cout << "Set #" << setNum++ << std::endl;

            for(int i = 0; i < c; i++){

                int chamberMass = massList[i] + massList[massList.size() - 1 - i];
                std::cout << " " << i << ":" << (massList[i] == 0 ? " " : " " + std::to_string(massList[i]) + " ") << (massList[massList.size() - 1 - i] != 0 ? std::to_string(massList[massList.size() - 1 - i]) : "") << std::endl;

                imbalance += std::abs(chamberMass - avgMass);

            }

            std::cout << "IMBALANCE = " << std::setprecision(5) << std::fixed << imbalance << std::endl << std::endl;

        }else{
            break;
        }

    }

    return 0;

}