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
        int n;
        cin >> n;

        vector<bool> isOpen(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
                isOpen[j] = !isOpen[j];
        }

        int result = 0;
        for (int i = 1; i <= n; i++)
            result += isOpen[i];
        cout << result << '\n';
    }
}