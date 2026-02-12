#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int choice, id;

    fp = fopen("employee.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("employee.dat", "wb+");
        if (fp == NULL) {
            printf("File cannot be created.\n");
            return 1;
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee by ID\n");
        printf("3. Modify Employee\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter ID: ");
            scanf("%d", &emp.id);
            printf("Enter Name: ");
            scanf("%s", emp.name);
            printf("Enter Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, (emp.id - 1) * sizeof(emp), SEEK_SET);
            fwrite(&emp, sizeof(emp), 1, fp);
            printf("Record added.\n");
            break;

        case 2:
            printf("Enter ID to display: ");
            scanf("%d", &id);

            fseek(fp, (id - 1) * sizeof(emp), SEEK_SET);
            fread(&emp, sizeof(emp), 1, fp);

            if (emp.id != id) {
                printf("Record not found.\n");
            } else {
                printf("ID: %d\nName: %s\nSalary: %.2f\n",
                       emp.id, emp.name, emp.salary);
            }
            break;

        case 3:
            printf("Enter ID to modify: ");
            scanf("%d", &id);

            fseek(fp, (id - 1) * sizeof(emp), SEEK_SET);
            fread(&emp, sizeof(emp), 1, fp);

            if (emp.id != id) {
                printf("Record not found.\n");
            } else {
                printf("Enter new Name: ");
                scanf("%s", emp.name);
                printf("Enter new Salary: ");
                scanf("%f", &emp.salary);

                fseek(fp, (id - 1) * sizeof(emp), SEEK_SET);
                fwrite(&emp, sizeof(emp), 1, fp);
                printf("Record updated.\n");
            }
            break;

        case 4:
            rewind(fp);
            while (fread(&emp, sizeof(emp), 1, fp)) {
                printf("\nID: %d\nName: %s\nSalary: %.2f\n",
                       emp.id, emp.name, emp.salary);
            }
            break;

        case 5:
            fclose(fp);
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
