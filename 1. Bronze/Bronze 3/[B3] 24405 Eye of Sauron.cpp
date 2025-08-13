#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    char l[101] = { '\0', }, r[101] = { '\0', };
    scanf("%[^()]%2s%[^\n]", l, r, r);

    string ls(l), rs(r);
    bool result = (ls == rs);

    if (result)
        cout << "correct" << '\n';
    else
        cout << "fix" << '\n';
}