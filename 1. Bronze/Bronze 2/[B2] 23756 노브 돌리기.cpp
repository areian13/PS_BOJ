#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a;
    cin >> n >> a;

    int p = a;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        int d = abs(p - a);
        result += min(d, 360 - d);
        p = a;
    }
    cout << result << '\n';
}