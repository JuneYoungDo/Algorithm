//
// Created by June Young Do on 2022/04/06.
//
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <time.h>

using namespace std;
#define endl '\n'
#define ll long long

unordered_map<string, int> userTable, itemTable; //userId, itemId 맵핑 해시 테이블
int userCnt = 1;
int itemCnt = 1;
int totalLineCnt;                           // userId 매핑할 정수, itemId 매핑할 정수
string sLastTime;
int integerArray[3];
int tmp[3];

void read(FILE *binaryFile) {
    fseek(binaryFile, 0, SEEK_SET);
    int read[3];
    int a;
    while (!feof(binaryFile)) {
        if (fread(&a, 1, 1, binaryFile) == 0) break;
        else fseek(binaryFile, -1, SEEK_CUR);
        //파일의 끝인지 확인하기 위해 1byte만큼 읽었으므로
        //파일포인터를 다시 1byte만큼 앞으로 되돌린다.
        fread(read, sizeof(int), 3, binaryFile);
        cout << read[0] << ' ' << read[1] << ' ' << read[2] << endl;
    }
}

// lineNum번째 줄의 값을 first,second,third 로 바꾸는 함수
void editLine(FILE *matrixWrite, int lineNum, int first, int second,
              int third) {
    fseek(matrixWrite, sizeof(int) * lineNum, SEEK_SET);
    integerArray[0] = first;
    integerArray[1] = second;
    integerArray[2] = third;
    fwrite(integerArray, sizeof(int), 3, matrixWrite);
    fflush(matrixWrite);
}

// 로그 한줄 가져왔을 때 시간, 유저 id, 아이템 id 를 벡터에 담아 보내는 함수
vector<string> decomposeLog(string log) {
    vector<string> v;
    string word = "";
    log = log + ' ';
    for (int i = 0; i < log.size(); i++) {
        if (log[i] == ' ') {
            v.push_back(word);
            word = "";
        } else word += log[i];
    }
    return v;
}

// 밀리세컨드 단위의 로그 시작 시간 start 와 현재 보고있는 로그의 시간 now 를 뺐을 때 양수라면(시작 시간 이전) false, 음수 혹은 0 이면 true 반환
bool getDiffMilliseconds(ll start, ll now) {
    chrono::milliseconds startMill(start);
    chrono::milliseconds nowMill(now);
    chrono::milliseconds diffMill = startMill - nowMill;
    if (diffMill.count() > 0) return false;
    else return true;
}

// 최근 n 시간에 대해, n 시간전의 milliseconds 구하기
ll getStartMilliseconds(ll startDate, int n) {
    chrono::milliseconds lastLog(startDate);
    chrono::hours h(n);
    chrono::milliseconds firstLog = lastLog - h;
    return firstLog.count();
}

// 입력된 데이터 data 에서 시작시간에 포함되는 첫번째 로그가 몇번째 줄인지 확인(0부터 시작)
// => 정렬이 되어있으니 이분탐색으로도 가능할듯?? 지금은 선형적이지만 최적화 할때 고쳐보자
int getStartLogLineNum(fstream &data, ll startMilliseconds) {
    data.seekg(0);

    string log;
    string date = "";
    int lineNum = 0;

    while (1) {
        date = "";
        getline(data, log);
        for (int i = 0; i < log.size(); i++) {
            if (log[i] == ' ')
                break;
            date += log[i];
        }
        ll milliseconds = stoll(date);
        if (getDiffMilliseconds(startMilliseconds, milliseconds))
            break;
        else
            lineNum++;
    }
    data.seekg(lineNum * 61);
    return lineNum;
}

