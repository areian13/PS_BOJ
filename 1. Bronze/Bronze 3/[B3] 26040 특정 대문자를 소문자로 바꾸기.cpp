#include <iostream>
#include <string>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Atoa(string s, vector<char>& bs)
{
    array<bool, 26> isA = { false, };
    for (char b : bs)
        isA[b - 'A'] = true;

    for (char& c : s)
    {
        if (isA[(c & ~32) - 'A'])
            c |= 32;
    }
    return s;
}

int main()
{
    FastIO;

    string a, bl;
    cin >> a;
    getline(cin.ignore(), bl);

    vector<char> bs;
    for (int i = 0; i < bl.size(); i += 2)
        bs.push_back(bl[i]);

    string result = Atoa(a, bs);
    cout << result << '\n';
}