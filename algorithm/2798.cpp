#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);

    int n, m;
    int cards[100];

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){

        std::cin >> cards[i];

    }

    int firstcard, secondcard, maxsum = 0;
    for(int i = 0; i < n; i++){
        firstcard = i;
        if(cards[firstcard] > m){
            continue;
        }
        for(int j = 0; j < n; j++){
            secondcard = j;
            if((j == firstcard) || (cards[firstcard] + cards[j] > m)){
                continue;
            }
            for(int k = 0; k < n; k++){
                if((k == firstcard) || (k == secondcard) || (cards[firstcard] + cards[j] + cards[k] > m) || (cards[firstcard] + cards[j] + cards[k] < maxsum)){
                    continue;
                }
                maxsum = cards[i] + cards[j] + cards[k];
            }
        }
    }

    std::cout << maxsum;

    return 0;

}