// 시작 로그 라인으로 커서 옮기기
int goToStartLine(fstream &data, int n) {   // 8일간은 최대 2억개의 로그가 찍힐 수 있으므로 int 로 가능
    string lastLine;                    // 가장 마지막 줄(제일 최근 로그)
    string lastTime = "";               // 가장 마지막 줄 시간 부분(제일 최근 로그 시간 부분)
    data.seekg(-61, ios::end);
    getline(data, lastLine);
    for (int i = 0; i < lastLine.size(); i++) {
        if (lastLine[i] == ' ') break;
        lastTime += lastLine[i];
    }
    sLastTime = lastTime;
    ll lastMill = stoll(lastTime);      // long long 형으로 마지막 줄 시간 부분 형변환
    ll startMill = getStartMilliseconds(lastMill, n);       // 마지막 줄 시간에서 n 시간 만큼 빼서 시작 시간을 구함
    int lineNum = getStartLogLineNum(data, startMill);  // 시작시간에서 부터 처음 찍힌 로그의 줄 번호를 구함 (0번째 부터 있음)
    return lineNum;     // 조건에 맞는 최초 시작 로그가 몇번째 줄부터인지 반환, 포인터는 해당 줄 제일 앞으로 가있음
}

// mm의 마지막 줄의 번호를 가져오는 함수
int getLastIdx(FILE *matrixRead) {
    fseek(matrixRead, sizeof(int) * -3, SEEK_END);
    fread(&integerArray, sizeof(int), 3, matrixRead);
    return integerArray[0];
}

// mm의 idx 번째 라인의 첫번째 수 혹은 두번째 수 혹은 세번째 수를 가져온다
int getIdxNum(FILE *matrixRead, int idx, int seq) {
    fseek(matrixRead, sizeof(int) * idx, SEEK_SET);
    fread(&integerArray, sizeof(int), 3, matrixRead);

    if (seq == 1) return integerArray[0];
    else if (seq == 2) return integerArray[1];
    else return integerArray[2];
}

// mm의 idx 번째 라인을 가져온다.
vector<int> getIdxLine(FILE *matrixRead, int idx) {
    fseek(matrixRead, sizeof(int) * idx, SEEK_SET);
    fread(&integerArray, sizeof(int), 3, matrixRead);
    vector<int> v;
    v.push_back(integerArray[0]);
    v.push_back(integerArray[1]);
    v.push_back(integerArray[2]);
    return v;
}

int doOneLog(FILE *matrixWrite, FILE *matrixRead, int userId, int itemId) {
    int start = 1;
    int end = getLastIdx(matrixRead);
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (getIdxNum(matrixRead, mid, 1) < userId)
            start = mid + 1;
        else end = mid - 1;
    }
    int userIdxFirst = start;       // 이분탐색(중복 가능, 중복 있다면 가장 앞에 idx 반환) 수행

    if (userId == userCnt - 1) {   // 들어가야 할 자리가 마지막 줄이면
        fseek(matrixWrite, 0, SEEK_END);         // 포인터를 mm 파일 제일 뒤로 이동
        tmp[0] = userId;
        tmp[1] = itemId;
        tmp[2] = 1;
        fwrite(tmp, sizeof(int), 3, matrixWrite);
        fflush(matrixWrite);
        totalLineCnt++;             // total Cnt 추가
        fseek(matrixWrite, 0, SEEK_SET);
        tmp[0] = userCnt - 1;
        tmp[1] = itemCnt - 1;
        tmp[2] = totalLineCnt;
        fwrite(tmp, sizeof(int), 3, matrixWrite);  // 헤더 갱신
        fflush(matrixWrite);
    } else {  // 2. 찾으려는 수가 있다 -> 시작 줄과 마지막 줄을 찾는다 시작idx와 끝idx를 찾는다 -> 시작idx와 끝idx에서 item 탐색한다 -> 여긴 중복이없음 ->  target보다 작은 가장 가까운 v의 인덱스 return
        start = 1;
        end = getLastIdx(matrixRead);
        while (start <= end) {
            mid = (start + end) / 2;
            if (getIdxNum(matrixRead, mid, 1) < userId)
                start = mid + 1;
            else end = mid - 1;
        }
        int userIdxEnd = end;       // 이분탐색(중복 가능, 중복 있다면 가장 뒤에 idx 반환) 수행

        start = userIdxFirst;       // userId의 시작 idx
        end = userIdxEnd;           // userId의 마지막 idx
        while (start <= end) {
            mid = (start + end) / 2;
            if (getIdxNum(matrixRead, mid, 2) < itemId) start = mid + 1;
            else end = mid - 1;
        }
        int findLine = end;         // itemId에 대해 이분탐색(해당 값이 없는 경우 해당 값보다 작은 가장 가까운 수 반환) 수행
        vector<int> v = getIdxLine(matrixRead, findLine);        // findLine == 찾는 줄의 idx, 해당 줄의 정보를 가져옴
        if (v[1] == itemId) {                         // itemId 부분이 같다 == userId와 itemId 가 모두 같다
            int third = v[2] + 1;                     // 3번째 값만 1 더해준다
            editLine(matrixWrite, findLine, userId, itemId, third);  // 수정
        } else {                    // itemId 부분이 다르다 == 새로운 라인이 추가되어야 한다
            //            mm.seekg(6 * findLine);             // 찾은 줄의 제일 뒤로 이동
            //            mm << '\n';                             // 한줄 내림
            //            string tmp = to_string(userId) + " " + to_string(itemId) + " " + to_string(1);
            //            mm << tmp;                              // 추가
            //            totalLineCnt++;                         // 헤더 3번 수 ++
            //            mm.seekg(0);            // 첫줄 이동 후 헤더 갱신
            //            tmp = to_string(userCnt - 1) + " " + to_string(itemCnt - 1) + " " + to_string(totalLineCnt);
            //            mm << tmp;
        }
    }
}

