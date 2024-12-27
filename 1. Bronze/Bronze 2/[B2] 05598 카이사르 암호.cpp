#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string RRotK(string& s, int k)
{
    string result = "";
    for (char c : s)
        result += (c - 'A' + 26 - k) % 26 + 'A';
    return result;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = RRotK(s, 3);
    cout << result << '\n';
}