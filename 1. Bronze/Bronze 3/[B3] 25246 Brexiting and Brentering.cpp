#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string Ntrylize(string& s)
{
    int n = s.size();
    string result = s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!IsMo(result[i]))
            result.pop_back();
        else
            break;
    }
    result += "ntry";

    return result;
}

int main()
{
    FastIO;

    string s;
    cin>> s;

    string result = Ntrylize(s);
    cout << result << '\n';
}