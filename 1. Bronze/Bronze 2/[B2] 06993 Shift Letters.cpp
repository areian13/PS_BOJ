#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ShiftN(string& s, int n)
{
    int k = s.size();
    string result(k, '\0');
    for (int i = 0; i < k; i++)
        result[(i + n) % k] = s[i];
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        int n;
        cin >> s >> n;

        string result = ShiftN(s, n);
        printf("Shifting %s by %d positions gives us: %s\n",
            s.c_str(), n, result.c_str());
    }
}