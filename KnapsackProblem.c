/*
 4
 20 30 50 10
 2  5 10  5
 16
 
 T為最大總價值、q為達到最大總價值之項目總個數,而(i1,i2,...,iq)項目列表 (由小到大排列)
 
 
 v[]  w[]  i\j  0  1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16
 0    0  0   0   0   0   0   0   0   0   0    0    0    0    0    0    0    0
 20    2   1    0x 0  20  20  20  20  20  20  20  20   20   20   20   20   20   20   20    done
 30    5   2    0  0  20  20  20  30x 30  50  50  50   50   50   50   50   50   50   50    =>2
 50   10   3    0  0  20  20  20  30  30  50  50  50   50   50   70   70   70   80x  80    =>3
 10    5   4    0  0  20  20  20  30  30  50  50  50   50   50   70   70   70   80   80x
 
 
 i=0   =>沒有東西可以偷    =>包包無論負重多少    =>價值都是0
 n     有n個東西可以偷     包包負重<東西       =>不能偷這個東西
 包包負重>=東西     =>取  偷  和  不偷  的最大價值
 
 */

#include<stdio.h>

int max(int a,int b){
    if (a>b) return a;
    else return b;
}

int main(){
    
    int n, W, I[100], i, j, T;
    int v[101],w[101],ans[101][101];
    
    scanf("%d",&n);
    for (i=1; i<=n; i++) I[i]=i;
    for (i=1; i<=n; i++) scanf("%d",&v[i]);
    for (i=1; i<=n; i++) scanf("%d",&w[i]);
    scanf("%d",&W);
    
    for (i=0; i<=n; i++) {
        for (j=0; j<=W; j++) {
            if (i==0 || j==0) ans[i][j]=0;
            else if(j<w[i]) ans[i][j]=ans[i-1][j];
            else ans[i][j]=max(ans[i-1][j],ans[i-1][j-w[i]]+v[i]);
        }
    }
    
    T=ans[n][W];
    printf("%d\n",T);
    
    i=0;
    while (W>0) {
        if (ans[n][W]==ans[n-1][W]) n--;
        else if (ans[n][W]==ans[n][W-1]) W--;
        else {
            I[i]=n;
            W-=w[n];
            i++;
            n--;
        }
    }
    printf("%d\n",i);
    printf("(");
    i--;
    for (; i>=0; i--) {
        printf("%d",I[i]);
        if (i>0) printf(",");
    }
    printf(")");
    
    return 0;
}