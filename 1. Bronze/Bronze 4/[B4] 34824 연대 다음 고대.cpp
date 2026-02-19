#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s == "yonsei" || s == "korea")
        {
            result = s;
            break;
        }
    }

    printf("Yonsei %s\n", (result == "yonsei" ? "Won!" : "Lost..."));
}