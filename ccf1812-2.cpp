#include<iostream>
using namespace std;
int main()
{
	unsigned int r, y, g;
	cin >> r >> y >> g;
	unsigned int n;
	cin >> n;
	unsigned long long time_all = 0;
	for(unsigned int i=0;i<n;i++)
	{
		unsigned k, t;
		unsigned rest = time_all % (r+y+g);
		cin >> k >> t;
		if(!k)		//��· 
			time_all += t;
		else if(k == 1){	//��� 
			if(r-t+rest < r)		//��Ϊ��� 
				time_all += r - (r-t+rest);
			else if(r-t+rest < r+g)	//Ϊ�̵� 
				time_all += 0;
			else		//Ϊ�Ƶƻ���һ����� 
				time_all += 2*r+g+y - (rest+r-t);
		}
		else if(k == 2){	//�Ƶ� 
			if(y-t+rest < r+y)
				time_all += r+y - (rest+y-t);
			else if(y-t+rest < r+y+g)
				time_all += 0;
			else
				time_all += 2*r+2*y+g - (rest+y-t);
		}
		else if(k == 3){	//�̵�
			if(g-t+rest < g)
				time_all += 0;
			else if(g-t+rest < r+g+y)
				time_all += r+g+y - (rest+g-t);
			else
				time_all += 0; 
		}
	}
	cout << time_all;
	return 0;
}
