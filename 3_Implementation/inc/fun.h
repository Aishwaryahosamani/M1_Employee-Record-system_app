#ifndef __FUN_H
#define __FUN_H


//Used macro
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "employeeRecordSystem.bin"
// Macro related to the employees info
#define MAX_FATHER_NAME 50
#define MAX_EMPLOYEE_NAME 50
#define MAX_EMPLOYEE_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
//Elements of structure
typedef struct// to call in program
{
    unsigned int employee_id; // declare the integer data type
    char fatherName[MAX_FATHER_NAME];// declare the charecter data type
    char employeeName[MAX_EMPLOYEE_NAME];// declare the character data type
    char employeeAddr[MAX_EMPLOYEE_ADDRESS];// declare the character data type
    Date employeeJoiningDate;// declare the integer data type
} s_EmployeeInfo;

int printMessageCenter(const char* message);
int headMessage(const char *message);
int isNameValid(const char *name);
int IsLeapYear(int year);
int isValidDate(Date *validDate);
int addEmployeeInDataBase();
int searchEmployee();
int viewEmployee();
int deleteEmployee();
int updateCredential(void);
int menu();
int login();
int isFileExists(const char *path);
int init();

#endif
