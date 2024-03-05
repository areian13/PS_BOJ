#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string str;
        cin >> str;

        int n = str.size();

        string result = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (i != n - 1 && str[i] <= str[i + 1])
                break;

            result += str[i];
        }
        reverse(result.begin(), result.end());

        printf("The longest decreasing suffix of %s is %s\n", str.c_str(), result.c_str());
    }
}