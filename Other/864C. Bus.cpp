#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int bus(int a, int b, int f, int k) {
    int result = 0;

    if(b < f)
        return -1;
    
    long long road[k + 1];
    int flag = 1;
    for(int i = 0; i < k; i++) {
        if(flag == 1) {
            road[i] = 1LL * i*a+f;
            flag = 0;
        } else {
            road[i] = 1LL * (i+1)*a-f;
            flag = 1;
        }
//        cout<<road[i]<<" ";
    }
    
    road[k] = 1LL * a*k;
    
    long long gas_tmp = b - f;
    for(int i = 1; i < k + 1; i++) {
        if(road[i] - road[i - 1] > b)
            return -1;
        
        if(gas_tmp >= road[i] - road[i - 1]) {
            gas_tmp -= road[i] - road[i - 1];
//            cout<<1<<" ";
        } else {
            result += 1;
            gas_tmp = b - road[i] + road[i - 1];
//            cout<<2<<" ";
        }
//        cout<<gas_tmp<<endl;
    }
   
    return result;
}

int main() {
    int a, b, f, k;
    cin>>a;
    cin>>b;
    cin>>f;
    cin>>k;
    int x = bus(a, b, f, k);
    cout<<x<<endl;
    return 0;
}
