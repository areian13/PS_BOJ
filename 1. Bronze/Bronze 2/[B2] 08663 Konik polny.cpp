#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, s;
    cin >> x >> s;

    int result = 0;
    int l = 0;
    while (l < x)
    {
        l += s;
        result++;

        s = max(s / 2, 1);
        if (s == 1)
        {
            result += x - l;
            break;
        }
    }
    cout << result << '\n';
}