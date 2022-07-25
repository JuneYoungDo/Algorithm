//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int N, M;
int cnt;
vector<int> knownPeople;
vector<int> partyPeople[52];
int known;

int parent[52];

int findParent(int a) {
    if (a == parent[a]) { return a; }

    parent[a] = findParent(parent[a]);
    return parent[a];
}

void unionP(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA < parentB) { parent[parentA] = parentB; }
    else { parent[parentB] = parentA; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> known;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    if (known == 0) {
        cout << M << endl;
        return 0;
    }

    for (int i = 0; i < known; i++) {
        int a;
        cin >> a;
        knownPeople.emplace_back(a);
    }

    for (int i = 1; i <= M; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            partyPeople[i].emplace_back(b);
        }
        for (int j = 1; j < a; j++) {
            unionP(partyPeople[i][0], partyPeople[i][j]);
        }
    }

    for (int i = 1; i <= M; i++) {
        bool flag = true;
        int partyParent = findParent(partyPeople[i][0]);
        for (int j = 0; j < knownPeople.size(); j++) {
            if (partyParent == findParent(knownPeople[j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
