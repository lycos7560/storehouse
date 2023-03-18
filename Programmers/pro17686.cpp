#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<string, int, int>> sliceVector;
// 원본의 순서, Head, number, tail, originNum

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b) {
	if (get<0>(a) == get<0>(b)) {
		if (get<1>(a) == get<1>(b)) {
			return get<2>(a) < get<2>(b);
		}
		return get<1>(a) < get<1>(b);
	}
	return get<0>(a) < get<0>(b);
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	int cnt = 0, number = 0;
	for (auto& it : files) {
		string head = "", numStr = "";
		int pivot = 0;
		for (int i = 0; i < it.length(); i++) {
			if (it[i] >= 48 && it[i] <= 57) {
				head = it.substr(pivot, i);
				for (auto& ch : head) ch = toupper(ch); // 전부 대문자로 변환
				pivot = i;
				break;
			}
		}
		for (int i = 0; i < 5; pivot++) {
			if (it[pivot] >= 48 && it[pivot] <= 57) {
				numStr.push_back(it[pivot]);
				continue;
			}
			number = atoi(numStr.c_str());
			break;
		}

		sliceVector.push_back(make_tuple(head, number, cnt));
		cnt++;
	}

	sort(sliceVector.begin(), sliceVector.end(), cmp);
	for (auto& it : sliceVector) answer.push_back(files[get<2>(it)]);
	
	return answer;
}