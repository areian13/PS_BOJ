#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Delete(string s, int n)
{
    for(char& c : s)
        c = (c - '0' + n) % 2 + '0';
    return s;
}

int main()
{
    FastIO;

    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    string result = Delete(s1, n);
    if (result == s2)
        cout << "Deletion succeeded" << '\n';
    else
        cout << "Deletion failed" << '\n';
}