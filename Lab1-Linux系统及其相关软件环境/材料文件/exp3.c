#include <stdio.h>
void madd(int a[100],int b[100],int c[100]) {
    for(int i=0;i<100;i++) {
        c[i] = a[i] + b[i];
    }
}
int main() {
    int a[100],b[100],c[100];
    int x=1,y=8;//本人学号2023211198,x=1,y=8
    for(int i=0;i<100;i++) {
        a[i] = i-50;
        b[i] = i+y;
    }
    madd(a,b,c);
    return 0;
}
