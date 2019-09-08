#include<iostream>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace::std;

const int max_rc = 50;
char area[max_rc+5][max_rc+5], reach[max_rc+5][max_rc+5], stuck[max_rc+5][max_rc+5];
int start_x, start_y, end_x, end_y;
int r, c;

void dfs_forward(int x, int y)
{
	reach[x][y] = 1;
//	printf("Reach at x = %d, y = %d\n", x, y);
	if(area[x][y] == '+' || area[x][y] == 'S' || area[x][y] == 'T'){
		if(x > 0 && !reach[x-1][y] && area[x-1][y] != '#')
			dfs_forward(x-1, y);
		if(x < r-1 && !reach[x+1][y] && area[x+1][y] != '#')
			dfs_forward(x+1, y);
		if(y > 0 && !reach[x][y-1] && area[x][y-1] != '#')
			dfs_forward(x, y-1);
		if(y < c-1 && !reach[x][y+1] && area[x][y+1] != '#')
			dfs_forward(x, y+1);
	}
	else if(area[x][y] == '-'){
		if(y > 0 && !reach[x][y-1] && area[x][y-1] != '#')
			dfs_forward(x, y-1);
		if(y < c-1 && !reach[x][y+1] && area[x][y+1] != '#')
			dfs_forward(x, y+1);
	}
	else if(area[x][y] == '|'){
		if(x > 0 && !reach[x-1][y] && area[x-1][y] != '#')
			dfs_forward(x-1, y);
		if(x < r-1 && !reach[x+1][y] && area[x+1][y] != '#')
			dfs_forward(x+1, y);
	}
	else if(area[x][y] == '.'){
		if(x < r-1 && !reach[x+1][y] && area[x+1][y] != '#')
			dfs_forward(x+1, y);
	}
	else{
		cout << "Error!" << endl;
		printf("Error at x = %d, y = %d\n", x, y);
	}
	return;
}

void dfs_back(int x, int y)
{
	assert(y < c);
//	printf("Reach at x = %d, y = %d\n", x, y);
	stuck[x][y] = 1;	//1表示这里能够到达t
	if(x > 0 && !stuck[x-1][y] && area[x-1][y] != '-' && area[x-1][y] != '#')
		dfs_back(x-1, y);
	if(x < r-1 && !stuck[x+1][y] && area[x+1][y] != '-' && area[x+1][y] != '#' && area[x+1][y] != '.')
		dfs_back(x+1, y);
	if(y > 0 && !stuck[x][y-1] && area[x][y-1] != '|' && area[x][y-1] != '#' && area[x][y-1] != '.')
		dfs_back(x, y-1);
	if(y < c-1 && !stuck[x][y+1] && area[x][y+1] != '|' && area[x][y+1] != '#' && area[x][y+1] != '.')
		dfs_back(x, y+1);
	return;
}

void print_reach(void)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ", reach[i][j]);
		}
		cout << endl;
	}
}
void print_stuck(void)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ", stuck[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	cin >> r >> c;
	getchar();
	memset(reach, 0, sizeof(reach));
	memset(stuck, 0, sizeof(stuck));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			area[i][j] = getchar();
			if(area[i][j] == 'S'){
				start_x = i;
				start_y = j;
			}
			else if(area[i][j] == 'T'){
				end_x = i;
				end_y = j;
			}
		}
		getchar();
	}
	dfs_forward(start_x, start_y);
//	printf("Finish forward dfs!\n");
//	printf("end_x = %d, end_y = %d, reach[end_x][end_y] = %d\n", end_x, end_y, reach[end_x][end_y]);
	if(!reach[end_x][end_y])
		cout << "I'm stuck!" << endl;
	else{
		dfs_back(end_x, end_y);
		int cnt = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(reach[i][j] && !stuck[i][j])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
//	print_reach();
//	cout << endl;
//	print_stuck();
	return 0;
}
