#include <iostream>
#include <string>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    regex seq_dot("[\\.]+");
    regex start_dot("^[\\.]");
    regex end_dot("[\\.]$");

    int append_size = 0;

    for (int i = 0; i < new_id.size(); i++){
        if (new_id[i] >= 'A' && new_id[i] <= 'Z'){
            answer += new_id[i] + 32;
        }
        else{
            if (new_id[i] >= '0' && new_id[i] <= '9') answer += new_id[i];
            else if (new_id[i] >= 'a' && new_id[i] <= 'z') answer += new_id[i];
            else if (new_id[i] == '_' || new_id[i] == '.' || new_id[i] == '-') answer += new_id[i];
        }
    }

    answer = regex_replace(answer, seq_dot, ".");
    answer = regex_replace(answer, start_dot, "");
    answer = regex_replace(answer, end_dot, "");

    if (answer == ""){
        answer += 'a';
    }

    if (answer.size() > 15){
        answer = answer.substr(0, 15);
    }

    answer = regex_replace(answer, end_dot, "");

    if (answer.size() < 3){
        append_size = 3 - answer.size(); 
        answer.append(append_size, answer[answer.size() - 1]);
    }

    return answer;
}

int main(){
    cout << solution("abcdefghijklmn.p.");

    return 0;
}