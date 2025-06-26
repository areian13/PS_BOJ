#include <iostream>
#include <array>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int c, d, v;
        cin >> c >> d >> v;

        array<vector<vector<int>>, 2> cnt;
        cnt[0].resize(c, vector<int>(d, 0));
        cnt[1].resize(d, vector<int>(c, 0));

        vector<
        for (int i = 0; i < v; i++)
        {
            string a, b;
            cin >> a >> b;

            int av = stoi(a.substr(1)) - 1;
            int bv = stoi(b.substr(1)) - 1;

            cnt[a[0] == 'D'][av][bv]++;
        }
    }
}