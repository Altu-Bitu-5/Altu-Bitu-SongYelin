#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int sum(string a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
        {
            sum += a[i] - '0';
        }
    }
    return sum;
}
bool cmp(string a, string b)
{

    if (a.size() != b.size()) // 길이가 다르면 오름차순으로 정렬
        return a.size() < b.size();
    if (sum(a) != sum(b))
        return sum(a) < sum(b);
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
    {
        cout << guitar[i] << '\n';
    }
    return 0;
}
