#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n;
    string name, ctg;
    cin >> t; // 테스트 케이스 입력
    map<string, int> m;
    while (t--)
    {
        cin >> n;
        while (n--)
        {
            cin >> name >> ctg;
            if (m.find(ctg) == m.end()) // m에 같은 종류가 없으면 추가
                m.insert({ctg, 1});
            else
                m[ctg]++; // 있으면 key 값 증가
        }
        int sum = 1;
        for (auto i : m)
        {
            sum *= (i.second + 1); // 어떤 종류의 옷을 하나도 안 입는 경우 포함
        }
        sum -= 1;            // 알몸인 경우 빼기
        cout << sum << "\n"; // 출력
        m.clear();
    }

    return 0;
}
