#include <stdio.h>
#include <string.h>
#include <argp.h>

int main(int argc,char **argv)
{
    printf("Hello!\r\n");
    return argp_parse(0,argc,argv,0,0,0);
}
