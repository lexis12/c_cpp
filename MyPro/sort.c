//
// Created by link on 16.09.2019.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int count =0;

void swap (int *a, int *b){
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
   }

    void print_arr (int *arr, int arr_len) {
        for (int i = 0; i < arr_len; ++i)
            printf("%d ", *(arr + i));

        printf("\n");
    }

    void rand_arr (int *arr, int arr_len, int arr_depth){
        srand((unsigned) time(NULL));
        for (int i = 0; i < arr_len; ++i)
            *(arr + i) = rand() % arr_depth;
    }

    void bubble_sort (int *arr, int arr_len){
        int tmp;
        int chk;
        for (int i = 0; i < arr_len; ++i) {
            chk = 0;
            for (int j = 0; j < arr_len - i - 1; ++j) {
                if (*(arr + j) > *(arr + j + 1) ) {
                    chk++;
                    swap ((arr + j) ,(arr + j + 1));
                }
            }
        if (!chk) break;
        }
    }

    void insert_sort (int *arr, int arr_len){

        for (int i = 1; i < arr_len ; ++i) {
            int j = i;
            while ((j >= 0) && (*(arr + j) < *(arr + j - 1))){
                swap( (arr + j),(arr + j - 1));
                --j;
            }
        }
    }

    void select_sort (int *arr, int arr_len) {
        int min = 0;
        for (int i = 0; i < arr_len -1; ++i){
            min = i;
            for (int j = i + 1; j < arr_len; ++j){
                if (*(arr+min) > *(arr+j)) {
                   min = j;
                }
            }
            swap(arr+min, arr+i);
        }

    }

    void merge_sort (int *arr,int arr_len) {

    if (arr_len > 1) {

            int l_size = arr_len / 2;
            int r_size = arr_len - l_size;

            merge_sort(arr, l_size);
            merge_sort(arr + l_size, r_size);

            int aix = 0;
            int lix = 0;
            int rix = l_size;
            int *tmp_arr = malloc(arr_len * sizeof(*tmp_arr));

            while (lix < l_size && rix < arr_len) {
                if (*(arr + rix) > *(arr + lix))
                    *(tmp_arr + aix++) = *(arr + lix++);
                else
                    *(tmp_arr + aix++) = *(arr + rix++);
            }

            while (lix < l_size)
                *(tmp_arr + aix++) = *(arr + lix++);
            while (rix < arr_len)
                *(tmp_arr + aix++) = *(arr + rix++);

            for (int i = 0; i < arr_len; ++i)
                *(arr + i) = *(tmp_arr + i);

            //print_arr(tmp_arr, arr_len);

            free(tmp_arr);

        }

    }

    void quick_sort (int *arr, int first ,int last){

        if (first < last ) {

            int left = 0;
            int right = last;
            int mid = (left + right) / 2;
            int mm = *(arr+mid);

            do {
                while (*(arr + left) < mm)
                    ++left;
                while (*(arr + right) > mm)
                    --right;
                if (left < right) {
                    swap(arr + left, arr + right);
                    ++left;
                    ++right;
                }
                print_arr(arr, last+1);
            } while (left <= right);

            printf ("new loop\n");
            quick_sort(arr, first, right);
            quick_sort(arr, left, last);
        }
    }


    void qs (int *arr, int first, int last){


        if (first < last){
            int tpm_arr [last+1];
            int left = 0;
            int right = last;
            int mid = (right -left) / 2;

            do {

               while (arr[left] < arr[mid])
                   ++left;
               while  (arr[right] > arr[mid])
                   --right;
               if (left < right){
                    swap(arr[left], arr[right]);
               }

            }while (left < right);
         }

    }

