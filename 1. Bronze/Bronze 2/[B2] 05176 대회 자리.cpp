#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int p, m;
        cin >> p >> m;

        vector<bool> isUsed(m, false);
        int result = 0;
        for (int i = 0; i < p; i++)
        {
            int k;
            cin >> k;
            k--;

            result += isUsed[k];
            isUsed[k] = true;
        }

        cout << result << '\n';
    }
}