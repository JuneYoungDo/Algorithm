//
// Created by June Young Do on 2022/03/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) return true;
    else {
        if (a.second == b.second) {
            if (a.first < b.first) return true;
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int N, M;
        int answer = 0;
        vector<pair<int, int>> v;
        bool visited[1001] = {false};

        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < M; i++) {
            for (int j = v[i].first; j <= v[i].second; j++) {
                if (visited[j] == false) {
                    visited[j] = true;
                    answer++;
                    break;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
