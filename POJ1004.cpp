#include <cstdio>
float a;
float sum=0;
int main() {
	for(int i=0; i<12; i++) {
		scanf("%f", &a);
		sum+=a;
	}
	printf("$%.2f", sum/12);
}
