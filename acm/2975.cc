#include<stdio.h>
#include<stdlib.h>
int main()
{
	int b, m;
	char c;
	while (1) {
		scanf("%d %c %d", &b, &c, &m);
		if (b == 0 && c == 'W'&&m == 0) break;
        b += (c =='W')? -m : m;
		if (b<-200) printf("Not allowed\n");
        else printf("%d\n",b);
	}
	return 0;
}
