#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string XOR(string s, int key)
{
    for (char& c : s)
        c ^= key;
    return s;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int key = 0;
    while (true)
    {
        if (XOR(s.substr(0, 8), key) == "CHICKENS")
            break;
        key++;
    }

    for (char c : s)
        cout << (char)(c ^ key);
    cout << '\n';
}