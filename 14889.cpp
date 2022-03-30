//
// Created by June Young Do on 2022/03/29.
//

#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
#define endl '\n'

int N;
int ans = 9876564321;
int teamA, teamB;
int map[21][21];
bool team[21];

void dfs(int cnt, int nxt) {
    if (cnt == N / 2) {
        teamA = 0;
        teamB = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (team[i] == true && team[j] == true) teamA += map[i][j];
                if (team[i] == false && team[j] == false) teamB += map[i][j];
            }
        }
        //ans = min(ans, abs(teamA - teamB));
        int tmp = abs(teamA - teamB);
        if (ans > tmp)ans = tmp;

        return;
    }

    for (int i = nxt; i < N; i++) {
        team[i] = true;
        dfs(cnt + 1, i + 1);
        team[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}