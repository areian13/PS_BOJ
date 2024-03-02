#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int k;
        cin >> k;

        if (k == 0)
            break;

        vector<int> result;
        int pre = 0;
        for (int i = 1; i <= k; i++)
        {
            int p;
            cin >> p;

            int n = p - pre;
            for (int j = 0; j < n; j++)
                result.push_back(i);
            pre = p;
        }

        for (int v : result)
            cout << v << ' ';
    }
}