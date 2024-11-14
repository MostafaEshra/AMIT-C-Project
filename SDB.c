#include "SDB.h"

/**
 * @brief Checks if the student database is full.
 *
 * This function traverses the linked list of students and counts the number of
 * nodes. If the count reaches the maximum capacity (10 in this case), it returns `true`
 * to indicate that the database is full; otherwise, it returns `false`.
 *
 * @return `true` if the database has reached its maximum capacity of 10 students,
 *         `false` otherwise.
 */
bool SDB_IsFull() {
    student* temp = pHead;
    uint8 counter = 0;
    while(temp != NULL){
        counter++;
        temp = temp->pNext;
    }
    if(counter == 10) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Retrieves the current number of students in the database.
 *
 * This function traverses the linked list of students, counting each node to determine
 * the number of students currently stored in the database. It returns this count.
 *
 * @return The number of students (nodes) currently in the list.
 */
uint8 SDB_GetUsedSize(){
    student* temp = pHead;
    uint8 counter = 0;
    while(temp != NULL){
        counter++;
        temp = temp->pNext;
    }
    return counter;
}

/**
 * @brief Creates and initializes a new student node.
 *
 * This function allocates memory for a new `student` node using `malloc`. If the memory allocation
 * is successful, it returns a pointer to the new node. If allocation fails, it prints an error message
 * and returns `NULL`.
 *
 * @return Pointer to a newly allocated `student` node if successful; `NULL` if memory allocation fails.
 *
 * @note The caller is responsible for checking the return value and for freeing
 *       the allocated memory when it is no longer needed.
 */
static student* Create_Node(){
    student* newNode = (student*)malloc(sizeof(student));
    if(!newNode) {
        printf("Memory allocation failed\n");
        return 0;
    }
    else {
        return newNode;
    }
}

/**
 * @brief Adds a new student entry to the list.
 * @details Allocates memory for a new student node and prompts the user to input student data, including ID, year, and three course IDs with corresponding grades. Adds the node to the end of the doubly linked list.
 * @return true if the entry is successfully added, false if memory allocation fails.
 */
bool SDB_AddEntry(){
    student* newNode = Create_Node();
    if(newNode) {
        uint32 id = 0;
        uint32 year = 0;
        uint32 course_id = 0;
        uint32 course_grade = 0;

        printf("Enter Student ID: ");
        scanf("%u", &id);
        while(SDB_IsIdExist(id)){
            printf("ID is already taken\n");
            printf("Enter Student ID: ");
            scanf("%u", &id);
        }
        newNode ->Student_ID = id;

        printf("Enter Student Year: ");
        scanf("%u", &year);
        newNode ->Student_year = year;

        for(int i = 0; i < 3; i++) {
            printf("Enter Course %d ID: ", i+1);
            scanf("%u",&course_id);
            printf("Enter Course %d Grade: ", i+1);
            scanf("%u",&course_grade);
            switch(i) {
                case 0:
                    newNode->Course1_ID = course_id;
                    newNode->Course1_grade = course_grade;
                    break;
                case 1:
                    newNode->Course2_ID = course_id;
                    newNode->Course2_grade = course_grade;
                    break;
                case 2:
                    newNode->Course3_ID = course_id;
                    newNode->Course3_grade = course_grade;
                    break;
            }
        }
        //case list is empty
        if(pHead == NULL) {
            pHead = pTail = newNode;
            newNode->pNext = NULL;
            newNode->pPrev = NULL;
        }
        else {
            pTail->pNext = newNode;
            newNode->pPrev = pTail;
            pTail = newNode;
            newNode->pNext = NULL;
        }
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Deletes a student entry by ID.
 * @param id The ID of the student to be deleted.
 * @details Searches for the student by ID in the list. If found, removes the node from the list and frees memory; otherwise, prints an error message.
 * @note Assumes the list has a minimum of three students.
 */
void SDB_DeleteEntry(uint32 id){
    student* temp = pHead;

    while(temp != NULL && temp->Student_ID != id){
        temp = temp->pNext;
    }
    if(temp == NULL){
        printf("\nID %u does not exist !!!\n", id);
        return;
    }
    else {
        if(temp == pHead) {
            pHead->pNext->pPrev = NULL;
            pHead = pHead->pNext;
        }
        else if(temp == pTail) {
            pTail->pPrev->pNext = NULL;
            pTail = pTail->pPrev;
        }
        else {
            temp->pPrev->pNext = temp->pNext;
            temp->pNext->pPrev = temp->pPrev;
        }
    }
    printf("\nDeleted ID %u\n", id);
    free(temp);
}

/**
 * @brief Reads and displays information for a student by ID.
 * @param id The ID of the student to be read.
 * @return true if the student ID exists and information is displayed, false if the ID is not found.
 * @details Searches for the student by ID. If found, displays the student's ID, year, and course information; otherwise, prints an error message.
 */
bool SDB_ReadEntry(uint32 id){
    student* temp = pHead;

    while(temp != NULL && temp->Student_ID != id){
        temp = temp->pNext;
    }
    if(temp == NULL){
        printf("ID %u does not exist !!!\n", id);
        return 0;
    }
    printf("Student ID = %u\n",temp->Student_ID);
    printf("Student Year = %u\n",temp->Student_year);
    printf("Course 1 ID = %u\n",temp->Course1_ID);
    printf("Course 1 Grade = %u\n",temp->Course1_grade);
    printf("Course 2 ID = %u\n",temp->Course2_ID);
    printf("Course 2 Grade = %u\n",temp->Course2_grade);
    printf("Course 3 ID = %u\n",temp->Course3_ID);
    printf("Course 3 Grade = %u\n",temp->Course3_grade);
    return 1;
}

/**
 * @brief Retrieves a list of all student IDs and the count of students.
 * @param[out] count Pointer to a variable to store the number of students in the list.
 * @param[out] list Pointer to an array to store the student IDs.
 * @details Sets *count to the number of students in the list and fills the list array with student IDs. Also prints each ID for verification.
 * @note Assumes the list array has enough space for all student IDs.
 */
void SDB_Getlist(uint8 * count,uint32 * list){
    *count = SDB_GetUsedSize();
    student* temp = pHead;
    int i = 0;
    while(temp != NULL && i < *count){
        list[i] = temp->Student_ID;
        temp = temp->pNext;
        i++;
    }

    printf("\nStudent IDs:\n");
    for (int i = 0; i < *count; i++) {
        printf("%u\n", list[i]);
    }
}

/**
 * @brief Checks if a student ID exists in the list.
 * @param id The ID to check for existence in the list.
 * @return true if the student ID exists, false if not.
 * @details Searches for the student by ID in the list. If found, returns true; otherwise, prints a message and returns false.
 */
bool SDB_IsIdExist(uint32 id){
    student* temp = pHead;

    while(temp != NULL && temp->Student_ID != id){
        temp = temp->pNext;
    }
    if(temp == NULL){
//        printf("ID %u does not exist !!!\n", id);
        return 0;
    }
    return 1;
}
