#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// simple software for Student Information Management System
//  perform following task :
//  1. Store the first name of the student
//  2. Store the last name of the student
//  3. Store the unique roll no. for every student
//  4. Store the CGPA of every student
//  5. Store the courses registered by the student

// variable to keep track of the number of the students
int stu_num = 0;

// structure to store the student
typedef struct student_info
{
    char fname[30];
    char lname[30];
    int roll;
    float cgpa;
    int cid[10];
} sinfo;

sinfo stud[100];

// function to add the students
void add_student()
{
    printf("Add the student detail\n");
    printf("-------------------------------\n");
    printf("Enter the first name of the student \n");
    scanf("%s", stud[stu_num].fname);
    printf("Enter the last name of the student \n");
    scanf("%s", stud[stu_num].lname);
    printf("Enter the ROLL number \n");
    scanf("%d", &stud[stu_num].roll);
    printf("Enter the CGPA you obtained \n");
    scanf("%.3f", &stud[stu_num].cgpa);
    printf("Enter the course ID of the each course \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &stud[stu_num].cid[i]);
    }
    stu_num = stu_num + 1;
}

// Function to find the student by the roll no
void find_roll()
{
    int r_find;
    printf("Enter Roll number of the student \n");
    scanf("%d", &r_find);
    for (int i = 0; i < stu_num; i++)
    {
        if (r_find == stud[i].roll)
        {
            printf("Detail of the student are : \n");
            printf("First name is %s\n", stud[i].fname);
            printf("Last name is %s\n", stud[i].lname);
            printf("The CGPA is %.3f\n", stud[i].cgpa);
            printf("The courses ID are ");
            for (int j = 0; j < 5; j++)
            {
                printf("%d\n", stud[i].cid[j]);
            }
        }

        break;
    }
}

// Function to find the student by the first name
void find_fname()
{

    char fname_find[30];
    printf("Enter the first name of the student \n");
    scanf("%s", fname_find);
    int c = 0;
    for (int i = 0; i < stu_num; i++)
    {
        if (!strcmp(stud[i].fname, fname_find))
        {
            printf("Detail of the student are \n");
            printf("First name is %s\n", stud[i].fname);
            printf("Last name is %s\n", stud[i].lname);
            printf("Roll no. is  %d\n", stud[i].roll);
            printf("The CGPA is %.3f\n", stud[i].cgpa);
            printf("The course ID are ");
            for (int j = 0; j < 5; j++)
            {
                printf("%d\n", stud[i].cid[j]);
            }
            c = 1;
        }
        else
            printf("The First name not found\n");
    }
}

// function to find the student enrolled in a particular course
void find_cid()
{
    int id;
    printf("Enter the course ID \n");
    scanf("%d", &id);
    int c = 0;
    for (int i = 0; i < stu_num; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (id == stud[i].cid[j])
            {
                printf("The student details are \n");
                printf("The First name is %s\n", stud[i].fname);
                printf("The Last name is %s\n", stud[i].lname);
                printf("The Roll no is %d\n", stud[i].roll);
                printf("The CGPA is %.3f\n", stud[i].cgpa);
                c = 1;
                break;
            }
            else
                printf("The course id is not found \n");
                
        }
    }
}

// Function to print the total number of the students
void total_stud()
{
    printf("The total number of the students are %d\n", stu_num);
    printf("You can have a max of 100 students \n");
    printf("You have space for %d more students\n", 100 - stu_num);
}

// Function to delete a student by the roll number
void del_stud()
{
    int stud_del;
    printf("Enter the Roll which you want to delete \n");
    scanf("%d", &stud_del);
    for (int i = 0; i < stu_num; i++)
    {
        if (stud_del == stud[i].roll)
        {
            for (int j = 0; j < 49; j++)
                stud[j] = stud[j + 1];

            stu_num--;
        }
    }

    printf("The Roll number is removed successfully\n");
}

// Function to update a student data
void update_stud()
{
    long int stud_roll;
    printf("Enter the Roll no to update the data of the student \n");
    scanf("%d", &stud_roll);
    for (int i = 0; i < stu_num; i++)
    {
        if (stud[i].roll == stud_roll)
        {
            printf(" 1. First Name \n");
            printf(" 2. Second name \n");
            printf(" 3. Roll no. \n");
            printf(" 4. CGPA \n");
            printf(" 5. Courses \n");
            int n;
            printf("Enter the number from above to update : \n");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter the New First name\n");
                scanf("%s", stud[i].fname);
                break;
            case 2:
                printf("Enter the New last name\n");
                scanf("%s", stud[i].lname);
                break;
            case 3:
                printf("Enter New Roll No \n");
                scanf("%d", stud[i].roll);
                break;
            case 4:
                printf("Enter New CGPA \n");
                scanf("%d", stud[i].cgpa);
                break;
            case 5:
                printf("Enter the New couses");
                scanf("%d%d%d%d%d", &stud[i].cid[0], &stud[i].cid[1], &stud[i].cid[2], &stud[i].cid[3], &stud[i].cid[4]);
                break;
            }
            printf("UPDATED SUCCESSFULLY \n");
        }
    }
}

void main()
{
    int choice;
    while (stu_num = 1)
    {
        printf("Task you want to perform \n");
        printf(" 1. Add the student details \n");
        printf(" 2. Find the student details by the Roll no \n");
        printf(" 3. Find the student details by the First name \n");
        printf(" 4. Find the student details by the course id \n");
        printf(" 5. Find the total number of students \n");
        printf(" 6. Delete the student details by Roll no \n");
        printf(" 7. Update the student details by Roll no. \n");
        printf(" 8. To exit \n");

        printf("Enter your choice to find the task \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            find_roll();
            break;
        case 3:
            find_fname();
            break;
        case 4:
            find_cid();
            break;
        case 5:
            total_stud();
            break;
        case 6:
            del_stud();
            break;
        case 7:
            update_stud();
            break;
        case 8:
            exit(0);
            break;        

        }
    }
}