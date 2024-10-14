#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, f, s;
    cin >> x >> f >> s;

    int result = (f == 1 ? x : 0);
    if (s == 1)
    {
        int k = (f == 1 ? 1 : x);
        for (int i = 0; i < k; i++)
        {
            int t;
            cin >> t;

            result += t;
        }
    }
    cout << result << '\n';
}