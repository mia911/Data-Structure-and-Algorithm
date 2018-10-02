#include <iostream>
#include <cstring>

using namespace std;

string friends[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string user_input;

string contest() {
    int n = user_input.length();
    int i, j, k, ii, count;
    string answer = "NO";
    int repeat = 0;
    
    for(i = 0; i < n; i++) { //loop input character
        for(j = 0; j < 5; j++) { //loop 5 friends
            count = 0;
            ii = i;
            for(k = 0; k < friends[j].length(); k++) { //loop friends character
                if(user_input[ii] == friends[j][k]) {
                    count += 1;
                    ii += 1;
                } else {
                    break;
                }
            }
            if(count == friends[j].length()) {
                repeat += 1;
                if(repeat > 1) {
                    answer = "NO";
                    return answer;
                }
            }
        }
    }
    
    if(repeat == 1)
        answer = "YES";
    
    return answer;
}

int main() {
    cin>>user_input;
    string output = contest();
    cout<<output<<"\n";
    return 0;
}
