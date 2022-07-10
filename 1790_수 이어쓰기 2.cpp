//
// Created by June Young Do on 2022/07/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long
#define endl '\n'

int N, k;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> k;

    int cntN = 1;
    ll sumN = 9;
    while (1) {
        if (k <= sumN) {
            break;
        } else {
            cntN++;
            sumN += 9 * cntN * pow(10, cntN - 1);
        }
    }
    for (int i = 1; i < cntN; i++) {
        k -= (9 * i * pow(10, i - 1));
    }

    int seq = k / cntN;
    int seq2 = k % cntN;

    int num = pow(10, cntN - 1) + seq - 1;
    if (N < num) {
        ans = -1;
    } else {
        string tmp = "";
        if (seq2 == 0) {
            tmp = to_string(num);
            ans = tmp[tmp.size() - 1] - '0';
        } else {
            num += 1;
            if (N < num) {
                ans = -1;
            } else {
                tmp = to_string(num);
                ans = tmp[seq2 - 1] - '0';
            }
        }
    }
    cout << ans << endl;
    return 0;
}
