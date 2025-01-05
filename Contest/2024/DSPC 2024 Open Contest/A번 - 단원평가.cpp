#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Pytha(int a, int b, int c)
{
    if (a == 0)
        return c * c - b;
    if (b == 0)
        return c * c - a;
    return sqrt(a + b);
}

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    int result = Pytha(a, b, c);
    cout << result << '\n';
}