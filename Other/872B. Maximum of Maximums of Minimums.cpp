#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int divide(int n, int a[]) {
    int output = INT_MIN;
    int left[n - 1], right[n];
    left[0] = a[0];
    right[n - 1] = a[n - 1];
    
    for(int i = 1; i < n - 1; i++) {
        if(a[i] >= a[i - 1]) {
            left[i] = left[i - 1];
        } else {
            left[i] = min(left[i - 1], a[i]);
        }
    }
    
    for(int i = n-2; i >= 1; i--) {
        if(a[i] >= a[i + 1]) {
            right[i] = right[i + 1];
        } else {
            right[i] = min(a[i], right[i + 1]);
        }
    }
    
    for(int i = 0; i < n - 1; i++) {
        output = max(left[i], max(right[i + 1], output));
//        cout<<output<<" ";
    }
    
    return output;
}

int max_min(int n, int k, int a[]) {
    int output = INT_MIN;
    if(k == 1) {
        output = a[0];
        for(int i = 0; i < n; i++)
            output = min(output, a[i]);
    } else if (k == 2) {
        output = divide(n, a);
    } else {
        for(int i = 0; i < n; i++)
            output = max(output, a[i]);
    }
    
    return output;
}

int main() {
    int n, k;
    cin>>n;
    cin>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    int output = max_min(n, k, a);
    cout<<output<<"\n";
    return 0;
}