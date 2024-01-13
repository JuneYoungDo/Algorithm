//
// Created by June Young Do on 2021/12/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//5번

//문제 : 간격의 시작 a와 끝 b가 주어짐, 해당 시작점에서 가장 작은 값과 끝점에서 가장 큰값을 하나의 구간으로 잡고, 부분들을 적용하였을 때 띄워지는 부분이 있으면 구간이 나누어 지는것으로 판단
// 예를 들어 (1,2) (2,3) (1,5) 에서 최종 구간은 1~5 여기서 1~5는 모두 이어져 있어서 하나의 구간
// (1,2) (3,4) 는 최종구간 1~4 그러나 2~3이 떨어져있기 때문에 총 2개의 구간임
// 길이 k짜리의 선 하나를 임의로 추가할 수 있을 때 구간의 갯수가 최소일 떄를 구하여라

vector<pair<int, int>> v;

int minimumDivision(vector<int> a, vector<int> b, int k) {
    vector<int> st, end;
    for (int i = 0; i < a.size(); i++) {
        v.emplace_back(a[i], b[i]);     // 객체를 집어넣을 때 emplace를 쓰면 메모리적으로 빠르다
    }
    sort(v.begin(), v.end());
    int e = v[0].second;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first > e) { //연결이 안되는 경우      // 끝나는 점과 다음 구간의 시작점 비교했을 때 다음 시작점이 더 멀리 있으면 그 부분은 떨어져있는 것!
            st.push_back(e);
            end.push_back(v[i].first);
            e = v[i].second;                    // 떨어져 있으면 떨어져있는 구간 저장해주고 ,갱신
        } else {
            e = e > v[i].second ? e : v[i].second;      // 떨어져 있지 않아도 앞선 부분이 뒷부분을 포함 할 수 있음 (1-5) (2-3) 같은경우!, 따라서 더 큰거 넣어줌
        }
    }
    int max_cnt = 0; //segment 하나를 추가해 연결 가능한 끊어진 구간의 개수
    for (int i = 0; i < st.size(); i++) {
        int max_end = st[i] + k;
        int upper = upper_bound(end.begin(), end.end(), max_end) - end.begin();
        int cnt = upper - i;
        max_cnt = max_cnt > cnt ? max_cnt : cnt;
    }
    return st.size() - max_cnt + 1;     // 끊어진 구간이 2개면 총 구간은 3개이기 때문에 +1
}