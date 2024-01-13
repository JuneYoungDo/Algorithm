//
// Created by June Young Do on 2022/07/10.
//

#include<iostream>

using namespace std;
#define endl '\n'
#define INF 987654321

int N;
int num[12];
int opt[5];
int minAns = INF;
int maxAns = -INF;

void printAns() {
    cout << maxAns << endl;
    cout << minAns << endl;
}

void getAns(int x) {
    if (minAns > x) {
        minAns = x;
    }
    if (x > maxAns) {
        maxAns = x;
    }
}

void dfs(int plus, int minus, int multi, int div, int result, int cnt) {
    if (cnt == N) {
        getAns(result);
    }
    if (plus > 0) {
        dfs(plus - 1, minus, multi, div, result + num[cnt], cnt + 1);
    }
    if (minus > 0) {
        dfs(plus, minus - 1, multi, div, result - num[cnt], cnt + 1);
    }
    if (multi > 0) {
        dfs(plus, minus, multi - 1, div, result * num[cnt], cnt + 1);
    }
    if (div > 0) {
        dfs(plus, minus, multi, div - 1, result / num[cnt], cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> opt[i];
    }
    dfs(opt[0], opt[1], opt[2], opt[3], num[0], 1);

    printAns();

    return 0;
}