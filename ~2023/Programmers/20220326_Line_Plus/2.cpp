#include <string>
#include <vector>

using namespace std;

int solution(vector<string> sentences, int n) {
    int answer = -1;

    for (int i = 0; i < sentences.size(); i++) {
        bool used[140] = {false};
        for (int j = 0; j < sentences[i].size(); j++) {
            if (sentences[i][j] >= 97)
                used[0] = true;
            break;
        }
        for (int j = 0; j < sentences[i].size(); j++) {
            int x = (int) sentences[i][j];
            if (x >= 97) x = x - 32;
            if (used[x])continue;
            else used[x] = true;
        }
        int tmp = 0;
        for(int i=0;i<140;i++) {
            if(used[i])tmp++;
        }
        if(tmp <= n) {

        }
    }

    return answer;
}