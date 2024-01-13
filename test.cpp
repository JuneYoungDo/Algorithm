#include<iostream>
#include <vector>
#include<map>

using namespace std;
#define endl '\n'

map<string,int> nameNum;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for (int i = 0; i < friends.size(); i++) {
        string s = friends[i];
        nameNum[s] = i;
    }

    for(int i = 0;i<gifts.size();i++) {
        string s = gifts[i];
        string from = "";
        string to = "";
        string tmp = "";
        for(int j =0;j<s.length();j++) {
            if(s[j] != ' ') {
                cout<<tmp<<endl;
                tmp+=s[j];
                cout<<tmp<<endl;
            } else {
                if( from == "") {
                    from = tmp;
                    tmp = "";
                } else {
                    to = tmp;
                    tmp = "";
                }
            }
        }


    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);




    return 0;
}