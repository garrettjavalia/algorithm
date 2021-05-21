#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int t;
    std::cin >> t;

    while(t--){

        std::vector<int> coins;
        int coinCount;
        std::cin >> coinCount;

        while(coinCount--){
            int coin;
            std::cin >> coin;
            coins.push_back(coin);
        }
        std::vector<bool> coinCheck;
        coinCheck.assign(coins.size(), false);

        int totalMoney = 1;
        int typeCount = 1;

        for(int i = 1; i < coins.size() - 1; i++){
            if(totalMoney + coins[i] < coins[i + 1]){
                typeCount++;
                totalMoney += coins[i];
            }
        }

        std::cout << typeCount + 1 << std::endl;

    }

    return 0;

}