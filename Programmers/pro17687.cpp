#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

string decimalToN(int decimalNum, int n) {
    if (decimalNum == 0) return "0";
    string str;
    while (decimalNum != 0) {
        int remainder = decimalNum % n;
        if (remainder < 10) str.push_back(remainder + 48); // ����
        else str.push_back(remainder + 55); // ���ĺ�
        decimalNum /= n;
    }
    reverse(str.begin(), str.end()); // ������
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 1;
    for (int i = 0; answer.length() <= t; i++) {
        string str = decimalToN(i, n);
        for (int j = 0; j < str.length(); j++) {
            if (cnt == p) answer.push_back(str[j]);
            cnt++;
            if (cnt == m + 1) cnt = 1;
        }
    }

    return answer.substr(0, t);
}