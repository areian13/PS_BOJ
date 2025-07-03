#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        char d = s.back();
        s.pop_back();
        for (auto& c : s)
        {
            if ('A' <= c && c <= 'Z')
                c = (c - d + 26) % 26 + 'A';
            else if ('a' <= c && c <= 'z')
                c = (c - d - 32 + 26) % 26 + 'a';
        }
        cout << s << '\n';
    }
}