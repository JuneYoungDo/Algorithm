//
// Created by June Young Do on 2021/11/15.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Time {
    int start;
    int finish;
};

bool cmp(Time a, Time b) {
    if (a.finish == b.finish)
        return a.start < b.start;
    else
        return a.finish < b.finish;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Time> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i].start >> c[i].finish;
    }
    sort(c.begin(), c.end(), cmp);

    int cnt = 0;
    int result = 0;

    for (int i = 0; i < c.size(); i++) {
        if (result <= c[i].start) {
            result = c[i].finish;
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}