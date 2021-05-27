/*
https://mp.weixin.qq.com/s/WvAsjLhgGlRJsxFPLAI3lw
https://www.tutorialspoint.com/compile_c_online.php
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>
int main()
{
 char *p1 = (char *)malloc(1024*1000000);
 strcpy(p1, "这里是堆区");
 printf("%s\n", p1);
 free(p1);
}

/*
$gcc -o main *.c
$main
这里是堆区
*/