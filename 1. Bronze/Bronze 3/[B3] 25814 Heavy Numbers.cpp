#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Heavy(string& a, string& b)
{
    int ha = 0;
    for (char c : a)
        ha += (c - '0');
    ha *= a.size();

    int hb = 0;
    for (char c : b)
        hb += (c - '0');
    hb *= b.size();

    return (ha == hb ? 0 : (ha > hb ? 1 : 2));
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int result = Heavy(a, b);
    cout << result << '\n';
}