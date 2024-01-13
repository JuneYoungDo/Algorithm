//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int N, M, K;
int in_degree[100002];
int isBuild[100002];
vector<int> v[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        in_degree[b]++;
    }

    bool flag = true;
    for (int i = 0; i < K; i++) {
        int mode, num;
        cin >> mode >> num;
        if (mode == 1) {
            if (in_degree[num] != 0) {
                flag = false;
                break;
            } else {
                if (isBuild[num] == 0) {
                    for (int j = 0; j < v[num].size(); j++) {
                        in_degree[v[num][j]]--;
                    }
                }
                isBuild[num]++;
            }
        } else {
            if (!isBuild[num]) {
                flag = false;
                break;
            }
            if (isBuild[num] == 1) {
                for (int j = 0; j < v[num].size(); j++) {
                    in_degree[v[num][j]]++;
                }
            }
            isBuild[num]--;
        }
    }
    if (flag) {
        cout << "King-God-Emperor" << endl;
    } else {
        cout << "Lier!" << endl;
    }

    return 0;
}
