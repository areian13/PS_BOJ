#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinPlate(int a, int b, int h, int w)
{
    int p = h / a + (h % a != 0);
    int q = w / b + (w % b != 0);
    return p * q;
}

int main()
{
    FastIO;

    int a, b, h, w;
    cin >> a >> b >> h >> w;

    int result = MinPlate(a, b, h, w);
    cout << result << '\n';
}