#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{

    int n, m;
    string input;
    int count = 0;
    cin >> n >> m; // 개수 입력
    set<string> a;
    for (int j = 0; j < n; j++)
    {
        cin >> input;
        a.insert(input);
    } // n개의 문자열을 set a에 넣기

    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (a.find(input) != a.end())
            count++;
        //  a에 들어있는 값과 같은 지 확인
        // 같으면 count
    }
    cout << count; // 출력

    return 0;
}
