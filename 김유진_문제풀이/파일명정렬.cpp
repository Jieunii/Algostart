#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    string name;
    string hd;
    int num;
    int idx;
};

vector<info> v;

bool isNum(char c) {
    if ('0' <= c && c <= '9') return true;
    else return false;
}

bool cmp(info a, info b) {
    if (a.hd != b.hd)
        //hd ���� �������� ����
        return a.hd < b.hd;
    else if(a.num != b.num){
        //num ���� �������� ����
        return a.num < b.num;
    }
    else {
        //idx ���� �������� ����
        return a.idx < b.idx;
    }

}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {
        string tmp, head = "";
        int number = 0;

        //HEAD, NUMBER �ڸ���
        for (int j = 0; j < files[i].size(); j++) {
            if (isNum(files[i][j])) {
                tmp = files[i].substr(0, j);
                //���ڿ��� ��� �빮�ڷκ���
                for (int z = 0; z < tmp.size(); z++) {
                    head += toupper(tmp[z]);
                }
                int flag = 0;
                for (int k = j; k < j + 5; k++) {
                    if (!isNum(files[i][k])) {
                        flag = 1;
                        number = stoi(files[i].substr(j, k - j));
                        break;
                    }
                }
                if (flag == 0) number = stoi(files[i].substr(j, 5));
                break;
            }
        }
        v.push_back({ files[i], head, number,i });
    }

    //sorting
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].name);
    }

    return answer;
}
