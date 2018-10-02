#include <iostream>
#include <string>

using namespace std;

string crossword(int x, int n, int a[]) {
	string output;
	int encode_len = 0;
	for(int i = 0; i < n; i++)
		encode_len += a[i];
	encode_len += n - 1;
	if(encode_len == x) {
		output = "YES";
	} else
		output = "NO";
	return output;
}

int main() {
	int x, n;
	cin>>n;
	cin>>x;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	string output = crossword(x, n, a);
	cout<<output;
	return 0;
}
