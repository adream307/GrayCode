#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
   int n,i;
   unsigned long x=1;
   unsigned long y=0;
   unsigned long t=0;
   unsigned long z=0;
   if(argc!=2)
    {
        printf("Usage: graycode n,where n is int and n>0 && n<=31\n");
        return -1;    
    }
    sscanf(argv[1],"%d",&n);
    x=x<<(n-1);
    for(y=0;y<x;++y)
    {
        t = y^(y>>1);
        printf("%lx -- ",t);
        z=t;
        for(i=1;i<n;++i)
        {
            z=z>>1;
            t=t^z;    
        }
        printf("%lx\n",t);
        if(t!=y)
        {
            printf("Error at %lx\n",y);
            return -2;
        }
    }
    return 0;
}
