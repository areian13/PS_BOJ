#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int s, t;
    cin >> s >> t;

    int result = t - s + (t <= s ? 24 : 0);
    cout << result << '\n';
}