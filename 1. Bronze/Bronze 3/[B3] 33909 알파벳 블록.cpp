#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int s, c, o, n;
    cin >> s >> c >> o >> n;

    int result = min((s + n) / 3, (c + o * 2) / 6);
    cout << result << '\n';
}