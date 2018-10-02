#include <iostream>

using namespace std;

void immortal(long long a, long long b) {
    if(a == b) {
        cout<<1<<endl;
        return;
    }
    
    if(b - a >= 5) {
        cout<<0<<endl;
        return;
    }
    
    long long result = (a + 1)%10;
    
    for(long long i = a + 2; i <= b; i++) {
        result *= i%10;
    }
    
    cout<<result%10<<endl;
    return;
}

int main() {
    long long a, b;
    cin>>a;
    cin>>b;
    immortal(a, b);
    return 0;
}
