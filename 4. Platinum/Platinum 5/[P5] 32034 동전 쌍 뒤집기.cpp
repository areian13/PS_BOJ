#include <iostream>
#include <vector>
#include <stack>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinFlip(vector<char>& s)
{
    int n = s.size();
    
    long long result = 0;
    stack<int> S;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            if (!S.empty() && S.top() % 2 != i % 2)
            {
                result += i - S.top();
                S.pop();
            }
            else
                S.push(i);
        }
    }

    if (!S.empty())
        return -1;
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int n;
        cin >> n;

        vector<char> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        long long result = MinFlip(s);
        cout << result << '\n';
    }
}