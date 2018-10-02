#include <iostream>
#include <string>

using namespace std;

void extract_numb(string a) {
    a += ";";
    int n = a.length();
    int save_comma = -1;
    int flag;
    string b;
    string result_a = "";
    string result_b;
    string c;
    int flag_c = 0;
    int flag_a = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == ',' || a[i] == ';') {
            flag = 0;
            b = "";
            c = "";
            
            for(int j = save_comma + 1; j < i; j++) {
                if('0' > a[j] || a[j] > '9') {
                    flag = 1;
                    c = a.substr(save_comma + 1, i - save_comma - 1);
                    break;
                }
                b += a[j];
            }
            
            if(b[0] == '0' && b.length() > 1) {
                c = a.substr(save_comma + 1, i - save_comma - 1);
                flag = 1;
            }
            
            if(flag == 0 && b.length() > 0) {
                if(flag_a) {
                    result_a += ",";
                } else {
                    result_a += "\"";
                }
                result_a += b;
                flag_a = 1;
            } else {
                if(flag_c == 1) {
                    result_b += ",";
                } else {
                    result_b += "\"";
                }
                result_b += c;
                flag_c = 1;
            }
            
            save_comma = i;
//            cout<<save_comma<<" ";
        }
    }
    if(result_a.length())
        result_a += "\"";
    else
        result_a = "-";
    
    if(result_b.length())
        result_b += "\"";
    else
        result_b = "-";
    
    cout<<result_a<<"\n";
    cout<<result_b<<"\n";
    return;
}

int main() {
    string a;
    cin>>a;
    extract_numb(a);
    return 0;
}
