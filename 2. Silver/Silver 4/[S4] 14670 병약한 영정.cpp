#include <iostream>
#include <unordered_map>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<int, int> drugs;
    for (int i = 0; i < n; i++)
    {
        int e, m;
        cin >> e >> m;
        drugs[e] = m;
    }

    int r;
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        int l;
        cin >> l;

        vector<int> result;
        for (int i = 0; i < l; i++)
        {
            int s;
            cin >> s;

            if (drugs.count(s) == 1)
                result.push_back(drugs[s]);
        }

        if (result.size() != l)
            cout << "YOU DIED" << '\n';
        else
        {
            for (int drug : result)
                cout << drug << ' ';
            cout << '\n';
        }
    }
}