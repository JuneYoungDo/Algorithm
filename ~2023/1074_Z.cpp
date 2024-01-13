//
// Created by June Young Do on 2023/10/13.
//

#include<iostream>

using namespace std;
#define endl '\n'

int n, r, c;
int answer;

void solve(int y, int x, int size) {
    if (y == r && x == c) {
        cout << answer << endl;
        return;
    }
    if (r < y + size && r >= y && c < x + size && c >= x) {
        solve(y, x, size / 2);
        solve(y, x + size / 2, size / 2);
        solve(y + size / 2, x, size / 2);
        solve(y + size / 2, x + size / 2, size / 2);
    } else {
        answer += size * size;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    solve(0,0,1<<n);

    return 0;
}