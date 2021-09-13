#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string solution(string new_id) {
    string answer = "";

    int append_size = 0;

    for (char& ch : new_id){
        if (ch >= 'A' && ch <= 'Z') answer += (ch | 32);
        else{
            if (ch >= '0' && ch <= '9' ||
                ch >= 'a' && ch <= 'z' ||
                strchr("-_", ch) ||
                ch == '.' && answer.back() != '.' && answer.size() > 0) answer += ch;
        }
    }

    if (answer.front() == '.') answer.erase(answer.begin());
    if (answer.back() == '.') answer.pop_back();

    if (!answer.size()) answer += 'a';
    if (answer.size() > 15) answer = answer.substr(0, 15);
    if (answer.back() == '.') answer.pop_back();

    if (answer.size() < 3) answer.append(3 - answer.size(), answer.back());

    return answer;
}

int main(){
    cout << solution("abcdefghijklmn.p.");

    return 0;
}