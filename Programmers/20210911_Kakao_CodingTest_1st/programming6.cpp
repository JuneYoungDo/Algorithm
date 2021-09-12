//
// Created by June Young Do on 2021/09/11.
//

#include <string>
#include <vector>
using namespace std;

int map[102][102];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n =board.size();
    int m = board[0].size();

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            map[i][j] = board[i][j];
        }
    }

    for(int i=0;i<skill.size();i++) {
        vector<int> k = skill[i];
        int kill = k[0];
        int startY = k[1];
        int startX = k[2];
        int endY = k[3];
        int endX = k[4];
        int cost = k[5];
        if( kill == 1) {
            for(int j=startY;j<=endY;j++) {
                for(int t = startX;t<=endX;t++) {
                    map[j][t] -=cost;
                }
            }
        }
        else {
            for(int j=startY;j<=endY;j++) {
                for(int t = startX;t<=endX;t++) {
                    map[j][t] +=cost;
                }
            }

        }
    }
    for(int a=0;a<n;a++)    {
        for(int b=0;b<m;b++)
            if(map[a][b]>0)
                answer++;
    }
    return answer;
}