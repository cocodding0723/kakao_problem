#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

vector<string> solution(vector<string> v){
    vector<string> result;
    
    map<string, string> user_data;
    vector<pair<string, string>> command;

    string cmd, id, nickname, order;

    for (int i = 0; i < v.size(); i++){
        istringstream ss(v[i]);
        ss >> cmd >> id >> nickname;

        if (cmd == "Leave"){
            command.push_back(make_pair(cmd, id));
        }
        else if (cmd == "Enter"){
            if (user_data.find(id) != user_data.end()){
                user_data[id] = nickname;
            }
            else{
                user_data.insert(make_pair(id, nickname));
            }
            command.push_back(make_pair(cmd, id));
        }
        else if (cmd == "Change"){
            user_data[id] = nickname;
        }
    }

    for (int i = 0; i < command.size(); i++){
        if (command[i].first == "Enter"){
            order = user_data[command[i].second] + "님이 들어왔습니다.";
        }
        else if (command[i].first == "Leave"){
            order = user_data[command[i].second] + "님이 나갔습니다.";
        }

        result.push_back(order);
    }

    return result;
}

int main(){
    vector<string> ans = solution(record);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}