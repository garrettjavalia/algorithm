#include <iostream>
#include <cmath>

int main(){

    std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int tests = 0; 
    std::cin >> tests;

    while(tests--){

        long long A, B, C;

        std::cin >> A >> B >> C;

        //해를 구한다.
        //문제의 A, B, C의 범위는 최대 6000000000000000000
        //구의 방정식을 생각해 볼 때 x, y, z의 범위는 2449489743까지 줄어든다.
        //여전히 너무 많다.

        bool solved = false;

        for(long long x = -1817122; x <= 1817122; x++){

            if(x * x <= C){

                long long absylimit = static_cast<long long>(std::sqrt(C - x * x)) + 10;
                //std::cout << "absylimit is " << absylimit << std::endl;

                for(long long y = -absylimit; y <= absylimit; y++){
                    
                    long long t;

                    //둘이 같아선 안된다.
                    if(x == y){
                        continue;
                    }

                    if(x + y <= A && x * y <= B && (t = x * x + y * y) <= C){

                        long long a = C - t;

                        long long z = A - x - y;
                        //std::cout << x << " " << y << " " << z << "dsaf" << std::endl;

                        if(z != x && z != y && z * z == a && x * y * z == B){
                            std::cout << x << " " << y << " " << z << std::endl;
                            solved = true;
                        }                        

                    }else if(y > 0){
                        //y가 아무리 커져도 조건을 만족할 수 없으므로 탈출
                        break;
                    }

                    if(solved) break;

                }

            }else if(x > 0){
                //x가 더 커져도 조건을 만족할 수 없으므로 탈출
                break;
            }

            if(solved) break;

        }

        if(!solved){
            //해가 없다.
            std::cout << "No solution.\n";
        }
    }

    return 0;

}