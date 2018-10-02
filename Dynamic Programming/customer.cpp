#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n;
int a[100];
int b[100];
int c[100];
int flag[100]; // so tien nhieu nhat co the khi cho khach hang i cuoi cung thue
int idx[100];
int trace[100];

bool cmp(int x, int y) {
    if(b[x] < b[y])
        return true;
    else
        return false;
}

void customer() {
    int ii = 0;
    sort(idx, idx + n, cmp);
    if(n == 1) {
        cout<<c[0]<<"\n";
        return;
    }
    int max_rev = c[idx[0]];
    for(int i = 0; i < n; i++) {
        flag[i] = c[idx[i]];
        trace[i] = -1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(b[idx[j]] <= a[idx[i]]) {
                if(flag[i] < c[idx[i]] + flag[j]) {
                    flag[i] = c[idx[i]] + flag[j];
                    trace[i] = j;
                }
                if(max_rev < flag[i]) {
                    max_rev = flag[i];
                    ii = i;
                }
            }
        }
        if(max_rev < flag[i]) {
            max_rev = flag[i];
            ii = i;
        }
    }
    while(ii > 0) {
        cout<<idx[ii]<<" ";
        ii = trace[ii];
    }
    cout<<max_rev<<"\n";
    return;
}

int main() {
    cout<<"Input n: "; cin>>n;
    cout<<"Input start time: \n";
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<"Input end time: \n";
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        idx[i] = i;
    }
    cout<<"Input money: \n";
    for(int i = 0; i < n; i++) {
        cin>>c[i];
    }
    customer();
    return 0;
}