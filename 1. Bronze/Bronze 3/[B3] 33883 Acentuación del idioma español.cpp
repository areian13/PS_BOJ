#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int Acent(string& s)
{
    int n = s.size();
    if (s.back() != 'n' && s.back() != 's' && !IsMo(s.back()))
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (IsMo(s[i]))
                return i + 1;
        }
        return -1;
    }

    bool last = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (IsMo(s[i]))
        {
            if (!last)
                last = true;
            else
                return i + 1;
        }
    }
    return -1;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = Acent(s);
    cout << result << '\n';
}