#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, h;
    cin >> a >> b >> h;

    int result = max((h - b - 1) / (a - b) + 1, 1);
    cout << result << '\n';
}