#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a1, b1, c1, a2, b2, c2, h1, m1, s1;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> h1 >> m1 >> s1;

    int time = h1 * b1 * c1 + m1 * c1 + s1;
    int h2 = time / (b2 * c2);
    int m2 = time % (b2 * c2) / c2;
    int s2 = time % c2;

    cout << h2 << ' ' << m2 << ' ' << s2 << '\n';
}