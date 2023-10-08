#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf ("Ban can it nhat mot tu \n");
		return 1;
	}
	for (int i = argc - 1 ; i > 0 ; i--)
		printf("%s ", argv[i]);
	return 0;	
}
