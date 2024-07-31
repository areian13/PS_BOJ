#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        bool isFull = true;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;

            isFull &= (l + r == n);
        }

        string result = (isFull ? "no" : "yes");
        cout << result << '\n';
    }
}