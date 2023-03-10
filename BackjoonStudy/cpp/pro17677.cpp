//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//unordered_map<string, int> mMap1;
//unordered_map<string, int> mMap2;
//unordered_map<string, int> uMap;
//
//int solution(string str1, string str2) {
//    int answer = 0;
//    string tempstr1, tempstr2;
//
//    // 대문자를 소문자로 변환
//    for (int i = 0; i < str1.length(); i++) {
//        if (str1[i] >= 'A' && str1[i] <= 'Z') {
//            str1[i] = tolower(str1[i]);
//            tempstr1.push_back(str1[i]);
//        }
//        else if (str1[i] >= 'a' && str1[i] <= 'z') tempstr1.push_back(str1[i]);
//        else tempstr1.push_back(' ');
//    }
//
//    for (int i = 0; i < tempstr1.length() - 1; i++) {
//        string temp = tempstr1.substr(i, 2);
//        if (temp[0] == ' ' || temp[1] == ' ') continue;
//        auto it = mMap1.find(temp);
//        if (it != mMap1.end()) mMap1.find(temp)->second++;
//        else mMap1.insert(make_pair(temp, 1));
//        
//    }
//
//    // 대문자를 소문자로 변환
//    for (int i = 0; i < str2.length(); i++) {
//        if (str2[i] >= 'A' && str2[i] <= 'Z') {
//            str2[i] = tolower(str2[i]);
//            tempstr2.push_back(str2[i]);
//        }
//        else if (str2[i] >= 'a' && str2[i] <= 'z') tempstr2.push_back(str2[i]);
//        else tempstr2.push_back(' ');
//    }
//
//    for (int i = 0; i < tempstr2.length() - 1; i++) {
//        string temp = tempstr2.substr(i, 2);
//        if (temp[0] == ' ' || temp[1] == ' ') continue;
//        auto it = mMap2.find(temp);
//        if (it != mMap2.end()) mMap2.find(temp)->second++;
//        else mMap2.insert(make_pair(temp, 1));
//
//    }
//
//    float Union = 0, intersection = 0;
//
//    for (auto &it : mMap1) {
//
//        auto it2 = mMap2.find(it.first);
//
//        if (it2 != mMap2.end()) intersection += min(it.second, it2->second);
//        
//        uMap.insert(make_pair(it.first, it.second));
//    }
//
//    for (auto& it : mMap2) {
//
//        auto it2 = mMap1.find(it.first);
//
//        if (it2 != mMap1.end()) it.second = max(it.second, it2->second);
//
//        if (uMap.find(it.first) != uMap.end()) uMap.find(it.first)->second = max(uMap.find(it.first)->second, it.second);
//        else uMap.insert(make_pair(it.first, it.second));
//
//    }
//
//    for (auto& it : uMap) Union += it.second;
//    
//    if (mMap1.size() || mMap2.size()) answer = (intersection / Union) * 65536;
//    else answer = 1 * 65536;
//
//    return answer;
//}
