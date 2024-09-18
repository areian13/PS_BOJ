#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int s, t, r;
        cin >> s >> t >> r;

        int result = 0;
        int p = 0;
        while (p < n)
        {
            for (int i = 0; i < t; i++)
            {
                result++;
                p += s;

                if (p >= n)
                    break;
            }

            if (p >= n)
                break;

            result += r;
        }
        cout << result << '\n';
    }
}