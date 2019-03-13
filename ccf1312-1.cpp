#include<iostream>
using namespace std;
int main()
{
	int n, s[10020] = {0}, max_num = 0, n_max = 0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		s[x]++;
		if(s[x] > n_max){
			max_num = x;
			n_max = s[x];
		}
		else if(s[x] == n_max){
			if(x < max_num)
				max_num = x;
		}
	}
	cout << max_num;
	return 0;
}
