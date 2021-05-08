#include <iostream>
#include <vector>

class FenwickTree{

    private:

    std::vector<int> data;

    int leastSignificantBit(int n){
        return n & -n;
    }

    public:
    FenwickTree(int size){
        data.assign(size + 1, 0);
    }

    int rangeSumQuery(int b){
        int res = 0;
        for(; b; b -= leastSignificantBit(b)){
            res += data[b];
        }
        return res;
    }

    int rangeSumQuery(int a, int b){
        return rangeSumQuery(b) - (a == 1 ? 0 : rangeSumQuery(a));
    }

    void adjust(int k, int v){
        for(; k < data.size(); k += leastSignificantBit(k)){
            data[k] += v;
        }
    }

};

int main(){

    int n, k;

    while(true){

        if(!std::cin.eof()){
            std::cin >> n >> k;

            FenwickTree ft(n);

            for(int i = 0; i < n; i++){
                int x = 0;
                std::cin >> x;
                ft.adjust(i + 1, x);
            }

            for(int i = 0; i < k; i++){
                char cmd;
                int a1, a2;
                std::cin >> cmd >> a1 >> a2;
                if(cmd == 'C'){
                    bool first = true;
                    int res = 0;
                    for(int i = a1; i <= a2; i++){
                        if(first){
                            res = ft.rangeSumQuery(i, i);
                            first = false;
                        }else{
                            res *= ft.rangeSumQuery(i, i);
                        }
                        if(res == 0){
                            break;
                        }
                    }
                    if(res == 0){
                        std::cout << 0;
                    }else if(res > 0){
                        std::cout << '+';
                    }else{
                        std::cout << '-';
                    }
                }else if(cmd == 'P'){
                    ft.adjust(a1, a2);
                }
            }

        }else{
            break;
        }

    }

    return 0;

}