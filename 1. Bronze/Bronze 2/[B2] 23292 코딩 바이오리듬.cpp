#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Rhythm(const string& a, const string& b)
{
    int y = 0, m = 0, d = 0;
    for (int i = 0; i < 4; i++)
        y += (a[i] - b[i]) * (a[i] - b[i]);
    for (int i = 4; i < 6; i++)
        m += (a[i] - b[i]) * (a[i] - b[i]);
    for (int i = 6; i < 8; i++)
        d += (a[i] - b[i]) * (a[i] - b[i]);
    return y * m * d;
}

int main()
{
    FastIO;

    string s;
    int n;
    cin >> s >> n;

    auto comp = [&s](const string& a, const string& b)
        { 
            int ar = Rhythm(s, a), br = Rhythm(s, b);
            if (ar != br) return ar < br;
            return a > b;
        };
    string result = s;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;

        result = max(result, t, comp);
    }
    cout << result << '\n';
}