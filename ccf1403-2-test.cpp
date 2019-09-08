#include<iostream>
#include<fstream>
#include<cstdio>
#include<random>
#include<utility>		//swap
using namespace::std;

int main()
{
	ofstream out("ccf1403-2.in");
	out << "10 10" << endl;
	default_random_engine e;
	uniform_int_distribution<unsigned> x(0, 2559), y(0, 1439);
	for(int i=0;i<10;i++){
		unsigned x1 = x(e), y1 = y(e), x2 = x(e), y2 = y(e);
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		out << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	}
	for(int i=0;i<10;i++)
		out << x(e) << ' ' << y(e) << endl;
	out.close();
	return 0;
}
