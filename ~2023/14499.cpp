//
// Created by June Young Do on 2022/05/11.
//
#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int n, m, x, y, k;
int my[5] = {0, 0, 0, -1, 1};
int mx[5] = {0, 1, -1, 0, 0};
int map[21][21];
int arr[1001];
vector<int> dice(6);

// 동쪽으로 굴리기
void rollEast() {
    dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
}

// 서쪽으로 굴리기
void rollWest() {
    dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
}

// 북쪽으로 굴리기
void rollNorth() {
    dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
}

// 남쪽으로 굴리기
void rollSouth() {
    dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < k; i++)
        cin >> arr[i];


    for (int i = 0; i < k; i++) {
        int ny = my[arr[i]];
        int nx = mx[arr[i]];
        if (y + ny >= n || y + ny < 0 || x + nx >= m || x + nx < 0)
            continue;
        // 주사위 위치하는 칸 이동
        y += ny;
        x += nx;
        // 명령에 따라 주사위 굴리기
        if (arr[i] == 1)rollEast();
        else if (arr[i] == 2)rollWest();
        else if (arr[i] == 3)rollNorth();
        else rollSouth();

        cout << dice[0] << '\n'; // 윗면 출력

        // 도착한 보드 칸이 0 이라면
        if (map[y][x] == 0)
            map[y][x] = dice[5]; // 주사위 아랫면 숫자를 위치한 칸에 복사
        else {
            dice[5] = map[y][x];
            map[y][x] = 0;
        }
    }

    return 0;
}
