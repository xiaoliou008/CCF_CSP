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
	����ԭ��
	������ǿ���64�����
	�ȽϺõ��ǿ��ǰ������������λ�ã�ÿ��λ���Ƿ��ǳ˳���
	����ʱֻ�����������������͵��
	�����������
	��ʵ��ʱ����̫����
	Ҫ�ǲ���һ�£�ÿ������ļ���������֪���Բ�����
	Ӳ�ǲ����㣬��һ�е���
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
//	�������˳����ˣ�Ҫע����źͳ����ļ���˳���ǲ�ͬ��
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
