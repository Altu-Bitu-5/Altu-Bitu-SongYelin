#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n, k; // n명, k번째

    cin >> n >> k;
    queue<int> circle;     // 사람들이 앉을 원
    queue<int> death_note; // 죽일 명당
    for (int i = 1; i <= n; i++)
    {
        circle.push(i); // 앉히기
    }

    int i = 3;
    int tmp;
    while (n--)
    {
        for (int i = 1; i < k; i++)
        {
            tmp = circle.front();
            circle.pop();
            circle.push(tmp);
        }
        death_note.push(circle.front());
        circle.pop();
    }
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
