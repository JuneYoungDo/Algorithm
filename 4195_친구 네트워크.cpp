//
// Created by June Young Do on 2022/07/28.
//

#include<iostream>
#include<vector>
#include<map>

#define endl '\n'
using namespace std;

int T, F;
int num;
map<string, int> m;
int parent[200005];
int arrSize[200005];

int findParent(int x) {
    if (x == parent[x])return x;
    else return parent[x] = findParent(parent[x]);
}

void Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa < pb) {
        arrSize[pa] += arrSize[pb];
        arrSize[pb] = 0;
        parent[pb] = pa;
    } else {
        arrSize[pb] += arrSize[pa];
        arrSize[pa] = 0;
        parent[pa] = pb;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        m.clear();
        num = 1;
        cin >> F;

        for (int i = 1; i <= F * 2 + 1; i++) {
            parent[i] = i;
            arrSize[i] = 1;
        }

        for (int k = 0; k < F; k++) {
            string a, b;
            cin >> a >> b;
            if (m.count(a) == 0) {
                m[a] = num;
                num++;
            }

            if (m.count(b) == 0) {
                m[b] = num;
                num++;
            }

            if (findParent(m[a]) != findParent(m[b])) {
                Union(m[a], m[b]);
            }
            if (arrSize[findParent(m[a])] > arrSize[findParent(m[b])]) {
                cout << arrSize[findParent(m[a])] << endl;
            } else {
                cout << arrSize[findParent(m[b])] << endl;
            }
        }
    }
    return 0;
}
