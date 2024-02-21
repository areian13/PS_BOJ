#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

int main()
{
	FastIO;

	Cout "02-521-0487";
	/*
	실제로는 그저 txt파일로 02-521-0487만을 제출했지만 부가 설명을 위해 cpp로 작성하였다.
	F12를 눌러 개발자 모드로 들어간 후 문제, 입력, 출력, 힌트 부분을 클릭하면 주석처리된 이상한 코드를 발견할 수 있다.

	각각의 내용은 다음과 같다.

	66y47KCc7J2YIOygleuLteydgA==
	7JWM66Ck7KSEIOyImCDsl4bri6Q=
	7ZWY7KeA66eMIO2ejO2KuOuKlCDsnojri6Q=
	7Z6M7Yq464qUIGh0dHBzOi8vc3RhcnRsaW5rLmlvLyDsl5Ag7J6I64qUIOOFiOOFjuOFguOFjg==
	
	꽤나 해괴망측하지만 이를 base64 디코더를 이용하여 해석하면 다음과 같다(필자도 게시글을 보고 base64에 대한 힌트를 얻었다...).
	
	문제의 정답은
	알려줄 수 없다
	하지만 힌트는 있다
	힌트는 https://startlink.io/ 에 있는 ㅈㅎㅂㅎ

	여기서 말하는 ㅈㅎㅂㅎ은 전화번호로 적혀있는 그대로 02-521-0487를 제출하면 된다...
	*/
}
// 미친 문제