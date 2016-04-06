// Problem#: 17133
// Submission#: 4369938
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#define INF 0x3f3f3f
#define max 200+10
int map[max][max];
int city,road;
int start,end;
void floyd()
{
    int k,i,j;
    for(k=0;k<city;k++)
    {
        for(i=0;i<city;i++)
        {
            for(j=0;j<city;j++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }
    if(map[start][end]==INF)
    printf("-1\n");
    else
    printf("%d\n",map[start][end]);
} 
int main()
{
    int i,j,x,y,c;
    while(scanf("%d%d",&city,&road)!=EOF)
    {
        for(i=0;i<city;i++)
        {
            for(j=0;j<city;j++)
            {
                if(i==j)
                map[i][j]=0;
                else
                map[i][j]=INF;
            }
        }
        while(road--)
        {
            scanf("%d%d%d",&x,&y,&c);
            if(map[x][y]>c)
            {
                map[x][y]=map[y][x]=c;
            }
        }
        scanf("%d%d",&start,&end);
        floyd();
    }
    return 0;
}                                 