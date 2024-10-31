#include <iostream>
#include <string>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBracket(char c)
{
    return c == '(' || c == ')' || c == '[' || c == ']';
}

bool IsBalanced(string str)
{
    stack<char> S;

    for (char c : str)
    {
        if (!IsBracket(c))
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

        string result = (IsBalanced(str) ? "yes" : "no");
        cout << result << '\n';
    }
}