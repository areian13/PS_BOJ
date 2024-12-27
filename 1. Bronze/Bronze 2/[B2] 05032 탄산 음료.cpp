#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int e, f, c;
    cin >> e >> f >> c;

    int result = 0;
    int s = e + f;
    while (s >= c)
    {
        result += s / c;
        s = (s / c) + (s % c);
    }
    cout << result << '\n';
}