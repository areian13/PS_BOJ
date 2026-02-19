#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsFair(vector<vector<vector<string>>>& sch)
{
    map<string, int> cnt;
    vector<int> t = { 4,6,4,10 };
    for (auto& week : sch)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (week[i][j] == "-")
                    continue;
                cnt[week[i][j]] += t[i];
            }
        }
    }

    auto comp = [](auto& a, auto& b) { return a.second < b.second; };
    int mt = min_element(cnt.begin(), cnt.end(), comp)->second;
    int Mt = max_element(cnt.begin(), cnt.end(), comp)->second;
    return Mt - mt <= 12;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector sch(n, vector(4, vector<string>(7)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 7; k++)
                cin >> sch[i][j][k];
        }
    }

    bool result = IsFair(sch);
    cout << (result ? "Yes" : "No") << '\n';
}