#include <iostream>

using namespace std;

int trip(int n, int a, int b, int c) {
    if(n <= 1) {
        return 0;
    }
    
    int path[3];
    path[0] = a;
    path[1] = b;
    path[2] = c;
    int j = 0;
    int distance = 0;
    for(int i = 0; i < n - 1; i++) {
        if(j == 0) {
            if(path[1] < path[0]) {
                distance += path[1];
                j = 2;
            } else {
                distance += path[0];
                j = 1;
            }
        } else if(j == 1) {
            if(path[0] < path[2]) {
                distance += path[0];
                j = 0;
            } else {
                distance += path[2];
                j = 2;
            }
        } else {
            if(path[2] < path[1]) {
                distance += path[2];
                j = 1;
            } else {
                distance += path[1];
                j = 0;
            }
        }
    }
    return distance;
}

int main () {
    int n, a, b, c;
    cin>>n;
    cin>>a;
    cin>>b;
    cin>>c;
    int output = trip(n, a, b, c);
    cout<<output<<endl;
    return 0;
}
