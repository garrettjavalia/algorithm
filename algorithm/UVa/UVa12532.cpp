#include <iostream>
#include <vector>

class FenwickTree{

    private:

    std::vector<int> data;

    int leastSignificantBit(int n){
        return n & (-n);
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
        return rangeSumQuery(b) - (a == 1 ? 0 : rangeSumQuery(a - 1));
    }

    void adjust(int k, int v){
        for(; k < data.size(); k += leastSignificantBit(k)){
            data[k] += v;
        }
        // for (int i = 0; i < data.size(); i++){
        //     std::cout << data[i] << " ";
        // }
        // std::cout << std::endl;
    }

};

int main(){

    int n, k;

    while(true){

        std::cin >> n >> k;

        if(std::cin.eof()){
            break;
        }

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
            if(cmd == 'P'){
                bool first = true;
                int res = 0;
                for(int i = a1; i <= a2; i++){
                    if(first){
                        res = ft.rangeSumQuery(i, i);
                        first = false;
                    }else{
                        res = res * ft.rangeSumQuery(i, i);
                    }
                    if(res == 0){
                        break;
                    }else if(res > 0){
                        res = 1;
                    }else{
                        res = -1;
                    }
                }
                if(res == 0){
                    std::cout << 0;
                }else if(res > 0){
                    std::cout << '+';
                }else{
                    std::cout << '-';
                }
            }else if(cmd == 'C'){
                int res = ft.rangeSumQuery(a1, a1);
                ft.adjust(a1, a2 - res);
            }
        }

        std::cout << std::endl;

    }

    return 0;

}