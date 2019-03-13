#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> height(n);
	vector<int> h(n);
	for(int i=0;i<n;i++)
		cin >> h[i];
	for(int i=0;i<n;i++)
	{
		int max_h = -1;
		for(int j=0;j<n;j++)
		{
			if(j<i)
				height[i].push_back(0);
			else{
				if(max_h > h[j] || max_h < 0){
					max_h = h[j];
					height[i].push_back(max_h);
				}
				else height[i].push_back(max_h);
			}
		}
	}
	int max_s = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(height[i][j]*(j+1-i) > max_s)
				max_s = height[i][j] * (j+1-i);	
		}
	}
	cout << max_s << endl;
	return 0;
}
