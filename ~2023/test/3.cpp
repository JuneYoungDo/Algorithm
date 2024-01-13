//
// Created by June Young Do on 2021/12/02.
//

#include <iostream>
#include <vector>

#define MAX 1234567890

// 문제 : 구간길이 x가 주어지고, 해당 갯수들로 순서대로 묶었을때, 최솟값들 구하고 그 최소값들 중 최대값 구하기
// 시간상 부분합으로 하면 시간초과 날거 같아서 세그먼트 트리 사용

using namespace std;

//3번

vector<int> tree, v;        // 시간초과 때문에 벡터를 함수에 넘겨주지 않고 전역변수로 사용하였다

int sgt(int idx, int st, int end) {
    if (st == end) return tree[idx] = v[st];
    int m = (st + end) / 2;
    int left = sgt(idx * 2, st, m);
    int right = sgt(idx * 2 + 1, m + 1, end);
    return tree[idx] = left <= right ? left : right;        // max()보다는 삼항연산자가 빠르다(수백만으로 갔을경우)
}

int findMin(int idx, int st, int end, int s, int e) {
    if (st > e || end < s) return MAX;
    if (st >= s && end <= e) return tree[idx];
    int m = (st + end) / 2;
    int left = findMin(idx * 2, st, m, s, e);
    int right = findMin(idx * 2 + 1, m + 1, end, s, e);
    return left <= right ? left : right;

}

int segment(int x, vector<int> space) {
    int ret = 0;
    int n = space.size();
    v.resize(n + 1);
    tree.resize(4 * n);         // 세그먼트 트리 넉넉히는 4배 곱하면 됌
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        v[i] = space[i - 1];


    sgt(1, 1, n);

    for (int i = 0; i + x <= n; i++) {
        int tmp = findMin(1, 1, n, i + 1, i + x);       // [] 이렇게 양쪽을 다 포함하기 위해 범위를 저렇게 씀
        ret = tmp > ret ? tmp : ret;
    }
    return ret;
}

int main() {
    cout << segment(1, {1, 2, 3, 1, 2});
}