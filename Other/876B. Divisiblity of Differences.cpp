#include <iostream>
#include <vector>

using namespace std;

void divisibility(int n, int k, int m, vector<int> a[]) {
    if(k > n) {
        cout<<"No"<<endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (a[i].size() >= k) {
            cout << "Yes" << endl;
            for (int j = 0; j < k-1; j++) {
                cout << a[i][j] << " ";
            }
            cout << a[i][k-1];
            return;
        }
    }
    cout << "No" << endl;
    return;
}

int main () {
    int n, k, m;
    cin>>n;
    cin>>k;
    cin>>m;
    vector<int> a[100005];
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[temp%m].push_back(temp);
    }
    divisibility(n, k, m, a);
    return 0;
}