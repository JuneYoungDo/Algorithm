//
// Created by June Young Do on 2022/03/08.
//

#include<iostream>
#define endl '\n'
using namespace std;

int map[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            map[i][j] = 0;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x;

        for (int j = y; j < y + 10; j++)
            for (int k = x; k < x + 10; k++)
                map[j][k] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            if (map[i][j] == 1)
                cnt++;
    }

    cout << cnt << endl;

    return 0;
}