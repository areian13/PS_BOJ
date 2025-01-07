#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int r, g, b;
    cin >> r >> g >> b;

    int result = r * 3 + g * 4 + b * 5;
    cout << result << '\n';
}