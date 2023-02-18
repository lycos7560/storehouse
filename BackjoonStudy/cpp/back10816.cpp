#include <iostream>
#include <list>

using namespace std;

int N, temp;

int arr[10000001][2];

list<int> myList;

int main()
{
   // N의 개수는 (1 ≤ N ≤ 500,000)
   ios_base::sync_with_stdio(false); // 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;
   while (N-- > 0) {
       cin >> temp;
       if (temp >= 0) { arr[temp][0]++; }
       else { arr[temp * -1][1]++; }
   }

   cin >> N;
   while (N-- > 0) {
       cin >> temp;
       myList.push_back(temp);
   }

   for (auto it = myList.begin(); it != myList.end(); it++) {
       if (*it >= 0) { cout << arr[*it][0] << " "; }
       else { cout << arr[*it * -1][1] << " "; }
   }

	return 0;
}