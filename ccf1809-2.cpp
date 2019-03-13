#include<stdio.h>
int main()
{
	int n,i,j,sum=0,a[2020],b[2020],c[2020],d[2020];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	for(i=0;i<n;i++) scanf("%d%d",&c[i],&d[i]);
	i=j=0;
	while(i<n && j<n)
	{
		if(a[i]<c[j])
		{
			if (b[i]<=c[j]) i=i+1;
			else if(b[i]<=d[j]) {sum = sum+b[i]-c[j]; i=i+1;}
			else {sum = sum+d[j]-c[j]; j=j+1;}
		}
		else if(a[i]>c[j])
		{
			if (d[j]<=a[i]) j=j+1;
			else if(d[j]<=b[i]) {sum = sum+d[j]-a[i]; j=j+1;}
			else {sum = sum+b[i]-a[i]; i=i+1;}
		}
		else
		{
			if(b[i]>d[j]) {sum = sum+d[j]-c[j]; j=j+1;}
			else if(b[i]<d[j]) {sum = sum+b[i]-a[i]; i=i+1;}
			else {sum = sum+b[i]-a[i]; i=i+1; j=j+1;}
		}
	}
	printf("%d",sum);
	return 0;
}
