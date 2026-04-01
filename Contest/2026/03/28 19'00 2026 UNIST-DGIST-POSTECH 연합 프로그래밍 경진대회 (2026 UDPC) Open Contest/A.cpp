#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Dist(int x, int y, int n)
{
    int d = abs(x - y);
    return min(d, n - d);
}

int Postech(int n, int a, int b, int c, int p, int q)
{
    int unist = 0;
    for (int dgist : {a, n - a})
    {
        for (int postech : {(dgist + b) % n, (dgist - b + n) % n})
        {
            if (Dist(unist, postech, n) != c)
                continue;

            for (int contest : {p, (n - p) % n})
            {
                if (Dist(unist, contest, n) == p && Dist(dgist, contest, n) == q)
                    return Dist(postech, contest, n);
            }
        }
    }
    return -1;
}

int main()
{
    FastIO;

    int n, a, b, c, p, q;
    cin >> n >> a >> b >> c >> p >> q;

    int result = Postech(n, a, b, c, p, q);
    cout << result << '\n';
}