#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Sum(int a, int d, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        result += max(a - d * i, 0);
    return result;
}

int main()
{
    FastIO;

    int m, dm, h, dh, n;
    cin >> m >> dm >> h >> dh >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int c, b;
        cin >> c >> b;

        result += max(Sum(m, dm, c), Sum(h, dh, b));
    }
    cout << result << '\n';
}