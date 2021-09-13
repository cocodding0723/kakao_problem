#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool is_correct_string(string str){
    bool result = true;
    stack<char> s;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '(') s.push(str[i]);
        else{
            if (s.size() > 0) s.pop();
        }
    }

    if (s.size() > 0) result = false;

    return result;
}

pair<string, string> divide(string str){
    pair<string, string> p;

    stack<char> s;
    queue<char> q;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '(') s.push(str[i]);
        else q.push(str[i]);

        if (s.size() > 0 && q.size() > 0 ){
            if (s.top() != q.front()){
                s.pop();
                q.pop();
            }
        }

        if (s.size() == q.size()){
            if (i == str.size() - 1){
                p.first = str;
                p.second = "";
                break;
            }
            else{
                p.first = str.substr(0, i + 1);
                p.second = str.substr(i + 1, str.size());
                break;
            }
        }
    }

    return p;
}

string solution(string p) {
    string answer = "";

    pair<string, string> uv = divide(p);

    if (p == "") return "";

    if (is_correct_string(uv.first)){
        answer.append(uv.first + solution(uv.second));
    }   
    else{
        answer.push_back('(');
        answer.append(solution(uv.second));
        answer.push_back(')');

        uv.first.erase(uv.first.begin());
        uv.first.erase(uv.first.end() - 1);

        for (int i = 0; i < uv.first.size(); i++){
            if (uv.first[i] == '(') uv.first[i] = ')';
            else uv.first[i] = '(';
        }

        answer.append(uv.first);
    }

    return answer;
}

int main(){
    cout << solution("()))((()");

    return 0;
}