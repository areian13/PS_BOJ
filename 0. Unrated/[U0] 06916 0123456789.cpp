#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<string, 5> display =
    {
        "",			//0
        " * * *",	//1
        "*     *",	//2
        "      *",	//3
        "*"			//4
    };

    array<array<int, 9>, 10> nums =
    {
        array<int, 9>
        { 1,2,2,2,0,2,2,2,1 },
        { 0,3,3,3,0,3,3,3,0 },
        { 1,3,3,3,1,4,4,4,1 },
        { 1,3,3,3,1,3,3,3,1 },
        { 0,2,2,2,1,3,3,3,0 },
        { 1,4,4,4,1,3,3,3,1 },
        { 1,4,4,4,1,2,2,2,1 },
        { 1,3,3,3,0,3,3,3,0 },
        { 1,2,2,2,1,2,2,2,1 },
        { 1,2,2,2,1,3,3,3,1 },
    };

    int n;
    cin >> n;

    for (int i = 0; i < 9; i++)
        cout << display[nums[n][i]] << '\n';
}