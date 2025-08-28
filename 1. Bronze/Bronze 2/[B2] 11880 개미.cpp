#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        long long result = min({
            a * a + (b + c) * (b + c),
            b * b + (c + a) * (c + a),
            c * c + (a + b) * (a + b)
            });
        cout << result << '\n';
    }
}