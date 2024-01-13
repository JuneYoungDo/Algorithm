//
// Created by June Young Do on 2022/05/12.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, N;
vector<pair<int, int>> v;
vector<int> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        v.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int maxS = v[0].second;
        for (int i = 0; i < N; i++) {
            if (maxS > v[i].second) {
                ans++;
                maxS = v[i].second;
            }
        }
        answer.push_back(ans);
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] + 1 << endl;

    return 0;
}
