#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int size_of_current_area = 0;

    bool visit[100][100] = { 0 };
    stack<pair<int, int>> s;

    for (int i = 0; i < picture.size(); i++){
        for (int j = 0; j < picture[0].size(); j++){
            if (!visit[i][j] && picture[i][j] != 0){
                size_of_current_area = 0;

                s.push(make_pair(i, j));

                number_of_area++;

                while(s.size() != 0){
                    pair<int, int> pos = s.top();
                    s.pop();

                    if (!visit[pos.first][pos.second] && picture[i][j] == picture[pos.first][pos.second]){
                        visit[pos.first][pos.second] = true;
                        size_of_current_area++;

                        if (pos.first - 1 > -1) s.push(make_pair(pos.first - 1, pos.second));
                        if (pos.first + 1 < picture.size()) s.push(make_pair(pos.first + 1, pos.second));
                        if (pos.second - 1 > - 1) s.push(make_pair(pos.first, pos.second - 1));
                        if (pos.second + 1 < picture[0].size()) s.push(make_pair(pos.first, pos.second + 1));
                    }
                }

                max_size_of_one_area = max(max_size_of_one_area, size_of_current_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

    vector<int> ans = solution(6, 4, picture);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}