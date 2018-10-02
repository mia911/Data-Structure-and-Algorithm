#include <iostream>

using namespace std;

int zigzag(int a[], int n) {
    int flag[n][2];
    flag[0][0] = 1; //0: giam
    flag[0][1] = 1; //1: tang
    int trace[n][2];
    int ii, jj;
    int max_sub = 0;
    for(int i = 1; i < n; i++) {
        flag[i][0] = 1;
        flag[i][1] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                if(flag[i][0] < flag[j][1] + 1) {
                    flag[i][0] = flag[j][1] + 1;
                    trace[i][0] = j;
                }
            } else if(a[i] < a[j]) {
                if(flag[i][1] < flag[j][0] + 1) {
                    flag[i][1] = flag[j][0] + 1;
                    trace[i][1] = j;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            if(max_sub < flag[i][j]) {
                max_sub = flag[i][j];
                ii = i;
                jj = j;
            }
        }
    }
    
    int i = max_sub;
    int zigzag[i];
    while(i > 0) {
        zigzag[i] = 
    }
    return max_sub;
}

int main() {
    int n;
    cout<<"Input n: "; cin>>n;
    cout<<"Input array: \n";
    int a[n];
    int x;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    x = zigzag(a, n);
    cout<<x<<"\n";
    return 0;
}
