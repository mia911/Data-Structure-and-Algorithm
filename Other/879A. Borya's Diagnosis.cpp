#include <iostream>
#include <cmath>

using namespace std;

int diagnosis(int n, int s[], int d[]) {
    int min_day = s[0];
    for(int i = 1; i < n; i++) {
        if(s[i] > min_day)
            min_day = s[i];
        else {
            min_day = s[i] + d[i] * ((min_day - s[i]) / d[i] + 1);
        }
    }
    return min_day;
}

int main() {
    int n;
    cin>>n;
    int s[n], d[n];
    for(int i = 0; i < n; i++) {
        cin>>s[i];
        cin>>d[i];
    }
    int output = diagnosis(n, s, d);
    cout<<output<<"\n";
    return 0;
}