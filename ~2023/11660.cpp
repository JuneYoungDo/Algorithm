//
// Created by June Young Do on 2022/03/28.
//

#include<iostream>

using namespace std;
#define endl '\n'

int N, M;
int prefixSum[1025][1025];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] + x - prefixSum[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        ans = prefixSum[y2][x2] - prefixSum[y2][x1 - 1] - prefixSum[y1 - 1][x2] + prefixSum[y1 - 1][x1 - 1];
        cout << ans << endl;
    }

    return 0;
}
