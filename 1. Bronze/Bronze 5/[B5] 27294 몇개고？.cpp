#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t, s;
    cin >> t >> s;

    int result = (!(12 <= t && t <= 16) || s) ? 280 : 320;
    cout << result << '\n';
}