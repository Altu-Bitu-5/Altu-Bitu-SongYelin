#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int n, m;
    string input;
    int count = 0;
    cin >> n >> m; // 개수 입력
    vector<string> a(n);
    for (int j = 0; j < n; j++)
    {
        cin >> a[j];
    }                         // n개의 문자열을 vector a에 넣기
    sort(a.begin(), a.end()); // 탐색 전 N개를 sort 해준다
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (binary_search(a.begin(), a.end(), input))
            count++;
        // binary_search() 함수로 input 값과 vector a에 들어있는 값 같은 지 확인
        // 같으면 count
    }
    cout << count; // 출력

    return 0;
}
