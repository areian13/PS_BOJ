#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    int s1 = a1 * 1 + b1 * 2 + c1 * 3;
    int s2 = a2 * 1 + b2 * 2 + c2 * 3;

    int result = (s1 == s2 ? 0 : (s1 > s2 ? 1 : 2));
    cout << result << '\n';
}