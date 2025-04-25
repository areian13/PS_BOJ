#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        int s = 1;
        while (s < n)
            s += k - 1;

        int result = s - n;
        cout << result << '\n';
    }
}