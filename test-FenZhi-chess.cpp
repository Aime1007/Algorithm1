#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int count=1,board[100][100];

void cover(int tr,int tc,int dr,int dc,int size);
int main() {
    int size;
    cin>>size;
    int dr, dc;
    cin >> dr >> dc;
    cover(0, 0, dr, dc, size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cout << setw(5) << setiosflags(ios::left) << board[i][j];
        cout << endl;
    }
    return 0;
}

void cover(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return ;
    int t=count++;
    int s=size/2;
    if(dr<tr+s && dc<tc+s) {
    	cover(tr, tc, dr, dc, s);
	}
	else {
		board[tr+s-1][tc+s-1]=t;
		cover(tr, tc, tr+s-1, tc+s-1, s);
	}
	if(dr<tr+s && dc>=tc+s) {
		cover(tr, tc+s, dr, dc, s);
	}
	else {
		board[tr+s-1][tc+s]=t;
		cover(tr, tc+s, tr+s-1, tc+s, s);
	}
	if(dr>=tr+s && dc<tr+s) {
		cover(tr+s, tc, dr, dc, s);
	}
	else {
		board[tr+s][tc+s-1]=t;
		cover(tr+s, tc, tr+s, tc+s-1, s);
	}
	if(dr>=tr+s && dc>=tc+s) {
		cover(tr+s, tc+s, dr, dc, s);
	}
	else {
		board[tr+s][tc+s]=t;
		cover(tr+s, tc+s, tr+s, tc+s, s);
	}
}
