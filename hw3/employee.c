/*
 * File: employee.c
 * ----------------
 * This program tests the functions defined for records of type
 * employeeRecordT and employeeT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Type: string
 * ------------
 * The type string is identical to the type char *, which is
 * traditionally used in C programs.  The main point of defining a
 * new type is to improve program readability.   At the abstraction
 * levels at which the type string is used, it is usually not
 * important to take the string apart into its component characters.
 * Declaring it as a string emphasizes this atomicity.
 */

typedef char *string;



/*
 * Constants
 * ---------
 * MaxEmployees -- Maximum number of employees
 */

#define MaxEmployees 100

/*
 * Type: employeeRecordT
 * --------------ax Employees-----
 * This structure defines a type for an employee record.
 */

typedef struct {
    char name[30];
    char title[30];
    char ssnum[30];
    double salary;
    int withholding;
} employeeRecordT;

/*
 * Type: employeeT
 * ---------------
 * This type definition introduces an employeeT as a
 * pointer to the same record type as before.
 */

typedef struct {
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
} *employeeT;

/*
 * Type: payrollT
 * --------------
 * This type represents an entire collection of employees.  The
 * type definition uses a dynamic array of employeeT values to
 * ensure that there is no maximum bound imposed by the type.
 * The cost of this design is that the programmer must explicitly
 * allocate the storage for the array using NewArray.
 */

typedef struct {
    employeeT *employees;
    int nEmployees;
} *payrollT;

/*
 * Global variables
 * ----------------
 * staff       -- Array of employees
 * nEmployees  -- Number of employees
 * manager     -- Used to produce a figure for the code
 */

static employeeRecordT staff[MaxEmployees];
static int nEmployees;

static employeeRecordT manager = {
    "Ebenezer Scrooge", "Partner", "271-82-8183", 250.00, 1
};

/* Private function declarations */

static void InitEmployeeTable(void);
static payrollT CreatePayroll(employeeRecordT staff[], int nEmployees);
static payrollT GetPayroll(employeeRecordT staff[], int nEmployees);
static double AverageSalary(payrollT payroll);
static void PayrollTax(payrollT payroll);

/* Main program */

main()
{
    int i = 0;
    payrollT payroll;
    InitEmployeeTable();
    payroll = GetPayroll(staff, nEmployees);
    PayrollTax(payroll);
}

static void InitEmployeeTable(void)
{
    employeeRecordT empRec[MaxEmployees];
    int i = 0, with;
    char* a = malloc(30 * sizeof(char));
    char* b = malloc(30 * sizeof(char));
    double Salary;
    printf("How many employees: ");
    scanf(" %d", &nEmployees);
    for(i; i < nEmployees; i++){
    printf("Name: ");
    scanf("%s %s", a, b);
    strcat(strcat(a," "), b);
    strcpy(empRec[i].name, a);
    printf("Title: ");
    scanf(" %s", a);
    strcpy(empRec[i].title, a);
    printf("SSN: ");
    scanf(" %s", a);
    strcpy(empRec[i].ssnum, a);
    printf("Salary: ");
    scanf(" %lf", &Salary);
    empRec[i].salary = Salary;
    printf("Withholding: ");
    scanf(" %d", &with);
    empRec[i].withholding = with;
    staff[i] = empRec[i];
	}/*
    empRec.name = "Ebenezer Scrooge";
    empRec.title = "Partner";
    empRec.ssnum = "271-82-8183";
    empRec.salary = 250.00;
    empRec.withholding = 1;
    staff[0] = empRec;
    empRec.name = "Bob Cratchit";
    empRec.title = "Clerk";
    empRec.ssnum = "314-15-9265";
    empRec.salary = 15.00;
    empRec.withholding = 7;
    staff[1] = empRec;
    nEmployees = 2;*/
    free(a);
    free(b);
}

static payrollT CreatePayroll(employeeRecordT staff[], int nEmployees)
{
    int i;
    payrollT payroll;
    payroll = (payrollT) malloc(sizeof *payroll); // New(payrollT);
    payroll->employees = (employeeT *) malloc(nEmployees*sizeof(employeeT)); // NewArray(nEmployees, employeeT);
    payroll->nEmployees = nEmployees;
    for (i = 0; i < nEmployees; i++) {
        payroll->employees[i] = (employeeT)malloc(sizeof *((employeeT) NULL));   // (New(employeeT);
	payroll->employees[i]->name = staff[i].name;
        payroll->employees[i]->title = staff[i].title;
        payroll->employees[i]->ssnum = staff[i].ssnum;
        payroll->employees[i]->salary = staff[i].salary;
        payroll->employees[i]->withholding = staff[i].withholding;
	}
	return(payroll);
}

static payrollT GetPayroll(employeeRecordT staff[], int nEmployees)
{
     int i;
     payrollT payroll;
     payroll = CreatePayroll(staff, nEmployees);
	for (i = 0; i < nEmployees; i++)
	printf("Employee #%d\n\tName: %s\n\tTitle: %s\n\tSSNum: %s\n\tSalary: %.2lf\n\tWithholding exeptions: %d\n",i+1, payroll->employees[i]->name, payroll->employees[i]->title, payroll->employees[i]->ssnum, payroll->employees[i]->salary, payroll->employees[i]->withholding);
	return(payroll);
}


static double AverageSalary(payrollT payroll)
{
    double total;
    int i;

    total = 0;
    for (i = 0; i < payroll->nEmployees; i++) {
        total += payroll->employees[i]->salary;
    }
    return (total / nEmployees);
}

static void PayrollTax(payrollT payroll)
{
	int i, j, m, n;
	double k, l;
	printf("Name %19s %7s %10s\n", "Gross", "Tax", "Net");
	for(i = 0; i < 50; i++)
		printf("-");
	printf("\n");
	for(j = 0; j < payroll->nEmployees; j++){
		k = (payroll->employees[j]->salary);
		l = ((k - (payroll->employees[j]->withholding)) * .25);
		printf("%-20s%.2lf%2s %2.2lf%2s %2.2lf\n", payroll->employees[j]->name, k, "-",  l, "=", k - l);
	}
	n = (payroll->nEmployees);
	for(m = 0; m < n; m++)
		free(payroll->employees[m]);
	free(payroll->employees);
	free(payroll);
}
