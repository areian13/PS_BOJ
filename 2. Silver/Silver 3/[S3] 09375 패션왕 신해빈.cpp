#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> garbsCount;
        for (int i = 0; i < n; i++)
        {
            string name, garb;
            cin >> name >> garb;

            garbsCount[garb]++;
        }

        int result = 1;
        for (auto& garbCount : garbsCount)
            result *= (garbCount.second + 1);
        result--;

        cout << result << '\n';
    }
}