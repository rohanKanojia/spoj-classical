#include<iostream>
#define _ std::
#define f(i, j) for(i=0;i<=j;i++)
int a[100][100],T,N,i,j,m;main(){_ cin>>T;while(T--){_ cin>>N;for(i=0;i<N;i++)f(j,i)_ cin>>a[i][j];for(i=N-2;i>=0;i--)f(j,i)a[i][j]+=_ max(a[i+1][j],a[i+1][j+1]);_ cout<<a[0][0]<<'\n';}}
