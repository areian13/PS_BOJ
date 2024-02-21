#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CompareIgnoreCase(string a, string b)
{
    for (char& c : a)
        c |= 32;
    for (char& c : b)
        c |= 32;

    return a > b;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        string result = "{";
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            if (CompareIgnoreCase(result, str))
                result = str;
        }
        cout << result << '\n';
    }
}