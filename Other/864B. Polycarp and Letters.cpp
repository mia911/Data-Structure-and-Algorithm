#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void pretty(int n, string a) {
    string tmp = "";
    int flag[256];
    for(int i = 0; i < 256; i++)
        flag[i] = 0;
    
    int cnt = 0;
    int cnt_max = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= 'z' && a[i] >= 'a') {
            tmp += a[i];
//            cout<<flag[(int)a[i]]<<endl;
            if(flag[(int)a[i]] != 1) {
                cnt += 1;
            }
            flag[(int)a[i]] = 1;
        } else {
            for(int j = 0; j < tmp.size(); j++) {
                flag[(int)tmp[j]] = 0;
            }
            tmp = "";
            cnt = 0;
        }
        cnt_max = max(cnt, cnt_max);
//        cout<<cnt<<" ";
//        cout<<tmp<<" ";
//        cout<<cnt_max<<" ";
    }
    cout<<cnt_max<<endl;
    return;
}

int main() {
//    cout<<"Input n: "<<endl;
    int n;
    cin>>n;
    string a;
    cin>>a;
    pretty(n, a);
    return 0;
}
