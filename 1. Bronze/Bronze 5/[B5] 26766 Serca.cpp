#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << " @@@   @@@ " << '\n';
        cout << "@   @ @   @" << '\n';
        cout << "@    @    @" << '\n';
        cout << "@         @" << '\n';
        cout << " @       @ " << '\n';
        cout << "  @     @  " << '\n';
        cout << "   @   @   " << '\n';
        cout << "    @ @    " << '\n';
        cout << "     @     " << '\n';
    }
}