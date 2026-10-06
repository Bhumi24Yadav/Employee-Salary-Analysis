#include <stdio.h>
#include <string.h>

#define MAX 100

void display(int id[], char name[][50], char dept[][30],
             float salary[], int n)
{
    int i;

    printf("\n%-8s %-15s %-15s %-10s\n",
           "ID", "Name", "Department", "Salary");

    printf("--------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-15s %-15s %.2f\n",
               id[i], name[i], dept[i], salary[i]);
    }
}

void copyArray(int id1[], char name1[][50], char dept1[][30],
               float salary1[],
               int id2[], char name2[][50], char dept2[][30],
               float salary2[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        id2[i] = id1[i];
        strcpy(name2[i], name1[i]);
        strcpy(dept2[i], dept1[i]);
        salary2[i] = salary1[i];
    }
}

void selectionSort(int id[], char name[][50], char dept[][30],
                   float salary[], int n, int order,
                   long *comparisons, long *movements)
{
    int i, j, pos;
    int tempID;
    float tempSalary;
    char tempName[50];
    char tempDept[30];

    *comparisons = 0;
    *movements = 0;

    for (i = 0; i < n - 1; i++)
    {
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            (*comparisons)++;

            if ((order == 1 && salary[j] < salary[pos]) ||
                (order == 2 && salary[j] > salary[pos]))
            {
                pos = j;
            }
        }

        if (pos != i)
        {
            tempID = id[i];
            id[i] = id[pos];
            id[pos] = tempID;

            strcpy(tempName, name[i]);
            strcpy(name[i], name[pos]);
            strcpy(name[pos], tempName);

            strcpy(tempDept, dept[i]);
            strcpy(dept[i], dept[pos]);
            strcpy(dept[pos], tempDept);

            tempSalary = salary[i];
            salary[i] = salary[pos];
            salary[pos] = tempSalary;

            (*movements) += 4;
        }
    }
}

void insertionSort(int id[], char name[][50], char dept[][30],
                   float salary[], int n, int order,
                   long *comparisons, long *movements)
{
    int i, j;
    int keyID;
    float keySalary;
    char keyName[50];
    char keyDept[30];

    *comparisons = 0;
    *movements = 0;

    for (i = 1; i < n; i++)
    {
        keyID = id[i];
        strcpy(keyName, name[i]);
        strcpy(keyDept, dept[i]);
        keySalary = salary[i];

        (*movements)++;

        j = i - 1;

        while (j >= 0)
        {
            (*comparisons)++;

            if ((order == 1 && salary[j] > keySalary) ||
                (order == 2 && salary[j] < keySalary))
            {
                id[j + 1] = id[j];
                strcpy(name[j + 1], name[j]);
                strcpy(dept[j + 1], dept[j]);
                salary[j + 1] = salary[j];

                (*movements)++;
                j--;
            }
            else
            {
                break;
            }
        }

        id[j + 1] = keyID;
        strcpy(name[j + 1], keyName);
        strcpy(dept[j + 1], keyDept);
        salary[j + 1] = keySalary;

        (*movements)++;
    }
}

void addEmployee(int id[], char name[][50], char dept[][30],
                 float salary[], int *n)
{
    if (*n >= MAX)
    {
        printf("\nMaximum number of employees reached.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &id[*n]);

    printf("Enter Name: ");
    scanf("%s", name[*n]);

    printf("Enter Department: ");
    scanf("%s", dept[*n]);

    printf("Enter Salary: ");
    scanf("%f", &salary[*n]);

    (*n)++;

    printf("\nEmployee added successfully.\n");
}

void searchEmployee(int id[], char name[][50], char dept[][30],
                    float salary[], int n, int searchID)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (id[i] == searchID)
        {
            printf("\nEmployee Found!\n");
            printf("ID         : %d\n", id[i]);
            printf("Name       : %s\n", name[i]);
            printf("Department : %s\n", dept[i]);
            printf("Salary     : %.2f\n", salary[i]);
            return;
        }
    }

    printf("\nEmployee with ID %d not found.\n", searchID);
}

void highestLowest(int id[], char name[][50], char dept[][30],
                   float salary[], int n)
{
    int i;
    int highest = 0;
    int lowest = 0;

    for (i = 1; i < n; i++)
    {
        if (salary[i] > salary[highest])
            highest = i;

        if (salary[i] < salary[lowest])
            lowest = i;
    }

    printf("\nHighest Salary Employee\n");
    printf("-----------------------\n");
    printf("ID         : %d\n", id[highest]);
    printf("Name       : %s\n", name[highest]);
    printf("Department : %s\n", dept[highest]);
    printf("Salary     : %.2f\n", salary[highest]);

    printf("\nLowest Salary Employee\n");
    printf("----------------------\n");
    printf("ID         : %d\n", id[lowest]);
    printf("Name       : %s\n", name[lowest]);
    printf("Department : %s\n", dept[lowest]);
    printf("Salary     : %.2f\n", salary[lowest]);
}

