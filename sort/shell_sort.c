#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_SIZE 1000

typedef struct
{
    int data[MAX_SIZE + 1]; // data[0]作为哨兵
    int length;
} List;

// 交换list中下标为i和下标为j两个位置的值
void swap(List *list, int i, int j)
{
    int tmp = list->data[i];
    list->data[i] = list->data[j];
    list->data[j] = tmp;
}

void print_list(List list)
{
    int i;
    for (i = 1; i <= list.length; i++)
    {
        printf("%d\t", list.data[i]);
    }
    puts("");
}

void init_list(List *list)
{
    int d[10] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 5};
    int i;
    for (i = 0; i < 10; i++)
    {
        list->data[i + 1] = d[i];
    }
    list->length = 10;
}
// 希尔排序原理可参考附件:希尔排序.png
void shell_sort(List *list)
{
    int increment = list->length / 2 + 1;
    int i,j;
    while (increment >= 1)
    {
        for (i = 1; i <= list->length; ++i)
        {
            j = i;
            list->data[0] = list->data[j];// 暂存
            while(j - increment >= 1 && list->data[j - increment] > list->data[0])
            {
                list->data[j] = list->data[j - increment];
                j -= increment;
            }
            list->data[j] = list->data[0];
        }
        increment = increment / 2;
    }
}

int main(int argc, char const *argv[])
{
    List list;

    puts("初始化list");
    init_list(&list);
    print_list(list);
    puts("after shell_sort:");
    shell_sort(&list);
    print_list(list);

    return 0;
}
