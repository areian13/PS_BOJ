#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsTautogram(string& s)
{
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == ' ' && (s[i] | 32) != (s[0] | 32))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "*")
            break;
        
        char result = (IsTautogram(s) ? 'Y' : 'N');
        cout << result << '\n';
    }
}