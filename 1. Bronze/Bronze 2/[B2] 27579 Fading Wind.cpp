#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int FlyingDist(int h, int k, int v, int s)
{
    int result = 0;
    while (h > 0)
    {
        v += s;
        v -= max(1, v / 10);

        if (v >= k)
            h++;
        else if (0 < v && v < k)
        {
            h--;
            if (h == 0)
                v = 0;
        }

        if (v <= 0)
        {
            h = 0;
            v = 0;
        }

        result += v;
        if (s > 0)
            s--;
    }
    return result;
}

int main()
{
    FastIO;

    int h, k, v, s;
    cin >> h >> k >> v >> s;

    int result = FlyingDist(h, k, v, s);
    cout << result << '\n';
}