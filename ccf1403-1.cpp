#include<iostream>
#include<cstring>

const int max_num = 1000;
int num[max_num + 5];	// ÿ�����ֳ��ֵĴ��� 

int main()
{
	int N, cnt = 0;
	cin >> N;
	memset(num, 0, sizeof(num));
	while(N-- > 0){
		int x;
		cin >> x;
		if(x < 0) x = -x;
		if(!num[x]) num[x]++;	//û���ֹ� 
		else cnt++;
	}
	cout << cnt;
	return 0;
}
