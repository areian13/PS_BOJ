#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;

    int result = h * i - a * r * c;
    cout << result << '\n';
}