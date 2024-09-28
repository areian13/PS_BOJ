#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,-1,0,1 };

int Dir(char c)
{
    if (c == 'U')
        return 2;
    if (c == 'D')
        return 0;
    if (c == 'L')
        return 1;
    return 3;
}

bool CanGoStart(int n, int k, string& s)
{
    int y = 0;
    int x = 0;

    k = min(n / 2, k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int dir = Dir(s[j]);

            y += dy[dir];
            x += dx[dir];

            if (y == 0 && x == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    FastIO;

    int n, k;
    string s;
    cin >> n >> k >> s;

    string result = CanGoStart(n, k, s) ? "YES" : "NO";
    cout << result << '\n';
}