#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Encryption(string& str)
{
    string result = "";
    for (char c : str)
    {
        if ('A' <= c && c <= 'Z')
            result += to_string(c - 'A' + 27);
        else if ('a' <= c && c <= 'z')
        {
            if (c <= 'i')
                result += '0';
            result += to_string(c - 'a' + 1);
        }
        else if ('0' <= c && c <= '9')
        {
            result += '#';
            result += c;
        }
        else
            result += c;
    }
    return result;
}

int main()
{
    FastIO;

    string str;
    getline(cin, str);

    string result = Encryption(str);
    cout << result << '\n';
}