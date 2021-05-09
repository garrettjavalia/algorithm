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

void adjust(int key, int value, FenwickTree &negativeCounter, FenwickTree &zeroCounter, std::vector<int> &valueType){

    if(value == 0){
        //0이 되면 기존의 값에 따라서 행동
        //기존에 0이 아니었다면 0 카운터 증가
        if(valueType[key] != 0){
            zeroCounter.adjust(key, 1);
        }
        if(valueType[key] == -1){
            negativeCounter.adjust(key, -1);
        }
        valueType[key] = 0;
    }else if(value < 0){
        //기존에 0이었다면 0 카운터 감소
        if(valueType[key] == 0){
            zeroCounter.adjust(key, -1);
        }
        //기존에 음수가 아니었다면 음수 카운터 증가
        if(valueType[key] != -1){
            negativeCounter.adjust(key, 1);
        }
        valueType[key] = -1;
    }else{
        //양수가 되면 0과  음수 카운터를 모두 제거한다.
        if(valueType[key] == 0){
            zeroCounter.adjust(key, -1);
        }
        if(valueType[key] == -1){
            negativeCounter.adjust(key, -1);
        }
        valueType[key] = 1;
    }

}

int main(){

    std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, k;

    while(true){

        std::cin >> n >> k;

        if(std::cin.eof()){
            break;
        }

        FenwickTree negativeCounter(n);
        FenwickTree zeroCounter(n);
        std::vector<int> valueType;
        valueType.assign(n + 1, 0);

        for(int i = 0; i < n; i++){
            zeroCounter.adjust(i + 1, 1);
        }

        for(int i = 0; i < n; i++){
            int x = 0;
            std::cin >> x;
            adjust(i + 1, x, negativeCounter, zeroCounter, valueType);
        }

        for(int i = 0; i < k; i++){
            char cmd;
            int a1, a2;
            std::cin >> cmd >> a1 >> a2;
            if(cmd == 'P'){
                bool first = true;
                int res = 0;
                if(zeroCounter.rangeSumQuery(a1, a2) == 0){
                    if(negativeCounter.rangeSumQuery(a1, a2) % 2){
                        std::cout << '-';
                    }else{
                        std::cout << '+';
                    }
                }else{
                    std::cout << 0;
                }
            }else if(cmd == 'C'){
                adjust(a1, a2, negativeCounter, zeroCounter, valueType);
            }
        }

        std::cout << std::endl;

    }

    return 0;

}