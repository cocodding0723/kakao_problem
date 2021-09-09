#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string dest;
    stringstream ss;

    for (int i = 0; i < s.length(); i++){
        switch(s[i]){
            case 'z':
                dest.push_back('0');
                i += 3;
                break;
            case 'o':
                dest.push_back('1');
                i += 2;
                break;
            case 't':
                if (s[i + 1] == 'w'){
                    dest.push_back('2');
                    i += 2;
                }
                else{
                    dest.push_back('3');
                    i += 4;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o'){
                    dest.push_back('4');
                    i += 3;
                }
                else {
                    dest.push_back('5');
                    i += 3;
                }
                break;
            case 's':
                if (s[i + 1] == 'i'){
                    dest.push_back('6');
                    i += 2;
                }
                else{
                    dest.push_back('7');
                    i += 4;
                }
                break;
            case 'e':
                dest.push_back('8');
                i += 4;
                break;
            case 'n':
                dest.push_back('9');
                i += 3;
                break;
            default:
                dest.push_back(s[i]);
                break;
        }
    }

    ss << dest;
    ss >> answer;

    // cout << answer;

    return answer;
}

int main(){
    solution("23four5six7");

    return 0;
}