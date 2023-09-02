#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

queue<int> calculator(int n, int k){
    queue<int> circle;     // 사람들이 앉을 원
    queue<int> death_note; // 데스노트
    for (int i = 1; i <= n; i++)
    {
        circle.push(i); // 앉히기
    }
    while (n--)
    {
        for (int i = 0; i < k-1; i++) // k-1명의 사람을 큐에서 빼서 다시 큐에 넣는다
        {
            circle.push(circle.front());
            circle.pop();
        }
        death_note.push(circle.front()); // k번째 사람은 데스노트 큐에 저장
        circle.pop();
    }
    return death_note;
}

int main()
{
    int n, k; // n명, k번째

    cin >> n >> k; //입력


    queue<int> death_note= calculator(n,k);//연산

    // 데스노트에 있는 사람들을 출력
    cout << "<";
    cout << death_note.front();
    death_note.pop();
    while (!death_note.empty())
    {

        cout << ", " << death_note.front();
        death_note.pop();
    }
    cout << ">";

    return 0;
}
