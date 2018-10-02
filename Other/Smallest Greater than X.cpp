#include <iostream>
#include <vector>

using namespace std;

vector<int> find_y(int a[], string x) {
    vector<int>y(x.size(), -1);
    for(int i = x.size() - 2; i >= 0; i--){
        for(int j = 0; j < i; j++)
            y[j] = a[j];

        vector<int> s(10, 0);
        for(int j = i; j < x.size(); j++)
            s[a[j]] += 1;

        int yy = -1;
        for(int j = x.size() - 1; j > i; j--) {
            if(a[i] < a[j]) {
                yy = j;
                break;
            }
        }

        if(yy == -1)
            continue;

        y[i] = a[yy];
        s[y[i]] -= 1;

        for(int j = i + 1; j < x.size(); j++) {
            for(int k = 0; k < 10; k++) {
                if(s[k] > 0) {
                    y[j] = k;
                    s[k] -= 1;
                    break;
                }
            }
        }
        break;
    }

    return y;
}

int main () {
    string x;
    cin>>x;

    int a[x.size()];
    for(int i = 0; i < x.size(); i++)
        a[i] = x[i] - '0';

    vector<int>y = find_y(a, x);
    for(int i = 0; i < y.size(); i++)
        cout<<y[i];

    cout<<"\n";
    return 0;
}

