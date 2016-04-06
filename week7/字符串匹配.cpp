// Problem#: 16217
// Submission#: 4085976
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream> 
#include <cstdio> 
using namespace std; 
int next[60010]; 
int s[60010]; 
int ss[1000000]; 
void get_next(int n) //继续优化 aaaaaaaaaa aaa 
{ 
int i, j; 
i = 0; 
j = -1; 
next[0] = -1; 
while (i < n) 
{ 
if (j == -1 || s[i] == s[j]) 
{ 
i ++; 
j ++; 
next[i] = j; 
} 
else 
j = next[j]; 
} 
} 
int main() 
{ 
int n;
 while (scanf("%d", &n) != EOF) 
{ 
int m; 
int i,j; 
for (i=0;i<n;i++) 
scanf("%d",&s[i]); 
scanf("%d",&m); 
for (i=0;i<m; i++) 
scanf("%d",&ss[i]); 
get_next(n); 
i=0; 
j=0; 
while(i<m&&j<n) 
{ 
if (ss[i]==s[j]) 
{ 
i++; 
j++; 
} 
else if(next[j]>=0) 
j=next[j]; 
else 
{ 
j=0; 
i++; 
} 
} 
if (j!=n) 
printf("no solution\n");
 else printf("%d\n",i-n); 
} 
return 0; 
}                                 