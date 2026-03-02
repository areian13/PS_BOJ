#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<vector<bool>> mat = {
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1},
    {0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1},
    {0,0,0,0,0,1,1,0},
};

bool IsValid(string& s)
{
    if (s[0] != '1' || s.back() != '2')
        return false;

    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        int p = s[i] - '0' - 1;
        int q = s[i + 1] - '0' - 1;
        if (!mat[p][q])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        string s;
        cin >> s;

        if (s == "0")
            break;

        bool result = IsValid(s);
        printf("%d. %s\n", ++tc, result ? "VALID" : "NOT");
    }
}