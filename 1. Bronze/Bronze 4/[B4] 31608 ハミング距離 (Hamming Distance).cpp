#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int HammingDist(string& s, string& t)
{
    int n = s.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (s[i] != t[i]);
    return result;
}

int main()
{
    FastIO;

    int n;
    string s, t;
    cin >> n >> s >> t;

    int result = HammingDist(s, t);
    cout << result << '\n';
}