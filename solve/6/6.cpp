#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int row, col;
    vector<int> top(board.size());
    vector<int> basket;

    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (board[j][i] != 0){
                top[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < moves.size(); i++){
        row = moves[i] - 1;
        col = top[row];

        if (col < board.size()){

            if (basket.size() > 0 && basket[basket.size() - 1] == board[col][row]){
                basket.pop_back();
                answer += 2;
            }
            else
            {
                basket.push_back(board[col][row]);
            }

            top[row]++;
            board[col][row] = 0;
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> v = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> m = { 1,5,3,5,1,2,1,4 };
    cout << solution(v, m);

    return 0;
}