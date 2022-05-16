//
// Created by June Young Do on 2022/05/16.
//
#include<iostream>

using namespace std;
#define endl '\n'
#define INF 99999999

int answer;
int N, M, k;
int students[10002];
int cost[10002];

int findParent(int x) {
    if (students[x] == x) return x;
    return students[x] = findParent(students[x]);
}

void unionNode(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa != pb) {
        if (cost[pa] > cost[pb]) students[pa] = pb;
        else students[pb] = pa;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        students[i] = i;
    }
    cost[0] = INF;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unionNode(a, b);
    }
    for (int i = 1; i <= N; i++) {
        int a = findParent(i);
        if (a != findParent(0)) {
            answer += cost[a];
            unionNode(0, i);
        }
    }
    if (answer > k) cout << "Oh no" << endl;
    else cout << answer << endl;

    return 0;
}
