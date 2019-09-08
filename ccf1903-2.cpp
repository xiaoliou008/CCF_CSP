#include<iostream>
#include<cstdio>
#include<string>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	while(n-- > 0){
		int num[4], res = 0;
		char str[4] = {0};
		scanf("%d%c%d%c%d%c%d", &num[0], &str[0], &num[1], &str[1], &num[2], &str[2], &num[3], &str[3]);
		string s(str);
		if(s == "+++")	res = num[0] + num[1] + num[2] + num[3];
		else if(s == "++-") res = num[0] + num[1] + num[2] - num[3];
		else if(s == "++x") res = num[0] + num[1] + num[2] * num[3];
		else if(s == "++/") res = num[0] + num[1] + num[2] / num[3];
		else if(s == "+-+") res = num[0] + num[1] - num[2] + num[3];
		else if(s == "+--") res = num[0] + num[1] - num[2] - num[3];
		else if(s == "+-x") res = num[0] + num[1] - num[2] * num[3];
		else if(s == "+-/") res = num[0] + num[1] - num[2] / num[3];
		else if(s == "+x+") res = num[0] + num[1] * num[2] + num[3];
		else if(s == "+x-") res = num[0] + num[1] * num[2] - num[3];
		else if(s == "+xx") res = num[0] + num[1] * num[2] * num[3];
		else if(s == "+x/") res = num[0] + num[1] * num[2] / num[3];
		else if(s == "+/+") res = num[0] + num[1] / num[2] + num[3];
		else if(s == "+/-") res = num[0] + num[1] / num[2] - num[3];
		else if(s == "+/x") res = num[0] + num[1] / num[2] * num[3];
		else if(s == "+//") res = num[0] + num[1] / num[2] / num[3];
		else if(s == "-++") res = num[0] - num[1] + num[2] + num[3];
		else if(s == "-+-") res = num[0] - num[1] + num[2] - num[3];
		else if(s == "-+x") res = num[0] - num[1] + num[2] * num[3];
		else if(s == "-+/") res = num[0] - num[1] + num[2] / num[3];
		else if(s == "--+") res = num[0] - num[1] - num[2] + num[3];
		else if(s == "---") res = num[0] - num[1] - num[2] - num[3];
		else if(s == "--x") res = num[0] - num[1] - num[2] * num[3];
		else if(s == "--/") res = num[0] - num[1] - num[2] / num[3];
		else if(s == "-x+") res = num[0] - num[1] * num[2] + num[3];
		else if(s == "-x-") res = num[0] - num[1] * num[2] - num[3];
		else if(s == "-xx") res = num[0] - num[1] * num[2] * num[3];
		else if(s == "-x/") res = num[0] - num[1] * num[2] / num[3];
		else if(s == "-/+") res = num[0] - num[1] / num[2] + num[3];
		else if(s == "-/-") res = num[0] - num[1] / num[2] - num[3];
		else if(s == "-/x") res = num[0] - num[1] / num[2] * num[3];
		else if(s == "-//") res = num[0] - num[1] / num[2] / num[3];
		else if(s == "x++") res = num[0] * num[1] + num[2] + num[3];
		else if(s == "x+-") res = num[0] * num[1] + num[2] - num[3];
		else if(s == "x+x") res = num[0] * num[1] + num[2] * num[3];
		else if(s == "x+/") res = num[0] * num[1] + num[2] / num[3];
		else if(s == "x-+") res = num[0] * num[1] - num[2] + num[3];
		else if(s == "x--") res = num[0] * num[1] - num[2] - num[3];
		else if(s == "x-x") res = num[0] * num[1] - num[2] * num[3];
		else if(s == "x-/") res = num[0] * num[1] - num[2] / num[3];
		else if(s == "xx+") res = num[0] * num[1] * num[2] + num[3];
		else if(s == "xx-") res = num[0] * num[1] * num[2] - num[3];
		else if(s == "xxx") res = num[0] * num[1] * num[2] * num[3];
		else if(s == "xx/") res = num[0] * num[1] * num[2] / num[3];
		else if(s == "x/+") res = num[0] * num[1] / num[2] + num[3];
		else if(s == "x/-") res = num[0] * num[1] / num[2] - num[3];
		else if(s == "x/x") res = num[0] * num[1] / num[2] * num[3];
		else if(s == "x//") res = num[0] * num[1] / num[2] / num[3];
		else if(s == "/++") res = num[0] / num[1] + num[2] + num[3];
		else if(s == "/+-") res = num[0] / num[1] + num[2] - num[3];
		else if(s == "/+x") res = num[0] / num[1] + num[2] * num[3];
		else if(s == "/+/") res = num[0] / num[1] + num[2] / num[3];
		else if(s == "/-+") res = num[0] / num[1] - num[2] + num[3];
		else if(s == "/--") res = num[0] / num[1] - num[2] - num[3];
		else if(s == "/-x") res = num[0] / num[1] - num[2] * num[3];
		else if(s == "/-/") res = num[0] / num[1] - num[2] / num[3];
		else if(s == "/x+") res = num[0] / num[1] * num[2] + num[3];
		else if(s == "/x-") res = num[0] / num[1] * num[2] - num[3];
		else if(s == "/xx") res = num[0] / num[1] * num[2] * num[3];
		else if(s == "/x/") res = num[0] / num[1] * num[2] / num[3];
		else if(s == "//+") res = num[0] / num[1] / num[2] + num[3];
		else if(s == "//-") res = num[0] / num[1] / num[2] - num[3];
		else if(s == "//x") res = num[0] / num[1] / num[2] * num[3];
		else if(s == "///") res = num[0] / num[1] / num[2] / num[3];
		
		if(res == 24) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
