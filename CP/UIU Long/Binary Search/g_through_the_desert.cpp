#include <stdio.h>

char event[55];
int val[55];
int km[55];
int n;
char can(double fuel)
{
    double init = fuel;
    int cons = 0;
    int ckm = 0;
    int leek = 0;
    int i;
    for(i=0;i<n;i++)
    {
        fuel=fuel-(km[i]-ckm)*leek-(km[i]-ckm)/100.00*cons;
        if(fuel<0)
            return 0;
        if(event[i]=='F')
            cons = val[i];
        else if(event[i]=='L')
                leek++;
        else if(event[i]=='M')
                leek = 0;
        else if(event[i]=='G'&&fuel>=0)
                fuel = init;
        ckm = km[i];
    }
    return 1;
}
int main()
{
    char inp[100],s1[20],s2[20];
    int c,x,a;
    double hi,lo,mid;
    n = 0;
    while(gets(inp))
    {
        x = sscanf(inp,"%d %s %s %d",&a,s1,s2,&c);
        if(x==4&&!a&&!c)
            break;
        if(x==2&&s1[0]=='G')
        {
            km[n]=a;
            event[n]='g';
            n++;
            hi = 10000;
            lo = 0;
            while(hi-lo>1e-9)
            {
                mid = (hi+lo)/2;
                if(can(mid))
                    hi = mid;
                else
                    lo = mid;
            }
            printf("%.3lf\n",(hi+lo)/2);
            n = 0;
        }
        else
        {
            if(x<=3)
            {
                km[n]=a;
                event[n]=s1[0];
                n++;
            }
            if(x==4)
            {
                km[n]=a;
                event[n]=s1[0];
                val[n]=c;
                n++;
            }
        }
    }
    return 0;
}
