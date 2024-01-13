//
// Created by June Young Do on 2022/07/18.
//
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'
#define ll long long

int N, M;
map<string, int> nameIdx;
ll value[201];
vector<int> v[201];
int in_degree[201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string s;
    cin >> s;
    nameIdx[s] = 0;
    value[nameIdx[s]] = pow(2, 50);

    int idx = 1;
    for (int i = 0; i < N; i++) {
        string child, par1, par2;
        cin >> child >> par1 >> par2;

        int childIdx, idx1, idx2;
        if (nameIdx.count(par1)) {
            idx1 = nameIdx[par1];
        } else {
            nameIdx[par1] = idx;
            idx1 = idx;
            idx++;
        }
        if (nameIdx.count(par2)) {
            idx2 = nameIdx[par2];
        } else {
            nameIdx[par2] = idx;
            idx2 = idx;
            idx++;
        }
        if (nameIdx.count(child)) {
            childIdx = nameIdx[child];
        } else {
            nameIdx[child] = idx;
            childIdx = idx;
            idx++;
        }

        v[idx1].push_back(childIdx);
        v[idx2].push_back(childIdx);
        in_degree[childIdx] += 2;
    }
    queue<int> q;
    for (int i = 0; i < idx; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            value[next] += value[now] / 2;
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    string ans = "";
    ll maxNum = 0;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (!nameIdx.count(name)) { continue; }
        int ansIdx = nameIdx[name];
        if (value[ansIdx] > maxNum) {
            ans = name;
            maxNum = value[ansIdx];
        }
    }

    cout << ans << endl;

    return 0;
}
