#include <iostream>
#include <array>
#include <string>
#include <random>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<string, 2> name = { "Yonsei","Korea" };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> rand(0, 1);

    string result = name[rand(gen)];
    cout << result << '\n';
}