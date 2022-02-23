#include "fun.h"

//Align the message
int printMessageCenter(const char* message)
{
    int length =0;
    int position = 0;
    //calculate how many space need to print
    length = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(position =0 ; position< length ; position++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}

//Head message
int headMessage(const char *message)
{
    system("cls");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
//Validate name
int isNameValid(const char *name)
{
    int validName = 1;
    int length = 0;
    int index = 0;
    length= strlen(name);
    for(index =0; index <length ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}

int addEmployeeInDataBase()
{
    s_EmployeeInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW Employees");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tEmployee ID  = ");
    fflush(stdin);
    scanf("%u",&addEmployeeInfoInDataBase.employee_id);
    do
    {
        printf("\n\t\t\tFather Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.fatherName,MAX_FATHER_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.fatherName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.employeeName,MAX_EMPLOYEE_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.employeeName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Address  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.employeeAddr,MAX_FATHER_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.employeeAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }while(!status);
    fwrite(&addEmployeeInfoInDataBase,sizeof(addEmployeeInfoInDataBase), 1, fp);
    fclose(fp);
}
// search
int searchEmployee()
{
    int found = 0;
    int employeeId =0;
    s_EmployeeInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH EMPLOYEES");
    //put the control on student detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Employee ID NO to search:");
    fflush(stdin);
    scanf("%u",&employeeId);
    while (fread (&addInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        if(addEmployeeInfoInDataBase.employee_id == employeeId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tEmployee id = %d\n",addEmployeeInfoInDataBase.employee_id);
        printf("\n\t\t\tEmployee name = %s",addEmployeeInfoInDataBase.employeetName);
        printf("\t\t\tFather Name = %s",addEmployeeInfoInDataBase.fatherName);
        printf("\n\t\t\tEmployee Address = %s",addEmployeeInfoInDataBase.employeeAddr);
        printf("\t\t\tEmployee Admission Date(day/month/year) =  (%d/%d/%d)",addEmployeeInfoInDataBase.employeeJoiningDate.dd,
               addEmployeeInfoInDataBase.employeeJoiningDate.mm, addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// view employees function
int viewStudent()
{
    int found = 0;
    s_EmployeeInfo addEmployeetInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countEmployee = 1;
    headMessage("VIEW Employee DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addEmployeeInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tEmployee Count = %d\n\n",countEmployee);
        printf("\t\t\tEmployee id = %u\n",addEmployeeInfoInDataBase.employee_id);
        printf("\t\t\tEmployee Name = %s",addEmployeeInfoInDataBase.employeeName);
        printf("\t\t\tFather Name = %s",addEmployeeInfoInDataBase.fatherName);
        printf("\t\t\tEmployeeAddress = %s",addEmployeeInfoInDataBase.employeeAddr);
        printf("\t\t\tEmployee Admission Date(day/month/year) =  (%d/%d/%d)\n\n",addEmployeeInfoInDataBase.employeeJoiningDate.dd,
               addEmployeeInfoInDataBase.employeeJoiningDate.mm, addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
        found = 1;
        ++countEmployee;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// Delete employee entry
int deleteEmployee()
{
    int found = 0;
    int employeeDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_EmployeeInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *temp = NULL;
    headMessage("Delete Employee Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    temp = fopen("tmp.bin","wb");
    if(temp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, temp);
    printf("\n\t\t\tEnter EmployeeID NO. for delete:");
    scanf("%d",&employeeDelete);
    while (fread (&addEmployeeInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        if(addEmployeeInfoInDataBase.employee_id != employeeDelete)
        {
            fwrite(&addEmployeeInfoInDataBase,sizeof(addEmployeeInfoInDataBase), 1, temp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
//function to update credential
int updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\ttLogin Again:");
    fflush(stdin);
    getchar();
    exit(1);
}
//Display menu
int menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Employee");
        printf("\n\t\t\t2.Search Employee");
        printf("\n\t\t\t3.View Employee");
        printf("\n\t\t\t4.Delete Employee");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addEmployeeInDataBase();
            printf("\nadded successfully");
            break;
        case 2:
            searchEmployee();
            printf("\nsearched successfully");
            break;
        case 3:
            viewEmployee();
            break;
        case 4:
            deleteEmployee();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you !!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }while(choice!=0);                                        //Loop Ended
}
//login password
int login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int l=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((strcmp(userName,fileHeaderInfo.username)) && (strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed ,Enter Again Username & Password\n\n");
            l++;
        }
    }
    while(l<=3);
    if(l>3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getchar();

    }
}
//Check file exist or not
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
int init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="EmployeeRecord\n";
    const char defaultPassword[] ="EmployeeRecord\n";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");

        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
