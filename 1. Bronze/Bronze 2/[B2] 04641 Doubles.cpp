#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int ai;
        cin >> ai;

        if (ai == -1)
            break;

        vector<int> a = { ai };
        while (true)
        {
            cin >> ai;
            if (ai == 0)
                break;
            a.push_back(ai);
        }

        int n = a.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                result += (a[i] * 2 == a[j]);
        }
        cout << result << '\n';
    }
}