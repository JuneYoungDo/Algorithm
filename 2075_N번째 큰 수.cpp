//
// Created by June Young Do on 2022/07/11.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int N;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            pq.push(-1 * x);
            if (pq.size() > N) {
                pq.pop();
            }
        }
    }

    cout << -1 * pq.top() << endl;

    return 0;
}
