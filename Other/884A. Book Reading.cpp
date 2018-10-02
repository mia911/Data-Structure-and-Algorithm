//
//  main.cpp
//  stuff
//
//  Created by Trang Nguyen on 10/28/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int time(int n, int t, int a[]) {
    int output = 1;
    int remainer = t - (86400 - a[0]);
    int i = 1;
    while(remainer > 0) {
        if(i >= n)
            break;
        remainer -= (86400 - a[i]);
        output += 1;
        i += 1;
    }
    return output;
}

int main() {
    int n, t;
    cin>>n;
    cin>>t;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int output = time(n, t, a);
    cout<<output<<"\n";
    return 0;
}
