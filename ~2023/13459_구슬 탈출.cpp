//
// Created by June Young Do on 2022/07/18.
//
#include<iostream>

using namespace std;
#define endl '\n'

int N, M;
int blueY, blueX;
int redY, redX;
bool ans;
char pool[11][11];

int my[4] = {0, 0, -1, 1};  // 오 왼 위 아래
int mx[4] = {1, -1, 0, 0};

void dfs(int cnt, int by, int bx, int ry, int rx) {
    if (cnt == 0) { return; }
    if (ans == true) { return; }
    for (int i = 0; i < 4; i++) {
        int originalBy = by;
        int originalBx = bx;
        int originalRy = ry;
        int originalRx = rx;

        int nowBy = by;
        int nowBx = bx;
        int nowRy = ry;
        int nowRx = rx;
        bool blue = false, red = false;
        while (1) {
            int nextBy = nowBy + my[i];
            int nextBx = nowBx + mx[i];
            if (pool[nextBy][nextBx] == '#') { break; }
            if (pool[nextBy][nextBx] == 'O') {
                blue = true;
                nowBy += my[i];
                nowBx += mx[i];
                break;
            }
            nowBy += my[i];
            nowBx += mx[i];
        }
        while (1) {
            int nextRy = nowRy + my[i];
            int nextRx = nowRx + mx[i];
            if (pool[nextRy][nextRx] == '#') { break; }
            if (pool[nextRy][nextRx] == 'O') {
                red = true;
                nowRy += my[i];
                nowRx += mx[i];
                break;
            }
            nowRy += my[i];
            nowRx += mx[i];
        }
        if (blue) { continue; }
        if (red) {
            ans = true;
            return;
        }
        // 구슬위치
        // 파랑빨강  빨강파랑
        //  빨       파
        //  파       빨
        if (nowRy == nowBy && nowRx == nowBx) {
            if (i == 0 && originalBx > originalRx) { // 오른쪽으로 굴릴때 파랑구슬이 더 오른쪽에 있다 -> 빨간구슬이 한칸 왼쪽으로 가야한다
                nowRx -= 1;
            } else if (i == 0 && originalBx < originalRx) {
                nowBx -= 1;
            } else if (i == 1 && originalBx > originalRx) { // 왼쪽으로 굴릴 때 파란구슬이 더 오른쪽에 있따 -> 파란 구슬이 한칸 오른쪽으로 가야한다
                nowBx += 1;
            } else if (i == 1 && originalBx < originalRx) {
                nowRx += 1;
            } else if (i == 2 && originalBy > originalRy) { // 위쪽으로 굴릴 때 파란구슬이 더 아래쪽에 있따 -> 파란 구슬이 한칸 아래쪽으로 가야한다
                nowBy += 1;
            } else if (i == 2 && originalBy < originalRy) {
                nowRy += 1;
            } else if (i == 3 && originalBy > originalRy) { // 아래쪽으로 굴릴 때 파란구슬이 더 아래쪽에 있따 -> 빨간 구슬이 한칸 위쪽으로 가야한다
                nowRy -= 1;
            } else if (i == 3 && originalBy < originalRy) {
                nowBy -= 1;
            }
        }
        dfs(cnt - 1, nowBy, nowBx, nowRy, nowRx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            pool[i][j] = s[j];
            if (pool[i][j] == 'B') {
                blueY = i;
                blueX = j;
            }
            if (pool[i][j] == 'R') {
                redY = i;
                redX = j;
            }
        }
    }

    dfs(10, blueY, blueX, redY, redX);

    cout << ans << endl;

    return 0;
}
