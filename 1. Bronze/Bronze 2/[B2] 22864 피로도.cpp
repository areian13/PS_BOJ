#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int work = 0, piro = 0;
    for (int i = 0; i < 24; i++)
    {
        if (piro + a <= m)
            piro += a, work += b;
        else
            piro = max(piro - c, 0);
    }
    cout << work << '\n';
}