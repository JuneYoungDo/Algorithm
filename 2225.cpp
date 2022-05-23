//
// Created by June Young Do on 2022/05/23.
//

#include<iostream>
using namespace std;
#define endl '\n'
#define MOD 1000000000
#define ll long long

int N, K;
ll DP[201][201];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int m = 0; m <= j; m++) {
                DP[i][j] = DP[i][j] + DP[i - 1][m];
            }
            DP[i][j] = DP[i][j] % MOD;
        }
    }

    cout << DP[K][N] << endl;

    return 0;
}
