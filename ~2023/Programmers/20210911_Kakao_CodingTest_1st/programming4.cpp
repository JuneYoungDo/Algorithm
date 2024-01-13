//
// Created by June Young Do on 2021/09/11.
//

#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int ans;
int score1;
int score2;
int restArrow;
int arr[12];
int arr2[12];
bool flag;

void sol(int i) {
    if (i == 11) {
        if (score2 - score1 > ans) {
            flag = true;
            ans = score2 - score1;
            answer.clear();
            for (int i = 0; i < 10; i++) {
                answer.push_back(arr2[10 - i]);
            }
            answer.push_back(restArrow);
        }
        return;
    }
    if (arr[i]) {
        if (restArrow >= arr[i] + 1) {
            score2 += i;
            arr2[i] = arr[i] + 1;
            restArrow -= arr2[i];
            sol(i + 1);
            score2 -= i;
            restArrow += arr2[i];
            arr2[i] = 0;
        }
        arr2[i] = 0;
        score1 += i;
        sol(i + 1);
        score1 -= i;
    } else {
        if (restArrow > 0) {
            restArrow--;
            arr2[i] = 1;
            score2 += i;
            sol(i + 1);
            restArrow++;
            score2 -= i;
        }
        arr2[i] = 0;
        sol(i + 1);
    }
}

vector<int> solution(int n, vector<int> info) {
    restArrow = n;
    for (int i = 0; i < 11; i++)
        arr[10 - i] = info[i];
    sol(10);
    if (!flag) {
        answer.push_back(-1);
    }
    return answer;
}