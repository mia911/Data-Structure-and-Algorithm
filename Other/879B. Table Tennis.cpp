#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int power(int n, long long k, int a[]) {
    int output = INT_MIN;
    if(k > n - 1) {
        sort(a, a+n);
        output = a[n - 1];
    } else {
        int count[n];
        count[0] = 0;
        count[1] = 0;
        int ii;
        if(a[0] > a[1]) {
            output = a[0];
            count[0] += 1;
            ii = 0;
        } else {
            output = a[1];
            count[1] += 1;
            ii = 1;
        }
        
        for(int i = 2; i < n; i++) {
            count[i] = 0;
            if(a[i] > output) {
                output = a[i];
                count[i] += 1;
                ii = i;
            } else {
                count[ii] += 1;
            }
            if(count[i] == k || count[ii] == k)
                return output;
        }
    }
    return output;
}

int main () {
    int n;
    long long k;
    cin>>n;
    cin>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int output = power(n, k, a);
    cout<<output<<"\n";
    return 0;
}