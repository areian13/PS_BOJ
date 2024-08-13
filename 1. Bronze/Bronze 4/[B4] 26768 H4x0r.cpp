#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, char> cyfra;
    cyfra['a'] = '4';
    cyfra['e'] = '3';
    cyfra['i'] = '1';
    cyfra['o'] = '0';
    cyfra['s'] = '5';

    string str;
    cin >> str;

    string result = str;
    for (char& c : result)
    {
        if (cyfra.count(c) == 1)
            c = cyfra[c];
    }
    cout << result << '\n';
}