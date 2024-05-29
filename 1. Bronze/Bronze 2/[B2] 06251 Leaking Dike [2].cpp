#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> heigth(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> heigth[i];

        int x;
        cin >> x;

        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (heigth[i] > heigth[x])
                continue;
            result += heigth[x] - heigth[i] + 1;
        }
        cout << result << '\n';
    }
}