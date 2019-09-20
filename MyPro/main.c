#include <stdio.h>
#include "sort.h"
#include "tasks.h"
#include <stdlib.h>
#include <time.h>

int main() {

    struct aaa {

    }A;


    //time check
    clock_t  t_start, t_stop, t_sort1, t_sort2;
    t_start = clock();


    int arr_len = 9;

    // Malloc array
    int *arr = (int*) malloc (sizeof(*arr) * arr_len);
    // random int to array
    rand_arr (arr,arr_len,100);

    //for (int i = 0; i < arr_len; ++i)
    //*(arr + i) = arr_len - i - 1;
    //*(arr +i) = i;
    //print default array
    print_arr (arr,arr_len);

    //time sort start
    t_sort1 = clock();

    //array_sort
    //bubble_sort(arr,arr_len);
    //insert_sort(arr, arr_len);
    //select_sort(arr, arr_len);
    //merge_sort (arr,arr_len);
    //quick_sort(arr,0,arr_len-1);
    //time sort stop
    t_sort2 = clock();

    //print sort array
    print_arr (arr,arr_len);

    // free array
    free (arr);
    // time check
    t_stop = clock();
    printf("Sort_time is %lf\n", (double)(t_sort2 - t_sort1)/CLOCKS_PER_SEC);
    printf("All_time is %lf\n", (double)(t_stop - t_start)/CLOCKS_PER_SEC);

    resheto_eratosfena();

    return 0;
}