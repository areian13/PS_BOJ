#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, QC;
    long long m;
    cin >> n >> m >> QC;

    map<int, vector<string>> groups;
    map<string, long long> price;
    map<string, int> have;
    for (int i = 0; i < n; i++)
    {
        int g, p;
        string s;
        cin >> g >> s >> p;

        groups[g].push_back(s);
        price[s] = p;
    }

    for (int qc = 1; qc <= QC; qc++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            string a;
            int b;
            cin >> a >> b;

            if (price[a] * b > m)
                continue;

            m -= price[a] * b;
            have[a] += b;
        }
        else if (q == 2)
        {
            string a;
            int b;
            cin >> a >> b;

            b = min(b, have[a]);
            m += 1LL * price[a] * b;
            have[a] -= b;
        }
        else if (q == 3)
        {
            string a;
            int c;
            cin >> a >> c;
            price[a] += c;
        }
        else if (q == 4)
        {
            int d, c;
            cin >> d >> c;
            for (string& s : groups[d])
                price[s] += c;
        }
        else if (q == 5)
        {
            int d, e;
            cin >> d >> e;

            for (string& s : groups[d])
                price[s] = (long long)((price[s] * (100 + e) / 100) / 10) * 10;
        }
        else if (q == 6)
            cout << m << '\n';
        else
        {
            long long result = m;
            for (auto& [s, b] : have)
                result += 1LL * price[s] * b;
            cout << result << '\n';
        }
    }
}