//#include <iostream>
//
//using namespace std;
//
//// ��, ��, ���
//int row, column, result;
//
//// ���ĺ� �ߺ� ����
//bool isVisited[26];
//
//// �� ǥ��
//char mapArr[20][20];
//
//// �� �� �� ��
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//
//void DFS(int x, int y, int cnt) {
//
//    // ��������� ������ ���� �ٲپ� �ش�.
//    if (cnt > result)
//    {
//        result = cnt;
//    }
//
//    for (int i = 0;i < 4;i++)
//    {
//        // �� �� �� �� �������ֱ�
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        // ������ ����� ���� X
//        if (nx >= 0 && ny >= 0 && nx < column && ny < row)
//        {
//            // A - 65  �̹� �迭�� A�� �ִٸ� -65 = 0
//            // isVisited[0] �湮 ó��
//            if (isVisited[mapArr[ny][nx] - 'A'] == false)
//            {
//                isVisited[mapArr[ny][nx] - 'A'] = true;
//                DFS(nx, ny, cnt + 1);
//                isVisited[mapArr[ny][nx] - 'A'] = false;
//                // DFS�� �����鼭 �湮ó�� ����
//            }
//        }
//    }
//}
//
//int main() 
//{
//    cin >> row >> column;
//
//    for (int i = 0;i < row;i++) 
//    {
//        for (int j = 0;j < column;j++) 
//        {
//            cin >> mapArr[i][j];
//        }
//    }
//
//    // ù����
//    isVisited[mapArr[0][0] - 'A'] = true;
//
//    // DFS ����
//    DFS(0, 0, 1);
//
//    cout << result;
//
//    return 0;
//}