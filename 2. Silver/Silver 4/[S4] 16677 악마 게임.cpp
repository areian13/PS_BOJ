#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsGBS(string& w, string& s)
{
    int n = w.size(), m = s.size();
    if (n <= m) return false;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (w[i] == s[j]) j++;
        if (j == m) return true;
    }
    return false;
}

int main()
{
    FastIO;

    string s;
    int n;
    cin >> s >> n;

    string result = "";
    double gbs = 0;
    for (int i = 0; i < n; i++)
    {
        string w;
        int g;
        cin >> w >> g;

        if (!IsGBS(w, s))
            continue;

        double v = 1. * g / (w.size() - s.size());
        if (v > gbs)
            gbs = v, result = w;
    }

    if (result.empty())
        cout << "No Jam" << '\n';
    else
        cout << result << '\n';
}