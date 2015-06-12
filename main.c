#include "stdio.h"
#include "stdlib.h"

void print_all(int **ary, int n, int m){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++)
            printf("%d ", ary[i][j]);
        printf("\n");
    }
}

int cmp(const void *pa, const void *pb){
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    int idx = 0;
    while (a[idx] == b[idx]) {
        idx++;
        if (a[idx] == -1)
            return 0;
    }
    return a[idx] - b[idx];
}

int main() {
    int n, m, i, j, **ary, *pAry;
    scanf("%d %d", &n, &m);
    ary = malloc(n*sizeof(int *) + n*(m+1)*sizeof(int));
    for (i=0, pAry=(int *)(ary+n); i<n; i++, pAry+=(m+1)){
        ary[i] = pAry;
        ary[i][m] = -1;
    }
    
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%d", &ary[i][j]);
    
    qsort(ary, n, sizeof(int *), cmp);
    print_all(ary, n, m);
    return 0;
}
