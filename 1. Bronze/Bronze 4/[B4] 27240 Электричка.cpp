#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b, s, t;
    cin >> n >> a >> b >> s >> t;

    if (s > t)
        swap(s, t);

    if (t <= a || s >= b)
        cout << "Outside" << '\n';
    else if (a < s && t < b)
        cout << "City" << '\n';
    else
        cout << "Full" << '\n';
}