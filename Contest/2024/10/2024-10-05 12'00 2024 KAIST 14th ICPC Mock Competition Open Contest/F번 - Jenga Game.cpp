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

        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i++)
        {
            string b;
            cin >> b;

            if (i == 0)
                continue;

            cnt[b]++;
        }

        string result = (cnt["111"] % 2 || (cnt["110"] + cnt["011"]) % 2) ? "Yesyes" : "Nono";
        cout << result << '\n';
    }
}