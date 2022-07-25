//
// Created by June Young Do on 2022/07/23.
//
#include<iostream>

using namespace std;
#define endl '\n'

struct shark {
    int s, d, z;
};

int R, C, M;
int ans;
shark mp[103][103];
shark tmp[103][103];

int my[5] = {0, -1, 1, 0, 0};
int mx[5] = {0, 0, 0, 1, -1};

void move(int y, int x, int type, int speed, bool used) {
    // used 가 0이면 mp -> tmp
    int normalMoveY = my[type];
    int normalMoveX = mx[type];

    int reverseMoveY;
    int reverseMoveX;
    if (type == 1 || type == 3) {
        reverseMoveY = my[type + 1];
        reverseMoveX = mx[type + 1];
    } else {
        reverseMoveY = my[type - 1];
        reverseMoveX = mx[type - 1];
    }

    bool change = false;
    int ny = y;
    int nx = x;
    int realMove;
    if (type == 1 || type == 2) {
        realMove = speed % ((R - 1) * 2);
    } else {
        realMove = speed % ((C - 1) * 2);
    }
    for (int i = 0; i < realMove; i++) {
        if (!change) {
            ny += normalMoveY;
            nx += normalMoveX;
            if (ny < 1 || nx < 1 || ny > R || nx > C) {
                ny -= normalMoveY;
                nx -= normalMoveX;
                ny += reverseMoveY;
                nx += reverseMoveX;
                change = true;
            }
        } else {
            ny += reverseMoveY;
            nx += reverseMoveX;
            if (ny < 1 || nx < 1 || ny > R || nx > C) {
                ny -= reverseMoveY;
                nx -= reverseMoveX;
                ny += normalMoveY;
                nx += normalMoveX;
                change = false;
            }
        }
    }
    if (!used) {
        if (change) {
            if (type == 1 || type == 3) {
                tmp[y][x].d = type + 1;
            } else {
                tmp[y][x].d = type - 1;
            }
        }
        // tmp -> mp
        if (mp[ny][nx].d != 0) {
            if (mp[ny][nx].z > tmp[y][x].z) {
                tmp[y][x].d = 0;
            } else {
                mp[ny][nx] = tmp[y][x];
                tmp[y][x].d = 0;
            }
        } else {
            mp[ny][nx] = tmp[y][x];
            tmp[y][x].d = 0;
        }
    } else {
        if (change) {
            if (type == 1 || type == 3) {
                mp[y][x].d = type + 1;
            } else {
                mp[y][x].d = type - 1;
            }
        }
        if (tmp[ny][nx].d != 0) {
            if (tmp[ny][nx].z > mp[y][x].z) {
                mp[y][x].d = 0;
            } else {
                tmp[ny][nx] = mp[y][x];
                mp[y][x].d = 0;
            }
        } else {
            tmp[ny][nx] = mp[y][x];
            mp[y][x].d = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        shark s = {c, d, e};
        mp[a][b] = s;
    }

    bool flag = true;
    for (int king = 1; king <= C; king++) {
        // king은 x좌표를 뜻함
        // 잡을 수 있으면 한마리 잡음
        for (int i = 1; i <= R; i++) {
            if (mp[i][king].d != 0 || tmp[i][king].d != 0) {
                if (mp[i][king].d != 0) {
                    ans += mp[i][king].z;
                    mp[i][king].d = 0;
                    break;
                } else {
                    ans += tmp[i][king].z;
                    tmp[i][king].d = 0;
                    break;
                }
            }
        }

        // 상어 이동
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                // 상어가 있으면 새로운 지도로 상어들을 옮긴다 -> 같은 지점이 있으면 먹히는거 처리해 준다 -> bool 하나 써서 mp인지 tmp 인지 확인한다
                if (flag) {
                    if (mp[i][j].d != 0) {
                        move(i, j, mp[i][j].d, mp[i][j].s, flag);
                    }
                } else {
                    if (tmp[i][j].d != 0) {
                        move(i, j, tmp[i][j].d, tmp[i][j].s, flag);
                    }
                }
            }
        }
        if (flag) { flag = false; }
        else { flag = true; }
    }

    cout << ans << endl;

    return 0;
}
