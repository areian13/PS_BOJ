#include <iostream>
#include <vector>
#include <limits>

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

        vector<int> heigth(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> heigth[i];
        heigth[0] = INT_MAX;
        heigth[n + 1] = INT_MAX;

        int x;
        cin >> x;

        int h = heigth[x];
        int result = 0;

        while (heigth[x] == h)
        {
            int idx = 1;
            while (heigth[idx] >= heigth[idx + 1])
                idx++;
            do
            {
                heigth[idx]++;
                idx--;
                result++;
            } while (heigth[idx + 1] > heigth[idx]);
        }
        cout << result << '\n';
    }
}