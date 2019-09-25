//
// Created by alex on 20.09.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"


void resheto_eratosfena(){

    int num = 100;

    for (int n = 2; n  < num; ++n) {
        int k = n - 1;
        while ( k >= 2 && (n % k)) --k;
        if (k < 2) printf("%d ", n);
    }

}

    void stucture (){

        char c;
        typedef struct data {
            int index;
            char name [20];
            char surname [20];
            int age;
        }data;
        typedef struct dt{
            int cur_idx;
            data data;
        }dt;

        dt *bs = malloc(10* sizeof(struct dt));
        bs->cur_idx=0;

        do{
            printf("Input Name: ");
            scanf("%s",(bs+bs->cur_idx)->data.name);
            printf("Input SurName: ");
            scanf("%s",(bs+bs->cur_idx)->data.surname);
            printf("Age: ");
            scanf("%d",&(bs+bs->cur_idx)->data.age);
            bs->data.index = bs->cur_idx;

            ++bs->cur_idx;
            printf("Continue ? ");
            scanf(" %c", &c);
        }while (c == 'y');

        int key =0;
        printf("Input index for print (current max-%d):",bs->cur_idx -1);
        scanf("%d",&key);
        printf("Name: %s\n",(bs+key)->data.name);
        printf("Surname: %s\n",(bs+key)->data.surname);
        printf("Age: %d", (bs+key)->data.age);

        free(bs);

    }

    void my_puts(char* string){

        int i = 0;
        while( string[i] != '\0'){

            putchar(string[i]);
            ++i;
        }
        putchar('\n');
    }


//DIR *dir = (opendir("/home/alex"));
//struct dirent *ent;

//    while ((ent = readdir(dir)) != NULL) {
//      if ((int) (ent->d_name[0]) != 46)
//       my_puts(ent->d_name);
//     printf( "type=%c, name: %s\n",ent->d_type,ent->d_name);
//  }


/*  char* text = "Hello World\n";
  FILE * file_w = fopen("/home/alex/test.txt", "w");
  if (NULL == file_w) {
      printf("can't open file_w ");
      exit(EXIT_FAILURE);
  }
  else {
      fputs(text, file_w);
      fclose(file_w);
  }

  char str [1000];
  FILE * file_w = fopen("/home/alex/test2.txt","w+");
  FILE * file_r = fopen("/home/alex/test.txt", "r");
  if (NULL==file_w) exit(EXIT_FAILURE);
  if (NULL==file_r) exit(EXIT_FAILURE);

  while (fgets(str,1000,file_r))
      fprintf(file_w,str,"%s");

  //fclose(file_r);
  //fclose(file_w);

  fseek(file_w,0,SEEK_SET);
  while (fgets(str,1000,file_w))
      fputs(str,stdout);
*/
