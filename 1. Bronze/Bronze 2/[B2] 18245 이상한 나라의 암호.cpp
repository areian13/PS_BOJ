#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "Was it a cat I saw?")
            break;

        int n = s.size();
        tc++;
        for (int i = 0; i < n; i += tc + 1)
            cout << s[i];
        cout << '\n';
    }
}