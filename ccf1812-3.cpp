#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ip
{
	unsigned a[4];
	unsigned len=0;
	unsigned long long num=0;	//否则会造成严重的溢出问题 
};
unsigned long long power[33];
bool cmp(ip, ip);
bool ip_equal(ip, ip);
void read_ip(ip &);
void print_ip(vector<ip>::iterator, vector<ip>::iterator);
int main()
{
	unsigned n;
	cin >> n;
	vector<ip> ips;
	power[0] = 1;
	for(int i=1;i<33;i++)		//制表 
		power[i] = 2*power[i-1];
	for(unsigned i=0;i<n;i++)
	{
		ip ip_i;
		read_ip(ip_i);
		ips.push_back(ip_i);
	}
	sort(ips.begin(), ips.end(), cmp);
	auto delp = unique(ips.begin(), ips.end(), ip_equal);
	ips.erase(delp, ips.end());
	vector<ip> oip;
	oip.reserve(ips.size());
	for(auto iter = ips.begin();iter != ips.end();iter++)
	{
		oip.push_back(*iter);
		while(oip.size() > 1 && oip.rbegin()->num - (oip.rbegin()+1)->num == power[32 - (oip.rbegin()+1)->len]
				&& !((oip.rbegin()+1)->num % power[33-(oip.rbegin()+1)->len]) && oip.rbegin()->len == (oip.rbegin()+1)->len)
		{
			ip temp(*(oip.rbegin()+1));
			temp.len--;
			oip.pop_back();
			*(oip.rbegin()) = temp;
		}
		//print_ip(oip.begin(), oip.end());
	}
	print_ip(oip.begin(), oip.end());
	return 0;
}
void read_ip(ip &x)
{
	cin >> x.a[3];
	int ch = cin.get(), i=2;
	while(ch == '.')
	{
		cin >> x.a[i--];
		ch = cin.get();
	}
	if(ch == '/')
		cin >> x.len;
	else
		x.len = (3-i)*8;
	while(i >= 0)
		x.a[i--] = 0;
	x.num = 16777216*x.a[3] + 65536*x.a[2] + 256*x.a[1] + x.a[0];
	return;
}
bool cmp(ip x, ip y)
{
	if(x.num < y.num) return true;
	else if(x.num > y.num) return false;
	else return (x.len < y.len);
}
bool ip_equal(ip x, ip y)
{
	return (y.num-x.num < power[32-x.len]);
}
void print_ip(vector<ip>::iterator bg, vector<ip>::iterator ed)
{
	for(auto iter = bg;iter != ed;iter++)
	{
		ip &t = *iter;
		cout << t.a[3] << '.' << t.a[2] << '.' << t.a[1] << '.'
			<< t.a[0] << '/' << t.len << endl;
	}
	return;
}

/*90分版本
for(auto iter = ip_out.begin();iter != ips.end();iter++)
	{
		if(iter+1 == ips.end()){
			cout << iter->a[3] << '.' << iter->a[2] << '.'
				<< iter->a[1] << '.' << iter->a[0]
				<< '/' << iter->len << endl;
		}
		else if(((iter+1)->len == iter->len) && ((iter+1)->num - iter->num == power[32 - iter->len]) && !(iter->num % power[33 - iter->len]))
			{
				cout << iter->a[3] << '.' << iter->a[2] << '.'
					<< iter->a[1] << '.' << iter->a[0]
					<< '/' << iter->len-1 << endl;
				iter++;
			}
		else{
			cout << iter->a[3] << '.' << iter->a[2] << '.'
				<< iter->a[1] << '.' << iter->a[0]
				<< '/' << iter->len << endl;
		}
	}
*/ 
