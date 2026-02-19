#include <iostream>
#include <random>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 10'000;
mt19937 gen(random_device{}());
uniform_int_distribution<int> dis(1, MAX);

int Value(char c)
{
    array<bool, MAX + 1> used = { false, };
    while (true)
    {
        int t;
        while (true)
        {
            t = dis(gen);
            if (used[t]) continue;

            used[t] = true;
            break;
        }
        cout << '?' << ' ' << c << ' ' << t << endl;

        bool f;
        cin >> f;
        if (f) return t;
    }
}

int main()
{
    FastIO;

    int a = Value('A'), b = Value('B');
    cout << '!' << ' ' << a + b << endl;
}