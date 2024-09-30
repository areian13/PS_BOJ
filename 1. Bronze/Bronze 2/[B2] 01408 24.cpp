#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_SEC (60 * 60 * 24)

int main()
{
    FastIO;

    int h1, m1, s1, h2, m2, s2;
    scanf("%02d:%02d:%02d", &h1, &m1, &s1);
    scanf("%02d:%02d:%02d", &h2, &m2, &s2);

    int sec1 = h1 * 60 * 60 + m1 * 60 + s1;
    int sec2 = h2 * 60 * 60 + m2 * 60 + s2;

    int result = (sec2 - sec1 + MAX_SEC) % MAX_SEC;
    int h3 = result / 60 / 60;
    int m3 = result / 60 % 60;
    int s3 = result % 60;
    printf("%02d:%02d:%02d\n", h3, m3, s3);
}