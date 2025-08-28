#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int p;
        cin >> p;

        int result = 0;
        while (true)
        {
            int k;
            cin >> k;

            if (k == 0)
                break;

            result += max(k - p * 2, 0);
            p = k;
        }
        cout << result << '\n';
    }
}