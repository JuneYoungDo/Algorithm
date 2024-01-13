//
// Created by June Young Do on 2021/11/04.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

int n, t, p;
int ans;
bool timeSeat[24][60][101];      // 시간 / 분/ 좌석번호
// 시작 시간, 시작 분,  끝나는 시간, 끝나는 분

struct isUsed {
    int startTime;
    int startMin;
    int endTime;
    int endMin;
};

vector<isUsed> v;

bool cmp(isUsed a, isUsed b) {
    if (a.startTime == b.startTime)
        if (a.startMin == b.startMin)
            if (a.endTime == b.endTime) return a.endMin < b.endMin;
            else return a.endTime < b.endTime;
        else return a.startMin < b.startMin;
    else return a.startTime < b.startTime;
}

int checkDist(int hour, int min, int seatNum) {
    int minD = 101;  // 좌석 최대 거리
    for (int i = 1; i <= n; i++) {
        if (i == seatNum) continue;  // 같은 자리
        if (timeSeat[hour][min][i] == true) {  // 해당 자리에 사람이 있다면
            int x = abs(seatNum - i);           // 해당 자리와의 거리 측정
            if (x < minD) minD = x;       // 최소거리 측정
        }
    }
    return minD;
}

int findSeat(int hour, int min) {
    int maxD = 0;   // 가장 멀리있는 자리의 거리
    int seatNum;    // 가장 멀리있는 자리의 번호
    for (int i = 1; i <= n; i++) {
        if (timeSeat[hour][min][i] == false) {     // 빈자리 라면
            int minD = checkDist(hour, min, i);
            if (minD > maxD) {
                maxD = minD;
                seatNum = i;
            }
        }
    }
    return seatNum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t >> p;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a / 100, a % 100, b / 100, b % 100});
    }
    sort(v.begin(), v.end(), cmp);        // 시간 순 정렬
    for (int m = 0; m < t; m++) {
        int startT = v[m].startTime;
        int startM = v[m].startMin;
        int endT = v[m].endTime;
        int endM = v[m].endMin;
        int seat = findSeat(startT, startM);

        for (int i = startT; i <= endT; i++) {
            if (startT == endT) {    // 시작시각과 끝 시각이 같은 경우
                for (int j = startM; j < endM; j++)
                    timeSeat[i][j][seat] = true;
                break;
            }
            if (i == startT)
                for (int j = startM; j < 60; j++)
                    timeSeat[i][j][seat] = true;
            else if (i == endT)
                for (int j = 0; j < endM; j++)
                    timeSeat[i][j][seat] = true;
            else
                for (int j = 0; j < 60; j++)
                    timeSeat[i][j][seat] = true;
        }
    }
    for (int i = 9; i < 21; i++) {
        for (int j = 0; j < 60; j++)
            if (timeSeat[i][j][p] == false)ans++;
    }
    cout << ans << endl;
    return 0;
}