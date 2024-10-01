#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinDist(int ar, int ac, int br, int bc)
{
    if (ar != 0 && ac != 0)
        return 2;

    if (ar == 0)
    {
        if (br == 0 && bc < ac)
            return 3;
        else
            return 1;
    }
    if (ac == 0)
    {
        if (bc == 0 && br < ar)
            return 3;
        else
            return 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int ar, ac, br, bc;
    cin >> ar >> ac >> br >> bc;

    int result = MinDist(ar, ac, br, bc);
    cout << result << '\n';
}