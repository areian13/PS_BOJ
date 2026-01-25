#include <iostream>
#include <string>
#include <vector>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<char, char> opp = {
    {')','('},
    {']','['},
    {'}','{'},
};

bool IsRight(string& s)
{
    vector<char> stk;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            stk.push_back(c);
            continue;
        }
        if (stk.empty() || stk.back() != opp[c])
            return false;
        stk.pop_back();
    }
    return stk.empty();
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int cnt = 2, idx = -1;
        char c = '\0';
        for (int i = 0; s[i] != '\0'; i++)
        {
            string t = s;
            for (int p : { '(', '[', '{', '}', ']', ')' })
            {
                t[i] = p;
                if (!IsRight(t))
                    continue;

                if (cnt > (s[i] != p))
                {
                    cnt = (s[i] != p);
                    idx = i, c = p;
                }
            }
        }

        if (cnt == 2)
            cout << "NO" << '\n';
        else if (cnt == 0)
            cout << "YES 0" << '\n';
        else
        {
            cout << "YES 1" << '\n';
            cout << idx + 1 << ' ' << c << '\n';
        }
    }
}