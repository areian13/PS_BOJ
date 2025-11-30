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

        stack<string> result;
        stringstream ss(s);
        string temp;
        while (ss >> temp)
            result.push(temp);

        printf("Case #%d: ", tc);
        while (!result.empty())
        {
            printf("%s ", result.top().c_str());
            result.pop();
        }
        printf("\n");
    }
}