void departmentDisplay(int id[], char name[][50],
                       char dept[][30], float salary[],
                       int n)
{
    char searchDept[30];
    int i;
    int found = 0;

    printf("\nEnter Department: ");
    scanf("%s", searchDept);

    printf("\nEmployees in %s department:\n", searchDept);
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (strcmp(dept[i], searchDept) == 0)
        {
            printf("ID: %d | Name: %s | Salary: %.2f\n",
                   id[i], name[i], salary[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No employees found in this department.\n");
}

void compareSorts(int id[], char name[][50], char dept[][30],
                  float salary[], int n, int order)
{
    int selID[MAX], insID[MAX];
    char selName[MAX][50], insName[MAX][50];
    char selDept[MAX][30], insDept[MAX][30];
    float selSalary[MAX], insSalary[MAX];

    long selComp, selMove;
    long insComp, insMove;

    copyArray(id, name, dept, salary,
              selID, selName, selDept, selSalary, n);

    copyArray(id, name, dept, salary,
              insID, insName, insDept, insSalary, n);

    selectionSort(selID, selName, selDept, selSalary,
                  n, order, &selComp, &selMove);

    insertionSort(insID, insName, insDept, insSalary,
                  n, order, &insComp, &insMove);

    printf("\n========== SORTING COMPARISON ==========\n");

    printf("\nSelection Sort");
    printf("\nComparisons : %ld", selComp);
    printf("\nMovements   : %ld\n", selMove);

    printf("\nInsertion Sort");
    printf("\nComparisons : %ld", insComp);
    printf("\nMovements   : %ld\n", insMove);
}

void createTestData(int id[], char name[][50],
                    char dept[][30], float salary[],
                    int n, int type)
{
    int i;

    for (i = 0; i < n; i++)
    {
        id[i] = i + 1;
        sprintf(name[i], "Emp%d", i + 1);
        sprintf(dept[i], "Dept%d", (i % 3) + 1);

        if (type == 1)
            salary[i] = 10000 + (i * 1000);
        else if (type == 2)
            salary[i] = 10000 + ((i * 37) % n) * 1000;
        else
            salary[i] = 10000 + ((n - i) * 1000);
    }
}

void performanceTest()
{
    int id[MAX];
    char name[MAX][50];
    char dept[MAX][30];
    float salary[MAX];

    int selID[MAX], insID[MAX];
    char selName[MAX][50], insName[MAX][50];
    char selDept[MAX][30], insDept[MAX][30];
    float selSalary[MAX], insSalary[MAX];

    int sizes[] = {5, 10, 20, 50};
    int sizeCount = 4;
    int i, n;

    long selComp, selMove;
    long insComp, insMove;

    printf("\n====================================================");
    printf("\n       BEST / AVERAGE / WORST CASE ANALYSIS");
    printf("\n====================================================");

    printf("\n\nRecord sizes tested: 5, 10, 20, 50\n");

    printf("\n\n******** BEST CASE ********");
    printf("\nInput: Salaries already sorted\n");

    printf("\n\n%-6s %-15s %-15s %-15s %-15s\n",
           "N", "Sel-Comp", "Sel-Move", "Ins-Comp", "Ins-Move");

    for (i = 0; i < sizeCount; i++)
    {
        n = sizes[i];

        createTestData(id, name, dept, salary, n, 1);

        copyArray(id, name, dept, salary,
                  selID, selName, selDept, selSalary, n);

        copyArray(id, name, dept, salary,
                  insID, insName, insDept, insSalary, n);

        selectionSort(selID, selName, selDept, selSalary,
                      n, 1, &selComp, &selMove);

        insertionSort(insID, insName, insDept, insSalary,
                      n, 1, &insComp, &insMove);

        printf("%-6d %-15ld %-15ld %-15ld %-15ld\n",
               n, selComp, selMove, insComp, insMove);
    }

    printf("\n\n******** AVERAGE CASE ********");
    printf("\nInput: Salaries in mixed order\n");

    printf("\n\n%-6s %-15s %-15s %-15s %-15s\n",
           "N", "Sel-Comp", "Sel-Move", "Ins-Comp", "Ins-Move");

    for (i = 0; i < sizeCount; i++)
    {
        n = sizes[i];

        createTestData(id, name, dept, salary, n, 2);

        copyArray(id, name, dept, salary,
                  selID, selName, selDept, selSalary, n);

        copyArray(id, name, dept, salary,
                  insID, insName, insDept, insSalary, n);

        selectionSort(selID, selName, selDept, selSalary,
                      n, 1, &selComp, &selMove);

        insertionSort(insID, insName, insDept, insSalary,
                      n, 1, &insComp, &insMove);

        printf("%-6d %-15ld %-15ld %-15ld %-15ld\n",
               n, selComp, selMove, insComp, insMove);
    }

    printf("\n\n******** WORST CASE ********");
    printf("\nInput: Salaries in reverse order\n");

    printf("\n\n%-6s %-15s %-15s %-15s %-15s\n",
           "N", "Sel-Comp", "Sel-Move", "Ins-Comp", "Ins-Move");

    for (i = 0; i < sizeCount; i++)
    {
        n = sizes[i];

        createTestData(id, name, dept, salary, n, 3);

        copyArray(id, name, dept, salary,
                  selID, selName, selDept, selSalary, n);

        copyArray(id, name, dept, salary,
                  insID, insName, insDept, insSalary, n);

        selectionSort(selID, selName, selDept, selSalary,
                      n, 1, &selComp, &selMove);

        insertionSort(insID, insName, insDept, insSalary,
                      n, 1, &insComp, &insMove);

        printf("%-6d %-15ld %-15ld %-15ld %-15ld\n",
               n, selComp, selMove, insComp, insMove);
    }

    printf("\n\n====================================================");
    printf("\n                    OBSERVATIONS");
    printf("\n====================================================");

    printf("\n1. Selection Sort performs O(n^2) comparisons");
    printf("\n   in best, average and worst cases.");

    printf("\n\n2. Insertion Sort performs O(n) comparisons");
    printf("\n   in the best case when data is already sorted.");

    printf("\n\n3. Insertion Sort performs O(n^2) operations");
    printf("\n   in average and worst cases.");

    printf("\n\n4. Increasing the number of records increases");
    printf("\n   the number of operations.");

    printf("\n\n5. Selection Sort performs fewer data movements");
    printf("\n   because it performs at most one swap per pass.");

    printf("\n\n6. Insertion Sort is efficient for sorted or");
    printf("\n   nearly sorted data.\n");
}

int main()
{
    int id[MAX];
    char name[MAX][50];
    char dept[MAX][30];
    float salary[MAX];

    int n = 0;
    int choice;
    int order;
    int searchID;

    do
    {
        printf("\n\n==============================================");
        printf("\n       EMPLOYEE SALARY ANALYSIS SYSTEM");
        printf("\n==============================================");

        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Selection Sort by Salary");
        printf("\n4. Insertion Sort by Salary");
        printf("\n5. Search Employee by ID");
        printf("\n6. Highest and Lowest Salary");
        printf("\n7. Department-wise Display");
        printf("\n8. Compare Sorting Algorithms");
        printf("\n9. Best/Average/Worst Case Analysis");
        printf("\n10. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(id, name, dept, salary, &n);
            break;

        case 2:
            if (n == 0)
                printf("\nNo employee records available.\n");
            else
                display(id, name, dept, salary, n);
            break;

        case 3:
        {
            int sortID[MAX];
            char sortName[MAX][50];
            char sortDept[MAX][30];
            float sortSalary[MAX];
            long comparisons, movements;

            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            printf("\n1. Ascending");
            printf("\n2. Descending");
            printf("\nEnter required sort order: ");
            scanf("%d", &order);

            copyArray(id, name, dept, salary,
                      sortID, sortName, sortDept, sortSalary, n);

            selectionSort(sortID, sortName, sortDept, sortSalary,
                          n, order, &comparisons, &movements);

            printf("\nSelection Sort Result:\n");
            display(sortID, sortName, sortDept, sortSalary, n);

            printf("\nComparisons : %ld", comparisons);
            printf("\nMovements   : %ld\n", movements);
            break;
        }

        case 4:
        {
            int sortID[MAX];
            char sortName[MAX][50];
            char sortDept[MAX][30];
            float sortSalary[MAX];
            long comparisons, movements;

            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            printf("\n1. Ascending");
            printf("\n2. Descending");
            printf("\nEnter required sort order: ");
            scanf("%d", &order);

            copyArray(id, name, dept, salary,
                      sortID, sortName, sortDept, sortSalary, n);

            insertionSort(sortID, sortName, sortDept, sortSalary,
                          n, order, &comparisons, &movements);

            printf("\nInsertion Sort Result:\n");
            display(sortID, sortName, sortDept, sortSalary, n);

            printf("\nComparisons : %ld", comparisons);
            printf("\nMovements   : %ld\n", movements);
            break;
        }

        case 5:
            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            printf("\nEnter Employee ID to search: ");
            scanf("%d", &searchID);

            searchEmployee(id, name, dept, salary, n, searchID);
            break;

        case 6:
            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            highestLowest(id, name, dept, salary, n);
            break;

        case 7:
            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            departmentDisplay(id, name, dept, salary, n);
            break;

        case 8:
            if (n == 0)
            {
                printf("\nNo employee records available.\n");
                break;
            }

            printf("\n1. Ascending");
            printf("\n2. Descending");
            printf("\nEnter required sort order: ");
            scanf("%d", &order);

            compareSorts(id, name, dept, salary, n, order);
            break;

        case 9:
            performanceTest();
            break;

        case 10:
            printf("\nExiting program...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 10);

    return 0;
}
