#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long CountPos(long long b, long long u, long long l, long long r)
{
    if (b == INT_MIN || l == INT_MIN || u == INT_MAX || r == INT_MAX)
        return -1;
    return (u - b - 1) * (r - l - 1);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long b = INT_MIN;
    long long u = INT_MAX;
    long long l = INT_MIN;
    long long r = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        char dir;
        cin >> x >> y >> dir;

        if (dir == 'D')
            u = min(u, y);
        else if (dir == 'U')
            b = max(b, y);
        else if (dir == 'R')
            l = max(l, x);
        else if (dir == 'L')
            r = min(r, x);
    }

    long long countPos = CountPos(b, u, l, r);
    string result = (countPos != -1 ? to_string(countPos) : "Infinity");
    cout << result << '\n';
}
