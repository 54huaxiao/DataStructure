// Problem#: 17135
// Submission#: 4369943
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//http://acm.hdu.edu.cn/showproblem.php?pid=2489
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=15+5;
int edge[MAX][MAX],dist[MAX],node[MAX];//node记录最终选的点 
int vale[MAX],temp[MAX],n,m;//temp记录选的m个点
double minratio;
bool mark[MAX];

int Prim(int s){
    int sum=0;
    for(int i=1;i<=m;++i)mark[temp[i]]=false,dist[temp[i]]=edge[s][temp[i]];
    mark[s]=true;
    dist[s]=0;
    for(int i=1;i<m;++i){
        int point=s;
        for(int j=1;j<=m;++j){
            if(point == s && !mark[temp[j]])point=temp[j];
            if(!mark[temp[j]] && dist[point]>dist[temp[j]])point=temp[j];
        }
        mark[point]=true;
        sum+=dist[point];
        for(int j=1;j<=m;++j){
            if(!mark[temp[j]] && edge[point][temp[j]]<dist[temp[j]])dist[temp[j]]=edge[point][temp[j]];
        }
    }
    return sum;
} 

void dfs(int k,int num){
    if(num == m){
        int ans=0;
        for(int i=1;i<=m;++i)ans+=vale[temp[i]];
        double sum=Prim(k)*1.0/ans;
        if(sum-minratio<-(1e-9)){
            minratio=sum;
            for(int i=1;i<=m;++i)node[i]=temp[i];
        }
        return;
    }
    if(n-k+num<m)return;
    for(int i=k+1;i<=n;++i){
        temp[num+1]=i;
        dfs(i,num+1);
    }
}

int main(){
    while(cin>>n>>m,n+m){
        minratio=INF*1.0;
        for(int i=1;i<=n;++i)cin>>vale[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>edge[i][j];
            }
        }
        for(int i=1;i<=n;++i){
            temp[1]=i;
            dfs(i,1);
        }
        for(int i=1;i<m;++i)cout<<node[i]<<' ';
        cout<<node[m]<<endl;
    }
    return 0;
}                                 