#include<iostream>
#include<list>
using namespace::std;

struct window{
	window() = default;
	window(int a, int b, int c, int d, int l) : x1(a), y1(b), x2(c), y2(d), label(l) {}	//Ã»ÓÐ·âºÅ 
	int x1, y1, x2, y2, label;
};

int main()
{
	list<window> windows;
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		window win(a, b, c, d, i);
		windows.push_front(win);
	}
	while(M-- > 0){
		int x, y;
		cin >> x >> y;
		bool is_window = false;
		for(auto it = windows.begin(); it != windows.end(); it++){
			if(it->x1 <= x && it->y1 <= y && it->x2 >= x && it->y2 >= y){
				is_window = true;
				cout << it->label << endl;
				window w = *it;
				windows.erase(it);
				windows.push_front(w);
				break;
			}
		}
		if(!is_window) cout << "IGNORED" << endl;
	}
	return 0;
}
