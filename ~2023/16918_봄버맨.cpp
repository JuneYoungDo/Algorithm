//
// Created by June Young Do on 2022/08/01.
//
#include<iostream>
#include<cstring>

using namespace std;
#define endl '\n'

int R, C, N;
int mp[202][202];
int visit[202][202];
int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};

void print() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == 'O') {
                mp[i][j] = 2;
            } else {
                mp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N - 1; i++) {
        memset(visit, 0, sizeof(visit));
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                if (visit[j][k] == 2) { continue; }
                if (mp[j][k] == 2) {
                    mp[j][k] = 1;
                    visit[j][k] = 1;
                } else if (mp[j][k] == 1) {
                    mp[j][k] = 0;
                    visit[j][k] = 2;
                    for (int m = 0; m < 4; m++) {
                        int ny = j + my[m];
                        int nx = k + mx[m];
                        if (visit[ny][nx] == 2) { continue; }
                        if (ny < 0 || nx < 0 || ny >= R || nx >= C) { continue; }
                        if (mp[ny][nx] == 1 && visit[ny][nx] == 0) { continue; }
                        mp[ny][nx] = 0;
                        visit[ny][nx] = 2;
                    }
                } else if (mp[j][k] == 0) {
                    mp[j][k] = 3;
                } else {
                    mp[j][k]--;
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mp[i][j] == 0) {
                cout << ".";
            } else {
                cout << "O";
            }
        }
        cout << endl;
    }

    return 0;
}
