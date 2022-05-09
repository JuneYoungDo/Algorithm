//
// Created by June Young Do on 2022/05/09.
//
#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int n;
vector<string> v;
string answer;

bool isAllSame(int startY, int startX, int endY, int endX) {
    if(startY == endY && startX == endX) return true;
    bool flag = true;
    char now = v[startY][startX];
    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            if (v[i][j] != now) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    return flag;
}

void solve(int startY, int startX, int s) {
    if (isAllSame(startY, startX, startY + s - 1, startX + s - 1)) answer += v[startY][startX];
    else {
        answer += "(";
        solve(startY, startX, s / 2);
        solve(startY, startX + s / 2, s / 2);
        solve(startY + s / 2, startX, s / 2);
        solve(startY + s / 2, startX + s / 2, s / 2);
        answer += ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    solve(0, 0, n);
    cout << answer << endl;

    return 0;
}
