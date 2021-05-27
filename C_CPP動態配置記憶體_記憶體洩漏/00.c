/*
https://mp.weixin.qq.com/s/WvAsjLhgGlRJsxFPLAI3lw
https://www.tutorialspoint.com/compile_c_online.php
*/

#include <stdio.h>

int main()
{
 char arr_char[1024*1000000];
    arr_char[0] = '0';
}
/*
$gcc -o main *.c
$main
/usr/bin/timeout: the monitored command dumped core
sh: line 1: 182320 Segmentation fault      /usr/bin/timeout 10s main
*/