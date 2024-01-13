//
// Created by June Young Do on 2023/08/19.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

int N;
vector<pair<int, int>> schedule;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int begin, end;
    for (int i = 0; i < N; i++) {
        cin >> begin >> end;
        schedule.emplace_back(end, begin);
    }

    sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int answer = 1;
    for (int i = 1; i < N; i++) {
        if (time <= schedule[i].second) {
            answer++;
            time = schedule[i].first;
        }
    }
    cout << answer << endl;

    return 0;
}