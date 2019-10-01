#include <stdio.h>
#include "sort.h"
#include "tasks.h"
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include "fs.h"
#define M 1000000
#define K 1000


int comp(const void *x1, const void *x2)
{
    return *(int *)x1 - *(int *)x2;
}


int main() {


    //time check
    clock_t  t_start, t_stop, t_sort1, t_sort2;
    t_start = clock();

    int arr_len = M;

    // Malloc array
    //int *arr = (int*) malloc (sizeof(*arr) * arr_len);
    // random int to array
    //rand_arr (arr,arr_len,100);

    //print default array
    //print_arr (arr,arr_len);

    //time sort start
    t_sort1 = clock();

    //***array_sort***

    // time of 1000 items ~6500/10^-9
    //bubble_sort(arr,arr_len);

    // time of 1000 items ~3400/10^-9
    //insert_sort(arr, arr_len);

    // time of 1000 items ~2400/10^-9
    //select_sort(arr, arr_len);

    // time of 10^3 items ~245/10^-9
    // time of 10^6 items ~360/10^-6
    //merge_sort (arr,arr_len);

    // time of 1000 items ~145/10^-9
    // time of 10^6 items ~200/10^-6
    //quick_sort(arr,arr_len);

    // time of 10^6 items ~210/10^-6
    //qsort(arr,arr_len, sizeof(*arr),comp);

    //time sort stop
    t_sort2 = clock();

    //struct_print();

    listdir("/home/alex/");

    //print sort array
    //print_arr (arr,arr_len);

    // free array
    //free (arr);
    // time check
    t_stop = clock();
    printf("Sort_time is %lf\n", (double)(t_sort2 - t_sort1)/CLOCKS_PER_SEC);
    printf("All_time is %lf\n", (double)(t_stop - t_start)/CLOCKS_PER_SEC);


    return 0;
}