#include<iostream>
using namespace std;
int main()
{
	int r, g, y;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	int time_all = 0;
	for(int i=0;i<n;i++)
	{
		int k, t;
		cin >> k >> t;
		if(!k)
			time_all += t;
		else if(k == 1)
			time_all += t;
		else if(k == 2)
			time_all += t+r;
		else if(k == 3)
			time_all += 0;
	}
	cout << time_all;
	return 0;
}
