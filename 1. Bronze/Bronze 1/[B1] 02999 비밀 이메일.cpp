#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Encode(string& s)
{
    int n = s.size();
    int r = 1, c = n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            r = i, c = n / i;
    }
    string result = "";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            result += s[i + j * r];
    }
    return result;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = Encode(s);
    cout << result << '\n';
}