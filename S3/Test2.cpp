#include<stdio.h>
void f(int n) {
 if(n == 0) {
 printf("A");
 return;
 }
 if(n == 1) {
 printf("B");
 return;
 }
 f(n - 1);
 f(n - 2);
}
int main()
{
 f(5);
 return 0;
}
