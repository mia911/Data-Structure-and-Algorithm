#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int beautiful(string s) {
    unsigned long n = s.length();
    int flag[n][3];
    int output = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            flag[i][0] = 1;
        } else {
            flag[i][1] = 1;
        }
        flag[i][2] = 0;
        for(int j = 0; j < i; j++) {
            if(s[i] == 'a') {
                flag[i][0] = max(flag[i][0], flag[j][0] + 1);
                flag[i][2] = max(flag[j][2] + 1, max(flag[i][2], flag[j][1] + 1));
            } else {
                flag[i][1] = max(flag[j][1] + 1, max(flag[i][1], flag[j][0] + 1));
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            output = max(output, flag[i][j]);
        }
    }
    return output;
}

int main () {
    string s;
    cin>>s;
    int output = beautiful(s);
    cout<<output<<"\n";
    return 0;
}