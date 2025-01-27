#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanDNA(char a0, char a1, char b0, char b1, char c)
{
    if ('a' <= c && c <= 'z')
        return ('a' <= a1 && a1 <= 'z') && ('a' <= b1 && b1 <= 'z');
    return ('A' <= a0 && a0 <= 'Z') || ('A' <= b0 && b0 <= 'Z');
}

bool CanChild(string& a, string& b, string& c)
{
    int n = c.size();
    for (int i = 0; i < n; i++)
    {
        if (!CanDNA(a[i * 2], a[i * 2 + 1], b[i * 2], b[i * 2 + 1], c[i]))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int x;
    cin >> x;

    for (int q = 1; q <= x; q++)
    {
        string c;
        cin >> c;

        bool result = CanChild(a, b, c);
        if (result == true)
            cout << "Possible baby." << '\n';
        else
            cout << "Not their baby!" << '\n';
    }
}