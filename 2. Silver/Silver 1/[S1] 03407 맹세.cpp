#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_set<string> e = {
    "h", "he", "li", "be", "b",
    "c", "n", "o", "f", "ne",
    "na", "mg", "al", "si", "p",
    "s", "cl", "ar", "k", "ca",
    "sc", "ti", "v", "cr", "mn",
    "fe", "co", "ni", "cu", "zn",
    "ga", "ge", "as", "se", "br",
    "kr", "rb", "sr", "y", "zr",
    "nb", "mo", "tc", "ru", "rh",
    "pd", "ag", "cd", "in", "sn",
    "sb", "te", "i", "xe", "cs",
    "ba", "la", "ce", "pr", "nd",
    "pm", "sm", "eu", "gd", "tb",
    "dy", "ho", "er", "tm", "yb",
    "lu", "hf", "ta", "w", "re",
    "os", "ir", "pt", "au", "hg",
    "tl", "pb", "bi", "po", "at",
    "rn", "fr", "ra", "rf", "db",
    "sg", "bh", "hs", "mt", "ds",
    "rg", "cn", "fl", "lv", "la",
    "ce", "pr", "nd", "pm", "sm",
    "eu", "gd", "tb", "dy", "ho",
    "er", "tm", "yb", "lu", "ac",
    "th", "pa", "u", "np", "pu",
    "am", "cm", "bk", "cf", "es",
    "fm", "md", "no", "lr"
};

bool IsElem(string& s, int d, vector<int>& dp)
{
    if (d >= s.size())
        return true;
    if (dp[d] != -1)
        return dp[d];

    bool result = false;
    for (int i = 2; i >= 1; i--)
    {
        if (e.find(s.substr(d, i)) != e.end())
            result |= IsElem(s, d + i, dp);
    }
    return dp[d] = result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        vector<int> dp(s.size(), -1);
        bool result = IsElem(s, 0, dp);
        cout << (result ? "YES" : "NO") << '\n';
    }
}