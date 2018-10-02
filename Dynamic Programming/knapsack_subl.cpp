#include <iostream>

using namespace std;

int w;
int n;
int value[100];
int weight[100];
int bag[100][100];

void knapsack() {
    if(w == 0 || n == 0) {
    	cout<<0<<"\n";
    	return;
    }

    for(int i = 0; i < n; i++) {
    	for(int j = 0; j <= w; j++) {
    		if(i == 0 || j == 0) {
    			bag[i][j] = 0;
    		} else if(weight[i] <= j) {
    			bag[i][j] = max(bag[i - 1][j], value[i] + bag[i - 1][j - weight[j]]);
    		} else {
    			bag[i][j] = bag[i - 1][j];
    		}
    	}
    }

    cout<<bag[n-1][w]<<"\n";
    return;
}

int main() {
    cout<<"Input bag limit weight: "; cin>>w;
    cout<<"Input number of items: "; cin>>n;
    cout<<"Input item:\n";
    for(int i = 0; i < n; i++) {
        cout<<"Value: "; cin>>value[i];
        cout<<"Weight: "; cin>>weight[i];
    }
    knapsack();
    return 0;
}
