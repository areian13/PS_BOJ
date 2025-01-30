#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Encryption(string& k, string& s)
{
    string result = "";
    int i = 0;
    for (char c : s)
    {
        if (!('A' <= c && c <= 'Z'))
            continue;

        result += ((c - 'A') + (k[i] - 'A')) % 26 + 'A';
        i = (i + 1) % k.size();
    }
    return result;
}

int main()
{
    FastIO;

    string k, s;
    cin >> k;
    getline(cin.ignore(), s);

    string result = Encryption(k, s);
    cout << result << '\n';
}