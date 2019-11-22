#include<stdio.h>
#include "head.h"
#include<stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int retexpr;
	int retmatch;

        //const char string[] = "abcb";
        //printf("start\n");
        //const char patt[] = "[ab][^ab]";
        retexpr= validate_expr(argv[2],strlen(argv[2]));
	if(retexpr == -1)
	{
		printf("given expr is not valid\n");
		exit(0);
	}
	printf("validate_complete\n");
	comp(argv[2],strlen(argv[2]));
        retmatch = match(argv[1], strlen(argv[1]));
        if (retmatch == -1)
                {
                        printf("not  matched\n");
                }
	else
	{
		printf("matched\n");
	}
        return 0;
}

