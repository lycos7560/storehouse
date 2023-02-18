#include <iostream>

using namespace std;

int T, A, B, temp, maxA, minB;

// ��Ŭ���� �˰���
// �ִ�����
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

// �ּҰ����
// �� �� A,B�� ���� ���� �ִ������� ���� ���̴�.
int lcm(int a, int b) {

   return (a * b) / gcd(a, b);
}

int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   std::cout.tie(NULL);

   cin >> T;

   while (T--) {
       cin >> A >> B;
       cout << lcm(A, B) << "\n";
   }

   return 0;
}