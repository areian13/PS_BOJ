#include <iostream>
#include <string>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBucket(char c)
{
    return c == '(' || c == ')' || c == '[' || c == ']';
}

bool IsBalancedString(string str)
{
    stack<char> S;

    for (char c : str)
    {
        if (!IsBucket(c))
            continue;

        if (c == '(' || c == '[')
            S.push(c);
        else
        {
            if (c == ')')
            {
                if (S.empty() || S.top() != '(')
                    return false;
            }
            else if (c == ']')
            {
                if (S.empty() || S.top() != '[')
                    return false;
            }
            S.pop();
        }
    }
    return S.empty();
}

int main()
{
    FastIO;

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            break;

        string result = (IsBalancedString(str) ? "yes" : "no");
        cout << result << '\n';
    }
}