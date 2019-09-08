#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int plu(int, int);
int sub(int, int);
int mul(int, int);
int divi(int, int);
using PF = int(*)(int, int);
PF compute[3];
map<char, int> com = {{'+', 0},{'-', 1},
					  {'x',2}, {'/',3}};
int cal(int a, int b, char m);
/*****
	错误原因：
	最暴力的是考虑64种情况
	比较好的是考虑八种情况（三个位置，每个位置是否是乘除）
	考试时只考虑了四种情况，想偷懒
	结果根本不对
	其实当时还是太慌了
	要是测试一下，每种情况的计算结果，就知道对不对了
	硬是不肯算，就一行的事
*****/ 


int main()
{
	int n;
	cin >> n;
	compute[0] = plu;
	compute[1] = sub;
	compute[2] = mul;
	compute[3] = divi;
	while(n-- > 0)
	{
		int res = 0;
		char old[8];
		scanf("%s", old);
		char a = old[0], b = old[2], c = old[4], d =old[6];
		char x = old[1], y = old[3], z = old[5]; 
		if(com[x] < 2){
			if(com[y] < 2){
				res = cal(c-'0', d-'0', z);
//				res = cal(res, b-'0', y);
//				res = cal(res, a-'0', x);
//	上面计算顺序错了，要注意减号和除法的计算顺序是不同的
				res = cal(b-'0', res, y);
				res = cal(a-'0', res, x);
			}
			else{
				res = cal(b-'0', c-'0', y);
				res = cal(res, d-'0', z);
//				res = cal(res, a-'0', x);
				res = cal(a-'0', res, x);
			}
		}
		else{
			if(com[y] < 2){
				res = cal(a-'0', b-'0', x);
				int res2 = cal(c-'0', d-'0', z);
				res = cal(res, res2, y);
			}
			else{
				res = cal(a-'0', b-'0', x);
				res = cal(res, c-'0', y);
				res = cal(res, d-'0', z);
			}
		}
//		cout << res << endl;
		printf("%d\n", res);
//		if(res == 24)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
	}
	return 0;
}
int plu(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}
int divi(int a, int b)
{
	return a/b;
}
int cal(int a, int b, char m)
{
	return (compute[com[m]])(a, b);
}
