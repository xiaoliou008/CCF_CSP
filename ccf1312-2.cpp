#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string isbn;
	getline(cin, isbn);
	int weight = 1, test = 0;	//ШЈжи
	for(auto a : isbn)
	{
		if(isdigit(a))
			test += (a-'0') * weight++;
		if(weight > 9) break;
	}
	test %= 11;
	char &ed = *(isbn.end()-1);
	if(test < 10){
		if(test == (ed-'0'))
			cout << "Right";
		else{
			ed = test + '0';
			cout << isbn;
		}
	}
	else{
		if(ed == 'X')
			cout << "Right";
		else{
			ed = 'X';
			cout << isbn;
		}
	}
	return 0;
}
