#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int Max = 17;

bool map[Max][Max];

string decimalToBinary(int decimalNum, int n) { // 2진수로 변환
    if (decimalNum == 0) return "0";
    string str;
    while (decimalNum != 0) {
        int remainder = decimalNum % 2;
        if (remainder < 10) str.push_back(remainder + 48); // 숫자
        else str.push_back(remainder + 55); // 알파벳
        decimalNum /= 2;
    }

    while (str.length() != n) str.push_back('0'); // 빈 공간 채우기
    
    reverse(str.begin(), str.end()); // 뒤집기
    return str;
}

void MarkingMap(vector<int> arr, int n)
{
    int cnt = 0;
    for (auto& it : arr) {
        string str = decimalToBinary(it, n);
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') map[cnt][i] = true;
        }
        cnt++;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    MarkingMap(arr1, n);
    MarkingMap(arr2, n);
   for (int i = 0; i < n; i++) {
       string str = "";
       for (int j = 0; j < n; j++) {
           if (map[i][j] == true) str.push_back('#');
           else str.push_back(' ');
       }
       answer.push_back(str);
   }
    return answer;
}