#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int n = 8;
    int m = n;
    bitset<8>A(0);
    bitset<8>M(3);
    bitset<8>Q(14);
    cout << "Dividendo: " << Q <<endl;
    cout << "Divisor: " << M <<endl;
    while(n > 0){
        for(int i=m-1; i>=0; i--){
            if(i != 0){
                if(A.test(i-1)!= 0){
                    A.set(i,1);
                }else{
                    A.set(i,0);
                }
            }
            else{
                if(Q.test(m-1) != 0){
                    A.set(i,1);
                }else{
                    A.set(i,0);
                }
            }
        }
        for(int j=m-1; j>=0; j--){
            if(j != 0){
                if(Q.test(j-1)!= 0){
                    Q.set(j,1);
                }else{
                    Q.set(j,0);
                }
            }
            else{
                long x = A.to_ulong();
                long y = M.to_ulong();
                long b = x-y;
                if (b < 0){
                    Q.set(j,0);
                }
                else{
                    Q.set(j,1);
                    A = b;
                }
            }
        }
        n--;
    }
    cout<<endl<< "Residuo:" << A <<" " << "Cociente: "<<Q;
    return 0;
}
