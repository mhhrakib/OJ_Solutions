#include<stdio.h>
int main()
{
    int t,i,x1,x2,y1,y2,x,y,m;
    scanf("%d",&t);
    for(i = 1; i<=t; i++) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",i);
        while(m--) {
            scanf("%d %d",&x,&y);
            if(x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
