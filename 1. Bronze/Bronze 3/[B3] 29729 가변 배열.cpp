#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int s, n, m;
    cin >> s >> n >> m;

    int u = 0;
    for (int i = 0; i < n + m; i++)
    {
        int k;
        cin >> k;

        u += (k == 1 ? +1 : -1);
        if (u > s)
            s *= 2;
    }
    cout << s << '\n';
}