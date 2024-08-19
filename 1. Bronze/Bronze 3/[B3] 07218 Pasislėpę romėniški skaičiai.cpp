#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(string& s, string& x)
{
    int n = s.size();
    int m = x.size();

    for (int i = 0; i < n - m + 1; i++)
    {
        if (s.substr(i, m) == x)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    vector<string> rome = { "","I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII" };

    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i <= 12; i++)
    {
        if (IsIn(s, rome[i]))
            cout << i << ' ';
    }
    cout << '\n';
}