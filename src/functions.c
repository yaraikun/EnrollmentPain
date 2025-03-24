#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers.h"

void initData(databaseType *db)
{
    db->student_count = 0;
    db->faculty_count = 0;
    db->course_count = 0;
    db->prereq_count = 0;
    db->room_count = 0;
}

void loadData(databaseType *db)
{
    // make sure file exists
    // if file exists, then put the data in the struct(s)
    // if not then we start blank

    FILE *fp;

    String10 temp;

    fp = fopen(STUDENT_FILE, "r");
    if (fp != NULL) {
        while ( fscanf(fp, "%s", temp) != EOF ) {

        }
    }
}

void saveData(databaseType *db)
{
}

/*
    Purpose: determine if the search key is in the array or not using a linear
    Returns: either the (a) index of the array where the key was found or
    @param : db is a pointer to the main database containing the information to
             be stored in the text files
    @param : exit_flag is a flag to determine when to quit the program
    Pre-condition: the parameters contain valid values
*/
void mainMenu(databaseType *db, int *exit_flag)
{
    int choice;

    printf("\nMain Menu\n");
    printf("1] Student\n");
    printf("2] Faculty\n");
    printf("3] Academic Assistant\n");
    printf("4] Exit\n");
    printf("Answer: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            studentMenu(&db);
            break;
        case 2:
            facultyMenu(&db);
            break;
        case 3:
            assistantMenu(&db);
            break;
        case 4:
            *exit_flag = 1;
            break;
        default:
            fprintf(stderr, "ERROR: Choice %d is invalid.", choice);
            break;
    }
}

int searchStudent(databaseType *db, String10 key)
{
    int i, found;

    found = 0;
    i = 0;

    while (!found && i < db->student_count)
        if (strcmp(key, db->students[i++].id) == 0)
            found = 1;
    

    return found ? --i : -1;
}

void studentAccountMenu(studentType student, int *exit_flag)
{
    int choice;

    print("Choose your transaction: ");
    print("1] Enroll Courses");
    print("2] Print EAF");
    print("3] Exit to Return to Main Menu");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            studentEnroll();
            break;
        case 2:
            studentEAF();
            break;
        case 3:
            *exit_flag = 1;
            break;
        default:
            fprintf(stderr, "ERROR: Choice %d is invalid.", choice);
            break;
    }
}

void studentMainMenu(databaseType *db)
{
    int idx;
    int exit_flag;
    String10 student_id;

    exit_flag = 0;

    printf("Student Menu\n");
    printf("Enter Student ID: ");
    scanf("%s", student_id);

    idx = searchStudent(db, student_id);

    if (idx != -1)
        while(!exit_flag)
            studentAccountMenu(db->students[idx], &exit_flag);
    else
        fprintf(stderr, "ERROR: Student %s not found.", student_id);
}

void facultyMenu(databaseType *db)
{
}

void assistantMenu(databaseType *db)
{
}