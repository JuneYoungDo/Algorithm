//
// Created by June Young Do on 2022/03/30.
//
#include<iostream>

using namespace std;
#define endl '\n'

int n, m;
int parent[201];

int findParent(int a) {
    if (a == parent[a]) return a;

    parent[a] = findParent(parent[a]);
    return parent[a];
}

void unionP(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA < parentB) parent[parentA] = parentB;
    else parent[parentB] = parentA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 201; i++) {
        parent[i] = i;
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            if (x == 1)unionP(i, j);
        }
    }
    int root;
    bool flag = true;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (i == 0) root = findParent(x);
        else {
            if (root != findParent(x)) {
                flag = false;
                break;
            }
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
$