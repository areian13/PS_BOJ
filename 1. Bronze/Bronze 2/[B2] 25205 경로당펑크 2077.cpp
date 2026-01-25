#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsFinal(string& s)
{
    const string final = "qwertasdfgzxcv";
    return final.find(s.back()) != -1;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    bool result = IsFinal(s);
    cout << result << '\n';
}