#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; 
};

List ReadInput(); 
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
List ReadInput()
{
	List L;
	//L=(LNode*)malloc(sizeof(struct LNode));
	int n,a;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a);
		L->Data[i]=a;
	}
	L->Last=n;
	return L;
}
Position BinarySearch( List L, ElementType X )
{
	int left,right,mid;
	left=1;
	right=L->Last;
	while(left<=right) {
		mid=(left+right)/2;
		if(X<L->Data[mid]) {
			right=mid-1;
		}
		else if(X>L->Data[mid]) {
			left=mid+1;
		}
		else return mid;
	}
	return NotFound;
}
