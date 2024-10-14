#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        string seq;
        cin >> seq;

        array<int, 26> w;
        for (int i = 0; i < 26; i++)
            w[seq[i] - 'A'] = i;

        vector<string> word(n);
        for (int i = 0; i < n; i++)
            cin >> word[i];

        sort(word.begin(), word.end(),
            [&w](const string& a, const string& b)
            {
                int l = min(a.size(), b.size());
                for (int i = 0; i < l; ++i)
                {
                    if (a[i] != b[i])
                        return w[a[i] - 'A'] < w[b[i] - 'A'];
                }
                return a.size() < b.size();
            }
        );

        cout << "year " << ++tc << '\n';
        for (int i = 0; i < n; i++)
            cout << word[i] << '\n';
    }
}