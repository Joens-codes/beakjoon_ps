#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
   int cnt =0;
  char box[1000000];
while(scanf("%s",box)==1)cnt++;
printf("%d\n",cnt);
}