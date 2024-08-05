#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    getline(cin, str);

    string result = (str.substr(str.size() - 3) == "eh?" ? "Canadian!" : "Imposter!");
    cout << result << '\n';
}