void mm(fstream &data) {
    FILE *matrixWrite;
    matrixWrite = fopen("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/binary_mm.txt",
                        "wb");     // 텍스트 파일로 저장되면 모두 문자취급되기 때문에
    FILE *matrixRead;                                                                                              // 바이너리 파일로 저장 후 변환
    matrixRead = fopen("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/binary_mm.txt", "rb");

    ofstream itemListPage("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/item_list_file.txt",
                          ios::app);  // 마지막 추가만 되면 되므로 그냥 ofstream 써도됨
    ofstream userListPage("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/user_list_file.txt",
                          ios::app);  // 마지막 추가만 되면 되므로 그냥 ofstream 써도됨
    fseek(matrixWrite, 0, SEEK_SET);
    int arr[3] = {0, 0, 0};
    fwrite(arr, sizeof(int), 3, matrixWrite);          // 초기 mm 헤더 0 0 0

    while (1) {
        string log;
        getline(data, log);                 // 로그 한줄 씩 가져옴
        cout << log << endl;
        vector<string> v = decomposeLog(log);   // v[0] = 시간, v[1] = userID, v[2] = itemID
        int user, item;
        if (userTable.find(v[1]) != userTable.end()) user = userTable[v[1]];    // userTable 에 값이 있다
        else {      // 없다
            userTable[v[1]] = userCnt;          // 유저 테이블에 해당 유저 아이디가 없다면 현재 번호를 할당
            user = userCnt;                     // 현재 유저 번호 또한 같음
            userCnt++;                          // 다음을 위해 ++
            userListPage << v[1] + '\n';        // 유저 리스트 페이지에 기록
        }
        if (itemTable.find(v[2]) != itemTable.end()) item = itemTable[v[2]];    // itemTable 에 값이 있다
        else {      // 없다
            itemTable[v[2]] = itemCnt;          // 아이템 테이블에 해당 아이템 아이디가 없다면 현재 번호를 할당
            item = itemCnt;                     // 현재 아이템 번호 또한 같음
            itemCnt++;                          // 다음을 위해 ++
            itemListPage << v[2] + '\n';        // 아이템 리스트 페이지에 기록
        }
        if (totalLineCnt == 0) {        // 첫 줄
            fseek(matrixWrite, sizeof(int) * 3, SEEK_SET);
            int arr[3] = {user, item, 1};
            fwrite(arr, sizeof(int), 3, matrixWrite);       // 유저아이디, 아이템 아이디, 1 입력
            totalLineCnt++;     // 전체 라인( 헤더 3번째 값 ) ++
            fseek(matrixWrite, 0, SEEK_SET);
            arr[0] = userCnt - 1;
            arr[1] = itemCnt - 1;
            arr[2] = totalLineCnt;
            fwrite(arr, sizeof(int), 3, matrixWrite);  // 헤더 갱신
            fflush(matrixWrite);
        } else {        // 첫줄이 아니라면
            doOneLog(matrixWrite, matrixRead, user, item);       // 수행
        }
        if (v[0] == sLastTime) break;
    }
    fclose(matrixWrite);
    fclose(matrixRead);
    itemListPage.close();
    userListPage.close();
}

