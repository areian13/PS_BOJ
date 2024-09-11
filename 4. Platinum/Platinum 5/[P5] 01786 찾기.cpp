#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string t, p;
    getline(cin, t);
    getline(cin, p);

    int n = t.size();
    int m = p.size();

    vector<int> fail(m, 0);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
    }

    vector<int> result;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = fail[j - 1];

        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                result.push_back(i - m + 1);
                j = fail[j];
            }
            else
               j++;
        }
    }

    int k = result.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << result[i] + 1 << ' ';
    cout << '\n';
}