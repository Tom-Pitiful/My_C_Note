#include <stdio.h>
#include <string.h>
int main()
{
    char arr1[] = "abc";
    char arr2[] = {'a', 'b', 'c' ,'\0'};      //字符串后都有一个\0表示结束标志，且不计入其长度
    
    printf("%s\t%d\n", arr1,strlen(arr1));
    printf("%s\t%d\n", arr2,strlen(arr2));

    return 0;
}
