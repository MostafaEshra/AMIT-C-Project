#include "SDBAPP.h"
#include "STD.h"

/**
 * @brief SDB_APP - Entry point for the Student Database Application (SDB) interface.
 *
 * This function provides a console-based menu for interacting with the Student Database.
 * It runs an infinite loop where the user is prompted to select one of several options:
 * adding an entry, checking the database size, reading student data, listing all student IDs,
 * checking if an ID exists, deleting data, checking if the database is full, or exiting.
 *
 * @note The function validates the user's input choice, allowing only values between 0 and 7.
 *       If the input is outside this range, the user is prompted again until a valid choice is entered.
 *       The application will exit if the user selects the "exit" option (choice 0).
 *
 * @usage
 * 1. The user enters a number corresponding to the desired action.
 * 2. The function calls `SDB_action` with the user’s choice.
 *
 * @param None
 * @return None
 */
void SDB_APP(){
    uint8 choice;
    while(1){
        printf("\nTo add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check is database is full, enter 7\n");
        printf("To exit enter 0 \n");

        do {
            choice = 0;
            printf("Enter Your Choice: ");
            scanf("%u", &choice);
        }
        while(choice > 7);
        SDB_action(choice);
    }
}

/**
 * @brief SDB_action - Executes an action based on the user's menu choice.
 *
 * This function performs various operations on the Student Database based on the user's
 * input choice. It supports adding new entries, checking the database size, reading student data,
 * listing student IDs, checking if a specific ID exists, deleting student data, and verifying if
 * the database is full.
 *
 * @param choice A uint8 value representing the user's selected menu option (0-7).
 *
 * Each case within the switch statement corresponds to a specific database operation:
 * - **Case 0:** Exits the program.
 * - **Case 1:** Adds a new student entry. If the database has fewer than 3 entries, the user must add 3 students (minimum requirement).
 *              If the database is full (10 entries), a message is displayed and no entry is added.
 * - **Case 2:** Displays the number of students currently in the database.
 * - **Case 3:** Prompts the user to enter a student ID, then displays the student's data if the ID exists.
 * - **Case 4:** Retrieves and displays the list of all student IDs.
 * - **Case 5:** Checks if a specific student ID exists in the database and prints a message indicating the result.
 * - **Case 6:** Deletes a student entry based on the provided ID.
 * - **Case 7:** Checks if the database is full and displays the appropriate message.
 *
 * @note This function relies on other Student Database functions to perform its actions, such as
 *       `SDB_GetUsedSize`, `SDB_AddEntry`, `SDB_ReadEntry`, `SDB_Getlist`, `SDB_IsIdExist`,
 *       `SDB_DeleteEntry`, and `SDB_IsFull`.
 *
 * @return None
 */
void SDB_action(uint8 choice){
    switch(choice) {
        case 0:
            exit(0);
        case 1: {
            int count = SDB_GetUsedSize();
            if(count < 3){
                printf("\nList is empty you have to enter 3 students as this is the min of the list\n");
                for(int i = 0; i < 3; i++) {
                    if(SDB_AddEntry() == 0) {
                        printf("Failed to add data");
                        break;
                    }
                }
            }
            else if(count == 10) {
                printf("\nCan't add student, list is full!!!\n");
                break;
            }
            else {
                if(SDB_AddEntry() == 0) {
                        printf("\nFailed to add data\n");
                        break;
                }
            }
            break;
        }

        case 2:
            printf("\nNumber of Students = %u\n", SDB_GetUsedSize());
            break;

        case 3:
            printf("\nEnter Student ID: ");
            uint32 id;
            scanf("%u",&id);
            SDB_ReadEntry(id);
            break;

        case 4: {
            uint8 counter;
            uint32 list[10];
            SDB_Getlist(&counter,list);
            break;
        }

        case 5:
            printf("\nEnter Student ID: ");
            uint32 temp;
            scanf("%u",&temp);
            if(SDB_IsIdExist(temp)) {
                printf("\nThe ID does exist in the list\n");
            }
            else {
                printf("\nThe ID does not exist in the list\n");

            }
            break;

        case 6:
            printf("\nEnter Student ID: ");
            uint32 x;
            scanf("%u",&x);
            SDB_DeleteEntry(x);
            break;

        case 7:
            if(SDB_IsFull()) {
                printf("\nThe database is Full\n");
            }
            else {
                printf("\nThe database is not Full\n");
            }
            break;
    }
}
