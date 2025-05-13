/*
#include <stdio.h>

int main(){
 double unit;
 scanf("%lf",&unit);
 printf("ebill: %.3lf", (unit*10));
    return 0;
}

#include <stdio.h>

int main(){
 int num = 11283;
 //printf("%d\n", (num%10 + num%10 + num%10 + num%10 + num%10));
 printf("%d%d%d%d%d", num%10, (num%100)/10, (num%1000)/100, (num%10000)/1000, (num%100000)/10000);
    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    float a = 1, b = 2, c = 1;
    float d = (b * b) - (4 * a * c);
    if(d >= 0) {
        float r1 = (-b + sqrt(d)) / (2 * a);
        float r2 = (-b - sqrt(d)) / (2 * a);
        printf("%.2f %.2f", r1, r2);
    } else {
        float re = -b / (2 * a);
        float img = sqrt(-d) / (2 * a);
        printf("%.2f + %.2fi  %.2f - %.2fi\n", re, img, re, img);
    }
    return 0;
}
*/

#include <stdio.h>
int main()
{  int a = 100;
    printf("++a = %d\n", ++a);
    printf("a++ = %d\n", a++);
    printf("--a = %d\n", --a);
    printf("a-- = %d\n", a--);
    return 0;
}

