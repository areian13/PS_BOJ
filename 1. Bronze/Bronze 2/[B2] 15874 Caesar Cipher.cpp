#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k, n;
    string s;
    cin >> k >> n;
    cin.ignore();
    getline(cin, s);

    for(char& c : s)
    {
        if ('A' <= c && c <= 'Z')
            c = (c - 'A' + k) % 26 + 'A';
        else if ('a' <= c && c <= 'z')
            c = (c - 'a' + k) % 26 + 'a';
    }
    cout << s << '\n';
}