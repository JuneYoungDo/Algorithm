//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>

using namespace std;
#define endl '\n'

int N, H;
int top[500002];
int bottom[500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i % 2) { top[H - a + 1]++; }
        else { bottom[a]++; }
    }
    for (int i = 1; i <= H; i++) {
        bottom[H - i] += bottom[H - i + 1];
        top[i] += top[i - 1];
    }

    int ans = 987654321;
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        int num = top[i] + bottom[i];
        if (num < ans) {
            ans = num;
            cnt = 1;
        } else if (num == ans) {
            cnt++;
        }
    }

    cout << ans << ' ' << cnt << endl;


    return 0;
}
