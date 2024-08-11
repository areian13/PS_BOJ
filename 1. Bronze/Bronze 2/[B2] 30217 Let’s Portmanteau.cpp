#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string CombinedWord(string& a, string& b)
{
    int n = a.size();
    int aIdx = 1;
    while (aIdx < n && !IsMo(a[aIdx]))
        aIdx++;

    int m = b.size();
    int bIdx = m - 2;
    while (bIdx >= 0 && !IsMo(b[bIdx]))
        bIdx--;

    if (bIdx != -1)
        return a.substr(0, aIdx) + b.substr(bIdx, m);
    if (aIdx != n)
        return a.substr(0, aIdx + 1) + b;
    return a + 'o' + b;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    string result = CombinedWord(a, b);
    cout << result << '\n';
}