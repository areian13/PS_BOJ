#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int NeedPage(int h, int w, int n, int a, int b)
{
    int r = h / a;
    int c = w / b;

    int p = r * c;
    return n / p + (n % p != 0);
}

int main()
{
    FastIO;

    int h, w, n, a, b;
    cin >> h >> w >> n >> a >> b;

    int result = (h < a || w < b) ? -1 : NeedPage(h, w, n, a, b);
    cout << result << '\n';
}