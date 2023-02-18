#include <iostream>
#include <list>

using namespace std;

// T : 테스트 케이스의 수, H : 호텔의 층 수(높이), 
// W : 각 층의 방 수(너비), N : 몇 번째 손님
int T, H, W, N, temp, temp2;

list<int> myList;

int main()
{
	cin >> T;
	while (T-- > 0) {

		cin >> H >> W >> N;


		temp = N % H;
		// 21번쨰 % 4층 = 1층을 사용 
		// 
		// 나머지가 없다는 뜻은 최고 높이와 같은 층을 쓴다.

		if (temp == 0) { 
			temp = H; 
			temp2 = (N / H);
		}
		else { 
			// 나머지가 있다면 최고층을 넘었다는 뜻이므로 호수 + 1
			temp2 = (N / H) + 1;
		}

		myList.push_back((temp * 100) + temp2); // 층수 * 100 + 호수
	}
	
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}