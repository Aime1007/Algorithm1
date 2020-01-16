#include <iostream>
using namespace std;
int extgcd(int a, int b, int& x, int& y) {
	int d=a;
	if(b!=0) {
		d = extgcd(b, a%b, y, x);
		y -= (a/b)*x;
	}
	else {
		x=1; y=0;
	}
	return d;
}

int main() {
	int a,b,x,y;
    int ans[4]={0};
    cin>>a>>b;
    if(extgcd(a,b,x,y)!=1)
        cout<<"-1"<<endl;
    else
    {
        if(x<0) ans[2]=-x;
        else ans[0]=x;
        if(y<0) ans[3]=-y;
        else ans[1]=y;
        for(int i=0;i<4;i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}

