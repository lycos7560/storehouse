#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> myMap;

vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 1; i <= 26; i++) { // »çÀüÀ» ÃÊ±âÈ­
        string temp = "";
        temp.push_back('A' + i - 1);
        myMap.insert(make_pair(temp, i));
        cout << temp;
    }

    for (int j = 0; j < msg.length(); j++) { // ½ÃÀÛ ÇÇº¿
        for (int i = msg.length() - j; i >= 1; i--) { // ½½¶óÀÌ½Ì ÇÇº¿
            auto it = myMap.find(msg.substr(j, i));
            if (it != myMap.end()) {
                answer.push_back(it->second);
                if (j + i < msg.length()) 
                    myMap.insert(make_pair(msg.substr(j, i + 1), myMap.size() + 1));            
                j += it->first.length() - 1;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    string msg;
    cin >> msg;
    vector<int> res;
    res = solution(msg);
    for (auto &it : res) {
        cout << it << " ";
    }


    return 0;
}