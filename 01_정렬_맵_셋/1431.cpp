#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool cmp(string a, string b)
{
    int asum = 0, bsum = 0;

    if (a.size() != b.size()) // 길이가 다르면 오름차순으로 정렬
        return a.size() < b.size();
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
            asum += a[i] - '0';
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] - '0' <= 9 && b[i] - '0' >= 0)
            bsum += b[i] - '0';
    }
    if (asum != bsum)
        return asum < bsum;
    return a < b;
}
int main()
{

    int n;
    cin >> n;
    string guitar[50];
    for (int i = 0; i < n; i++)
    {
        cin >> guitar[i];
    }
    sort(guitar, guitar + n, cmp);
    for (int i = 0; i < n; i++)
        cout << guitar[i] << '\n';
    return 0;
}
