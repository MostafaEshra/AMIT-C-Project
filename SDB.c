#include "SDB.h"

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

uint8 SDB_GetUsedSize(){
    student* temp = pHead;
    uint8 counter = 0;
    while(temp != NULL){
        counter++;
        temp = temp->pNext;
    }
    return counter;
}

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

bool SDB_AddEntry(){
    student* newNode = Create_Node();
    if(newNode) {
        uint32 id = 0;
        uint32 year = 0;
        uint32 course_id = 0;
        uint32 course_grade = 0;

        printf("Enter Student ID: ");
        scanf("%u", &id);
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

void SDB_DeleteEntry(uint32 id){
    student* temp = pHead;

    while(temp != NULL && temp->Student_ID != id){
        temp = temp->pNext;
    }
    if(temp == NULL){
        printf("ID %u does not exist !!!", id);
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
    free(temp);
}

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

void SDB_Getlist(uint8 * count,uint32 * list){
    *count = SDB_GetUsedSize();
    student* temp = pHead;
    int i = 0;
    while(temp != NULL && i < *count){
        list[i] = temp->Student_ID;
        temp = temp->pNext;
        i++;
    }

    printf("Student IDs:\n");
    for (int i = 0; i < *count; i++) {
        printf("%u\n", list[i]);
    }
}

bool SDB_IsIdExist(uint32 id){
    student* temp = pHead;

    while(temp != NULL && temp->Student_ID != id){
        temp = temp->pNext;
    }
    if(temp == NULL){
        printf("ID %u does not exist !!!\n", id);
        return 0;
    }
    return 1;
}
