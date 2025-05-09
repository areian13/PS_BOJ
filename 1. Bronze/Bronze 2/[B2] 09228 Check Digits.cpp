#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char Check(string& s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (s[n - 1 - i] - '0') * (i + 2);

    char result = 11 - (sum % 11) + '0';
    if (result == 11 + '0')
        return '0';
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        cout << s << " -> ";
        char result = Check(s);
        if (result == ':')
            cout << "Rejected" << '\n';
        else
            cout << result << '\n';
    }
}