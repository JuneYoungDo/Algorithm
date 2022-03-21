#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

priority_queue<long long,vector<long long>, greater<long long >> wish;
long long m, n, sum;

void input() {
    cin >> m >> n;
    int x;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        wish.push(x);
        sum += x;
    }
}

void Ans() {
    long long left = sum - m;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (left ==0) break;
        long long tmp = 0;
        if (wish.top() >= left / (n - i)) tmp = left / (n - i);
        else tmp = wish.top();
        ans += tmp*tmp;
        left = left -tmp;
        wish.pop();
    }
    cout << ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    input();
    Ans();


}