#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int pretty_num(int n, int m, int a[], int b[]) {
    int output;
    sort(a, a+n);
    sort(b, b+m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                output = a[i];
                return output;
            }
        }
    }
    
    if(a[0] < b[0])
        output = a[0] * 10 + b[0];
    else
        output = b[0] * 10 + a[0];
    
    return output;
}

int main() {
    int n, m;
    cin>>n;
    cin>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    for(int i = 0; i < m; i++)
        cin>>b[i];
    
    int output = pretty_num(n, m, a, b);
    cout<<output<<"\n";
    return 0;
}