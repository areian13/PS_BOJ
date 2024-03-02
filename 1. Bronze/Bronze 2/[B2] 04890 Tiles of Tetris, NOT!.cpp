#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinTile(long long w, long long h)
{
    if (w == h)
        return 1;
    if (w < h)
        swap(w, h);
    if (w % h == 0)
        return w / h;
    return w * h;
}

int main()
{
    FastIO;

    while (true)
    {
        long long w, h;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        long long result = MinTile(w, h);
        cout << result << '\n';
    }
}