#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int result;
    int jump = 1, sum = 0;

    cin >> str;

    result = str.size();

    for (int i = 0; i < str.size(); i++){
        jump = 1;
        for (int j = i + 1; str[i] == str[j]; j++){
            jump++;
        }
        if (jump > 0){
            cout << jump << endl;
            i += jump;
            sum += jump - 1;
        }
        // cout << i << ' ';
    }

    cout << sum;

    return 0;
}