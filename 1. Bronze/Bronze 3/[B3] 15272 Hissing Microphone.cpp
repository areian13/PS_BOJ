#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHiss(string& str)
{
    int n = str.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == 's' && str[i + 1] == 's')
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    string str;
    cin >> str;

    string result = (IsHiss(str) ? "hiss" : "no hiss");
    cout << result << '\n';
}