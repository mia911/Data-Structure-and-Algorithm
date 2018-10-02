#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    //nhap du lieu de bai
    int n;
    cout<<"Nhap n: \n";
    cin>>n;
    
    cout<<"Nhap day a: \n";
    int a[n];
    int i = 0;
    for (i=0; i<n; i++) {
        printf("a[%d]: ",i);
        cin>>a[i];
    }
    
    cout<<"Nhap k: \n";
    int k;
    cin>>k;
    
    //tim day b[k] chua cac phan tu khac biet
    int b[k];
    int current_size_b = 1;
    int j = 0;
    b[0] = a[0];
    for (i=1; i<n; i++) {
        for (j=0; j<current_size_b; j++) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j == current_size_b) {
            b[current_size_b] = a[i];
            current_size_b ++;
        }
        
        if (current_size_b == k) {
            break;
        }
    }
    
    //sap xep day b[k] theo thu tu tang dan
    int l = 0;
    int trunggian = 0;
    for (j=0; j<(k-1); j++) {
        for (l=j+1; l<k; l++) {
            if (b[j] > b[l]) {
                trunggian = b[j];
                b[j] = b[l];
                b[l] = trunggian;
            }
        }
    }
    
    //thay the a[k]
    int flag = 0;
    while (i < n) {
        if (a[i] > b[0]) {
            for (j=0; j<k; j++) {
                flag = 0;
                if (a[i] == b[j]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) {
                b[0] = a[i];
            }
            
        }
        
        for (j=0; j<(k-1); j++) {
            if (b[j] > b[j+1]) {
                trunggian = b[j];
                b[j] = b[j+1];
                b[j+1] = trunggian;
            } else {
                break;
            }
        }
        i++;
    }
    
    for (j=0; j<k; j++) {
        cout<<b[j]<<"  ";
    }
    
    cout<<"\n";
    cout<<"So lon thu k la: ";
    cout<<b[0]<<"\n";
    return 0;
}