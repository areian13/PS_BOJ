#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int p = 0;
        string result = "";
        for (int i = 0; i < n; i++)
        {
            int c;
            string k;
            cin >> c >> k;

            if (c > p)
            {
                p = c;
                result = k;
            }
        }
        cout << result << '\n';
    }
}