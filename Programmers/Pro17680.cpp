#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<string> myDeque;

int solution(int cacheSize, vector<string> cities) {

	int answer = 0;

	for (auto &it : cities) { // 전부 대문자로 변경
		for (int i = 0; i < it.length(); i++) {
			it[i] = toupper(it[i]);
		}
	}

	for (auto &it : cities) {

		bool check = false; // cache hit
		int index = 0; // 인덱스 확인용

		for (auto &it2 : myDeque) {		

			if (it2 == it) {

				check = true; // cache hit
				answer += 1;

				myDeque.erase(myDeque.begin() + index);

				break;
			}

			index++;
		}

		if (!check) { // cache miss

			myDeque.push_back(it);
			 
			if (myDeque.size() != 0 && myDeque.size() > cacheSize) myDeque.pop_front();

			answer += 5;
		}
		else myDeque.push_back(it);
		
	}

    return answer;

}



