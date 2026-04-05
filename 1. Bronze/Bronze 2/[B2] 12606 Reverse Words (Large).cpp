#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string t;
        stack<string> stk;
        while (ss >> t)
            stk.push(t);

        printf("Case #%d: ", tc);
        while (!stk.empty())
        {
            printf("%s ", stk.top().c_str());
            stk.pop();
        }
        printf("\n");
    }
}