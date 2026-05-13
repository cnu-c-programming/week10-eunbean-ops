#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    char name[50];
    int score;
    struct Student* next;
} Student;

void addNode(Student** head, char* name, int score) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteNode(Student** head, char* name) {
    Student* temp = *head;
    Student* prev = NULL;

  
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

 
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }


    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}


void printList(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("%s %d\n", temp->name, temp->score);
        temp = temp->next;
    }
}


void freeList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Student* head = NULL;
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            addNode(&head, name, score);
        } 
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteNode(&head, name);
        } 
        else if (strcmp(command, "print") == 0) {
            printList(head);
        } 
        else if (strcmp(command, "quit") == 0) {
            freeList(head);
            break;
        }
    }

    return 0;
}
