# include <stdio.h>
int main()
{
    int v=10;
    int *y=&v;
    printf("%p\n",&y);
    printf("%p\n",&v);
    
    // printing the value using pointer.
    printf("the value stored in pointer is:%d\n",*y);
    void *p=NULL;
         printf("The size of poiner:%ld\n",sizeof(v));
 int **pointerToPtr= &y;
    printf("%d\n",**pointerToPtr);

    return 0;

}