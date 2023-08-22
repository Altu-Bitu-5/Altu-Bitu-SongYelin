#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int t, n;
    int a, b;
    // 입력
    cin >> t;
    while (t--)
    {

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        cin >> n;
        vector<pair<int, int>> g;
        for (int j = 0; j < n; j++)
        {
            cin >> a >> b;
            g.push_back({a, b}); // 지원자의 각각 순위를 백터에 넣음
        }
        sort(g.begin(), g.end()); // 서류 성적의 순윌로 정렬
        int count = 1;            // 서류 순위 1등은 자동 채용
        int k = 0;
        for (int l = 1; l < n; l++)
        {
            if (g[k].second > g[l].second)
            { // 앞 지원자와 면접순위 비교, 앞 순서보다 순위가 더 크면 포함되지 않음
                count++;
                k = l;
            }
        }
        cout << count << "\n";
        g.clear();
    }
    return 0;
}
