#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct POINT{
    int x, y;
};

int get_distance(POINT& pt1, POINT& pt2){
    return abs(pt1.x - pt2.x) + abs(pt1.y - pt2.y);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<POINT> number_pos = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 1}, {3, 2}};
    POINT left_hand = number_pos[9];
    POINT right_hand = number_pos[11];
    POINT current_point;
    int current_number;

    for (int i = 0; i < numbers.size(); i++){
        current_number = numbers[i];
        if (current_number % 3 == 2 || current_number == 0){
            current_point = current_number == 0 ? number_pos[10] : number_pos[current_number - 1];
            if (get_distance(right_hand, current_point) == get_distance(left_hand, current_point)){
                if (hand == "right"){
                    right_hand = current_point;
                    answer.push_back('R');
                }
                else{
                    left_hand = current_point;
                    answer.push_back('L');
                }
            }
            else{
                if (get_distance(right_hand, current_point) > get_distance(left_hand, current_point)){
                    left_hand = current_point;
                    answer.push_back('L');
                }
                else{
                    right_hand = current_point;
                    answer.push_back('R');
                }
            }
        }
        else{
            if (current_number % 3 == 0){
                right_hand = number_pos[current_number - 1];
                answer.push_back('R');
            }
            else {
                left_hand = number_pos[current_number - 1];
                answer.push_back('L');
            }
        }
    }

    return answer;
}

int main(){
    vector<int> v = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};

    cout << solution(v, "right");

    return 0;
}