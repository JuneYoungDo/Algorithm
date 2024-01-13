//
// Created by June Young Do on 2022/07/19.
//
#include<iostream>
#include<map>
#include<vector>

using namespace std;
#define endl '\n'

map<int, pair<int, int>> idx;
vector<int> v;
vector<int> tmp;

int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};

int mp[5][5];

void dfs(int sCnt, int yCnt, int y, int x) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 25; i++) {
        v.push_back(i);
        if (i < 7) {
            tmp.push_back(1);
        } else {
            tmp.push_back(0);
        }
    }

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            mp[i][j] = s[j];
            idx[cnt] = {i, j};
        }
    }

    vector<int> choice;
    do {
        choice.clear();
        for (int i = 0; i < 25; i++) {
            if (tmp[i] == 1) {
                choice.push_back(i);
            }
        }
    } while (prev_permutation(tmp.begin(), tmp.end()));

    return 0;
}
