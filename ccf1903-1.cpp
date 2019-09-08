#include<iostream>
#include<cstdio>
#include<vector>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int len = a.size();
	if(len % 2){
		int first = a[0], last = a.back(), mid = a[len / 2];
		if(first >= last)
			printf("%d %d %d", first, mid, last);
		else
			printf("%d %d %d", last, mid, first);
	}
	else{
		int first = a[0], last = a.back(), mid1 = a[len / 2 - 1], mid2 = a[len / 2];
		if((mid1 + mid2) % 2){
			double mid = (mid1 + mid2) / 2.0;
			if(first >= last)
				printf("%d %.1f %d", first, mid, last);
			else
				printf("%d %.1f %d", last, mid, first);
		}
		else{
			if(first >= last)
				printf("%d %d %d", first, (mid1 + mid2) / 2, last);
			else
				printf("%d %d %d", last, (mid1 + mid2) / 2, first);
		}
	}
	return 0;
}
