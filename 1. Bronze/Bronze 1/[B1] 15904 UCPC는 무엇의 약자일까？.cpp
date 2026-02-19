#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsUCPC(string& s)
{
    int n = s.size();
    for (int i = 0, j = 0; i < n; i++)
    {
        j += (s[i] == "UCPC"[j]);
        if (j == 4)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    bool result = IsUCPC(s);
    printf("I %s UCPC\n", (result ? "love" : "hate"));
}