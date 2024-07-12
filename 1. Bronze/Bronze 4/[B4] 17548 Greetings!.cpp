#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Heey(string& hey)
{
    string result = "";
    for (char e : hey)
    {
        result += e;

        if (e == 'e')
            result += e;
    }
    return result;
}

int main()
{
    FastIO;

    string hey;
    cin>> hey;

    string result = Heey(hey);
    cout << result << '\n';
}