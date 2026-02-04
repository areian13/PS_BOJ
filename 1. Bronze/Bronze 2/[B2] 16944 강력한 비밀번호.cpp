#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinAdd(string& s)
{
    bool n, l, u, p;
    n = l = u = p = false;
    for (char c : s)
    {
        n |= ('0' <= c && c <= '9');
        l |= ('a' <= c && c <= 'z');
        u |= ('A' <= c && c <= 'Z');
        p |= (string("!@#$%^&*()-+").find(c) != -1);
    }

    return max(!n + !l + !u + !p, 6 - (int)s.size());
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = MinAdd(s);
    cout << result << '\n';
}