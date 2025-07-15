#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = 0;
    string temp = "";
    for (char c : s)
    {
        if (c == ',')
        {
            result += stoi(temp);
            temp = "";
        }
        else
            temp += c;
    }
    result += stoi(temp);

    cout << result << '\n';
}