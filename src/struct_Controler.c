#include "struct_Controler.h"

Controler *create_Controler(StrTab* strTab_controler) {
    struct Controler *controler = (struct Controler *) malloc(sizeof(struct Controler));
    controler->size = 0;
    controler->capacity = 1;

    strTab_controler = (StrTab*) malloc(sizeof(StrTab) * controler->capacity);

    controler->strTab_controler = strTab_controler;
    return controler;
}

//void printControler(Controler controler){
//    printf("\n");
//    for (int i = 0; i < controler.size; i++) {
//        for(int j = 0; j < controler.strTab_controler->size)
//        {
//            printf("i = %d - j = %d --",i,j);
//            printStrTab(controler.strTab_controler[i][j]);
//        }
//    }
//    printf("\nfin printf Controler\n");
//}