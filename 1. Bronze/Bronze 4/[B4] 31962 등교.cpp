#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x;
    cin >> n >> x;

    int result = -1;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;

        if (s + t <= x)
            result = max(result, s);
    }
    cout << result << '\n';
}