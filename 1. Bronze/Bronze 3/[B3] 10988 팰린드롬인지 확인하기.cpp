#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPalin(string& str)
{
    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string str;
    cin >> str;

    bool result = IsPalin(str);
    cout << result << '\n';
}