#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Temper(int t1, int t2, string& mode)
{
    if (mode == "heat" && t2 > t1)
        return t2;
    if (mode == "freeze" && t2 < t1)
        return t2;
    if (mode == "auto")
        return t2;
    return t1;
}

int main()
{
    FastIO;

    int t1, t2;
    string mode;
    cin >> t1 >> t2 >> mode;

    int result = Temper(t1, t2, mode);
    cout << result << '\n';
}