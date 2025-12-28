#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void LShift(string& s)
{
    int n = s.size();
    string t(n, '\0');
    for (int i = 0; i < n; i++)
        t[i] = s[(i + 1) % n];
    s = t;
}

int main()
{
    FastIO;

    string s = "SciComLove";

    int n;
    cin >> n;

    n %= s.size();
    for (int i = 0; i < n; i++)
        LShift(s);
    cout << s << '\n';
}