#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned char;
    FILE *fp;
    fp=fopen("trail", "r");
    if(!fp)
    {
        printf("Unable to open file");
        exit(1);
    }
    fclose(fp);
    return 0;
}