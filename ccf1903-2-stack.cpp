#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cctype>
#include<map>
using namespace std;

map<char, int> pri = {{'#', -1}, {'+', 0}, {'-', 0}, {'x', 1}, {'/', 1}};

int compute(int a, int b, char op)
{
	int res;
	switch(op){
		case '+' : res = a + b; break;
		case '-' : res = a - b; break;
		case 'x' : res = a * b; break;
		case '/' : res = a / b; break;
	}
	return res;
}

void debug_queue(queue<char> q)
{
	while(!q.empty()){
		cout << q.front();
		q.pop();
	}
	cout << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	while(n-- > 0){
		string e;
		cin >> e;
		e += "#";
		stack<char> t;
		t.push('#');
		queue<char> q;
		for(int i=0;i<e.length();i++){
			if(isdigit(e[i]))
				q.push(e[i]);
			else{
				while(!t.empty() && pri[e[i]] <= pri[t.top()]){
					q.push(t.top());
					t.pop();
				}
				t.push(e[i]);	// 这句不能漏 
			}
		}
//		debug_queue(q);
		stack<int> res;
		while(q.front() != '#'){
			char c = q.front();
			q.pop();
			if(isdigit(c))
				res.push(c - '0');
			else{
				int b = res.top();		// 这里的a和b的顺序一定要注意 
				res.pop();				// 减和除的顺序是关键 
				int a = res.top();
				res.pop();
				res.push(compute(a, b, c));
			}
//			printf("res.top() = %d\n", res.top());
		}
//		cout << (res.size() == 1 ? "One" : "Else") << endl;
//		printf("Answer is %d\n", res.top());
		cout << ((res.top() == 24) ? "Yes" : "No") << endl;
	}
	return 0;
}
