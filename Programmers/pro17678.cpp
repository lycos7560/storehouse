#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

map<int, int> timeMap;


string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
	int result = 0;
	for (auto &it : timetable) {
		int ch = atoi(it.substr(0, 2).c_str());
		int cm = atoi(it.substr(3, 2).c_str());
		auto it2 = timeMap.find(ch * 100 + cm);
		if (it2 != timeMap.end()) it2->second++;
		else timeMap.insert(make_pair(ch * 100 + cm, 1));
	}

	int nTime = 900;
	auto it = timeMap.begin();

	for (int i = 0; i < n; i++) {
		int tempN = m;
		while (tempN > 0 && nTime >= it->first) {
			if (it == timeMap.end()) { break; }
			else {
				int ch = it->first / 100;
				int cm = it->first % 100;
				if (cm == 0) {
					cm = 59;
					ch--;
				}
				else cm--;
				result = ch * 100 + cm;

				it->second--;
				tempN--;
				if (it->second == 0) it++;
			}
		}

		if (tempN > 0) result = nTime;

		nTime += t;
		while (nTime % 100 >= 60) {
			nTime -= 60;
			nTime += 100;
		}
	}

	string strH, strM;
	strH = to_string(result / 100);
	if (strH.length() == 1) strH.insert(0, "0");
	strM = to_string(result % 100);
	if (strM.length() == 1) strM.insert(0, "0");

	answer = strH + ":" + strM;

    return answer;
}
