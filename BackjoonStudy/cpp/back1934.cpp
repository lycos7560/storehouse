#include <iostream>

using namespace std;

int T, A, B, temp, maxA, minB;

// 유클리드 알고리즘
// 최대공약수
int gcd(int a, int b)
{
   int c;
   while (b) {
       c = a % b;
       a = b;
       b = c;
   }
   return a;
}

// 최소공배수
// 두 수 A,B를 곱한 값을 최대공약수로 나눈 값이다.
int lcm(int a, int b) {

   return (a * b) / gcd(a, b);
}

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   std::cout.tie(NULL);

   cin >> T;

   while (T--) {
       cin >> A >> B;
       cout << lcm(A, B) << "\n";
   }

   return 0;
}