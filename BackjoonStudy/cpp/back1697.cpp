#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;
#define MAX 100001
int N, K;
bool visited[MAX];
int path[MAX];

void Init()
{
    cin >> N >> K;
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

int BFS(int N, int K)
{
    queue<int> myQueue;
    path[N] = 0;
    visited[N] = true;
    myQueue.push(N);

    while (!myQueue.empty())
    {
        int pos = myQueue.front();

        if (pos == K)
        {
            return path[pos];

        }

        myQueue.pop();

        if (visited[pos + 1] == 0 && pos + 1 >= 0 && pos + 1 < MAX)
        {
            visited[pos + 1] = true;
            myQueue.push(pos + 1);
            path[pos + 1] = path[pos] + 1;
        }
        if (visited[pos - 1] == 0 && pos - 1 >= 0 && pos - 1 < MAX)
        {
            visited[pos - 1] = true;
            myQueue.push(pos - 1);
            path[pos - 1] = path[pos] + 1;
        }
        if (visited[pos * 2] == 0 && pos * 2 >= 0 && pos * 2 < MAX)
        {
            visited[pos * 2] = true;
            myQueue.push(pos * 2);
            path[pos * 2] = path[pos] + 1;
        }
    }

}

int main()
{
    Init();
    cout << BFS(N, K);
    return 0;
}