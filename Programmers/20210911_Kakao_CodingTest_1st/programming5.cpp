#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer;
vector<vector<int>> edge(20);
vector<int> canGo;
bool visit[20];
int nowSheep;
int nowWolf;

bool validation(int x, vector<int> info) {
    if (visit[x]) return false;
    if (info[x] == 1) {
        if (nowSheep <= nowWolf + 1)
            return false;
    }
    return true;
}

void dfs(int x, vector<int> info) {

    visit[x] = true;

    if (info[x] == 0) {
        nowSheep++;
        if (answer < nowSheep)
            answer = nowSheep;
    } else {
        nowWolf++;
    }

    for (int i = 0; i < edge[x].size(); i++) {
        canGo.push_back(edge[x][i]);
    }
    for (int i = 0; i < canGo.size(); i++) {
        int next = canGo[i];
        if (validation(next, info)) {
            dfs(next, info);
        }
    }

    visit[x] = false;
    for (int i = 0; i < edge[x].size(); i++) {
        canGo.erase(find(canGo.begin(), canGo.end(), edge[x][i]));
    }
    if (info[x] == 0)
        nowSheep--;
    else
        nowWolf--;
}

int solution(vector<int> info, vector<vector<int>> edges) {

    for (int i = 0; i < edges.size(); i++) {
        edge[edges[i][0]].push_back(edges[i][1]);
    }

    dfs(0, info);
    return answer;
}