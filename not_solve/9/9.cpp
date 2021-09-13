#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    return answer;
}

int main(){
    string a, b;

    cin >> a >> b;

    string ans = "";

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            if (a[i] == b[j]){
                ans += a[i];
            }
        }
    }

    cout << ans;


    return 0;
}