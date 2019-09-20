//
// Created by alex on 20.09.2019.
//

#include <stdio.h>
#include "tasks.h"


void resheto_eratosfena(){

    int num = 100;

    for (int n = 2; n  < num; ++n) {
        int k = n - 1;
        while ( k >= 2 && (n % k)) --k;
        if (k < 2) printf("%d ", n);
    }

}