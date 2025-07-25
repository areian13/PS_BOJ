#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Tier
{
    int total;
    array<int, 4> detail;
};

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    vector<Tier> tier(t + 1);
    unordered_map<string, int> tierGrade;
    int m = n;
    for (int i = 1; i <= t; i++)
    {
        string tierName, k;
        cin >> tierName >> k;

        tierGrade[tierName] = i;

        int l = 0;
        if (k.back() == '%')
        {
            k.pop_back();
            l = (long long)m * stoi(k) / 100;
        }
        else
            l = min(m, stoi(k));

        tier[i].total = l;
        m -= l;

        int detail = ceill(l / 4.0);
        for (int j = 0; j < 4; j++)
            tier[i].detail[j] = min(detail, max(l - detail * j, 0));
    }
    string friendTier;
    cin >> friendTier;

    if (m != 0)
        cout << "Invalid System" << '\n';
    else
    {
        int bigTier = 0;
        int smallTier = -1;

        if ('1' <= friendTier.back() && friendTier.back() <= '4')
        {
            smallTier = friendTier.back() - '1';
            friendTier.pop_back();
        }
        bigTier = tierGrade[friendTier];

        if (bigTier == 0
            || (smallTier == -1 && tier[bigTier].total == 0)
            || (smallTier != -1 && tier[bigTier].detail[smallTier] == 0))
            cout << "Liar" << '\n';
        else
        {
            int top = 0;
            for (int i = 1; i < bigTier; i++)
                top += tier[i].total;

            int bottom = top;
            if (smallTier == -1)
                bottom += tier[bigTier].total;
            else
            {
                for (int i = 0; i < smallTier; i++)
                    top += tier[bigTier].detail[i];
                bottom = top + tier[bigTier].detail[smallTier];
            }
            top++;
            cout << top << ' ' << bottom << '\n';
        }
    }
}