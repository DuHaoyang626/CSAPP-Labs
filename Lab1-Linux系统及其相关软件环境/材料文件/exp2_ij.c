#include<stdio.h>

void copyij(int src[2048][2048],int dst[2048][2048]) {
    int i,j;
    for(i=0;i<2048;i++) {
        for(j=0;j<2048;j++) {
            dst[i][j]=src[i][j];
        }
    }
}
void copyji(int src[2048][2048],int dst[2048][2048]) {
    int i,j;
    for(j=0;j<2048;j++) {
        for(i=0;i<2048;i++) {
            dst[i][j]=src[i][j];
        }
    }
}
int src[2048][2048]={0};
int dst[2048][2048];
int main() {
    copyij(src,dst);
    return 0;
}