int main(int argc, char *argv[]) {
    //    fstream fp("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/MatrixMarket_format_file.txt");     // 읽기 쓰기 모두 가능(data)
    //    fstream mm("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/MatrixMarket_format_file.txt");
    FILE *pf;

    int arr[3] = {1, 100, 99};
    int arr2[3] = {2, 23300, 99};
    int arr3[3] = {3, 1001, 992};
    int plus[6] = {2, 23300, 99, 1, 2, 3};
    int reads[3];
    pf = fopen("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/binary_mm.txt", "w+b");
    fwrite(arr, sizeof(int), 3, pf);
    fwrite(arr2, sizeof(int), 3, pf);
    fwrite(arr3, sizeof(int), 3, pf);
    fseek(pf, sizeof(int) * 3, SEEK_SET);
    //fwrite(plus, sizeof(int), 6, pf);
    fclose(pf);

    int a;
    FILE *rf;
    rf = fopen("/Users/juneyoungdo/Desktop/Algorithm/kakaobrain/binary_mm.txt", "r+b");
    fseek(rf, sizeof(int) * 3, SEEK_SET);
    //fwrite(plus, sizeof(int), 6, rf);
    read(rf);
    fclose(rf);


    //    int a, b, c;
    //    fseek(pf, 0, SEEK_SET);
    //    cout << ftell(pf) << endl;
    //    a = 101;
    //    b = 102;
    //    c = 103;
    //    fprintf(pf, "%d %d %d\n", a, b, c);         // 입력       101 102 103
    //    fflush(pf);
    //    int num;
    //
    //    cout << ftell(pf) << endl;
    //    fseek(pf, sizeof(int) * 3, SEEK_SET);       //           101 102 103
    //    fprintf(pf, "%d %d %d\n", a, b, c);
    //    fflush(pf);
    //    cout << ftell(pf) << endl;
    //    fseek(pf, sizeof(int) * 6, SEEK_SET);       //           111 112 113
    //    fprintf(pf, "%d %d %d\n", a + 10, b + 10, c + 10);
    //    fflush(pf);
    //    cout << ftell(pf) << endl;
    //    fseek(pf, sizeof(int) * 3, SEEK_SET);               // 해당 라인 수정
    //    cout << ftell(pf) << endl;
    //    int x = 100, y = 100, z = 100;
    //    cout<<x<<" "<<sizeof(x)<<endl;
    //    cout<<y<<" "<<sizeof(y)<<endl;
    //    cout<<z<<" "<<sizeof(z)<<endl;
    //
    //    fprintf(pf, "%d %d %d\n", x, y, z);
    //    fflush(pf);
    //    cout << ftell(pf) << endl;


    //    fclose(rf);
    //    fclose(pf);

    //    cout << goToStartLine(fp, 192) << endl;         // 데이터 fp 에서 최근 1시간의 기록

    //    mm(fp);


    //    mm.close();
    //    fp.close();
    return 0;
}
