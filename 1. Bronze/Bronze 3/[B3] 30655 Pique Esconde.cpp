#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<bool> isSelected(n + 1, false);
        isSelected[m] = true;

        for (int i = 0; i < n - 2; i++)
        {
            int k;
            cin >> k;

            isSelected[k] = true;
        }

        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!isSelected[i])
            {
                result = i;
                break;
            }
        }
        cout << result << '\n';
    }
}