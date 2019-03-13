#include<iostream>
#include<vector>
using namespace std;
unsigned int all_number(int, int, int, int, int);
unsigned int power[1001];		//制表 
unsigned int a[1001][8];		//unsigned不能少 
int main()
{
	int k;
	cin >> k;
	power[0] = 1;
	for(int i=1;i<=1000;i++)
		power[i] = power[i-1]*2 % 1000000007;
	for(int i=0;i<8;i++)
		a[0][i] = 0;
	for(int i=0;i<8;i++){
		if(i<5) a[1][i] = 0;
		else if(i<7) a[1][i] = 1;
		else a[1][i] = 2;
	}
	a[2][0] = 0;	a[2][1] = 1;
	a[2][2] = 0;	a[2][3] = 2;
	a[2][4] = 0;	a[2][5] = 4;
	a[2][6] = 4;	a[2][7] = 4;
	for(int i=3;i<=1000;i++)
	{
		a[i][0] = (a[i-1][0]+a[i-1][1]+a[i-1][3]) % 1000000007;
		a[i][1] = (a[i-1][5]+a[i-1][1]) % 1000000007;
		//a[i][2] = 0;
		a[i][3] = (2*a[i-1][3]+a[i-1][5]+a[i-1][6]) % 1000000007;
		//a[i][4] = 0;
		a[i][5] = (2*a[i-1][5]+power[i-1]) % 1000000007;
		a[i][6] = (2*a[i-1][6]+power[i-1]) % 1000000007;
		a[i][7] = power[i];
	}
	unsigned int all = a[k-1][0] % 1000000007;
	cout << all << endl;
	//cout << all_number(k-1,0,0,1,0) << endl;
	return 0;
}
unsigned int all_number(int k, int zero, int one, int two, int three)
{
	int sum = 4-(zero+one+two+three);	//剩下多少没选 
	if(!sum){
		return power[k];
	}
	else if(k == sum){
		if(k == 3)
			return 3;
		else if(k == 2){
			if(three)		//剩下0和1，只有一种排法 
				return 1;
			else 
				return 2;
		}
		else if(k == 1){
			if(!zero)
				return 0;
			else 
				return 1;
		}
		else return 0;
	}
	else{
		if(one){
			if(!zero) return 0;
			else{		//三必定没选，否则四个数都选了 
				return (2*all_number(k-1,1,1,1,0) + all_number(k-1,1,1,1,1)) % 1000000007;
			}
		}
		else{
			if(three)
				return (all_number(k-1,1,0,1,1) + all_number(k-1,zero,1,1,1) + all_number(k-1,zero,0,1,1)) % 1000000007;
			else
				return (all_number(k-1,1,0,1,0) + all_number(k-1,zero,1,1,0) + all_number(k-1,zero,0,1,0) + all_number(k-1,zero,0,1,1)) % 1000000007;
		}
	}
	cout << "error" << endl;
	return 0;	//理论上不会运行这一句 
}

