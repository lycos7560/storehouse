#include <string>
#include <vector>
#include <algorithm>
#include <tuple>


using namespace std;

string DistinguishMelody(string m)
{
    string str;
    for (int i = m.length() - 1; i >= 0; i--) {
        if (m[i] == '#') {
            str.push_back(m[i - 1] + 32);
            i--;
        }
        else str.push_back(m[i]);
    }
    reverse(str.begin(), str.end());
    return str;
}

tuple<string, string, int> Slicing(string str)
{
    int startH = atoi(str.substr(0, 2).c_str());
    int endH = atoi(str.substr(6, 2).c_str());
    int startM = atoi(str.substr(3, 2).c_str());
    int endM = atoi(str.substr(9, 2).c_str());
    int resInt = (endH - startH) * 60 + (endM - startM);
    string str2 = str.substr(12, str.length() - 1);
    int pv = 0;
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == ',') {
            pv = i;
            break;
        }
    }
    string name = str2.substr(0, pv);
    string melody = DistinguishMelody(str2.substr(pv + 1, str.length() - 1));
    int cnt = melody.length();
    for (int i = melody.length(); i < resInt; i++) {
        melody.push_back(melody[i % cnt]);
    }
    melody = melody.substr(0, resInt);

    tuple<string, string, int> res = make_tuple(name, melody, resInt);
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m = DistinguishMelody(m);
    int answerlength = 0;
    for (auto &it : musicinfos) {
        tuple<string, string, int> res = Slicing(it);
        string str = get<1>(res);

        for (int i = 0; i < str.length(); i++) {
           for (int j = 0; j < m.length(); j++) {
              if (str[j + i] != m[j]) break;
              if (j == m.length() - 1) {
                  if (get<2>(res) > answerlength) {
                      answerlength = get<2>(res);
                      answer = get<0>(res);
                  }
              }
           }
        }
    }
    
    if (answerlength == 0) answer = "(None)";

    return answer;
}