#include "SDBAPP.h"

void SDB_APP(){
    uint8 choice;
    while(1){
        printf("To add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check is database is full, enter 7\n");
        printf("To exit enter 0 \n");

        scanf("%u", &choice);
        SDB_action(choice);
    }
}

void SDB_action(uint8 choice){
    return;
}
