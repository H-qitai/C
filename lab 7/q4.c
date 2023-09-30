#include<stdio.h>

int main(){

    int L_con;
    printf("Large capacity: \n");
    scanf("%d", &L_con);

    int S_con;
    printf("Small capacity: \n");
    scanf("%d", &S_con);

    int items;
    printf("Number of items: \n");
    scanf("%d", &items);

    int L_con_used;
    int S_con_used;
    int scrap_left;
    int items_left;

    L_con_used = items / L_con;
    items_left = items % L_con;
    S_con_used = items_left / S_con;
    items_left = items_left % S_con;
    scrap_left = items_left;

    printf("Allocated:\n");
    printf(" - Large: %d\n", L_con_used);
    printf(" - Small: %d\n", S_con_used);
    printf(" - Scrap: %d\n", scrap_left);


    return 0;
}