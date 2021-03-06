#include <stdio.h>
#include <string.h>

typedef struct employee_struct {
    char name[30];
    char age[20];
    char birth_place[30];
    char salary[20];
    char year[20];
} employee;

typedef struct name {
    char f_name[10];
    char m_name[20];
    char l_name[10];
} name_strct;

int main() {
    FILE *e_list;
    e_list = fopen("/Users/trangnguyen/Desktop/tt-nv.txt", "r");
    
    char lines[20][255];
    employee e_arr[20];
    int index = 0;
    const char delim[2] = ",";
    
    while(!feof(e_list) && index < 20) {
        fgets(lines[index], 255, e_list);
//        printf("%s", lines[index]);
        char *token;
        token = strtok(lines[index], delim);
        int comma = 0;
        while (token != NULL) {
            switch (comma) {
                case 0:
                    strcpy(e_arr[index].name, token);
                    comma++;
                    break;
                case 1:
                    strcpy(e_arr[index].age, token);
                    comma++;
                    break;
                case 2:
                    strcpy(e_arr[index].birth_place, token);
                    comma++;
                    break;
                case 3:
                    strcpy(e_arr[index].salary, token);
                    comma++;
                    break;
                case 4:
                    strcpy(e_arr[index].year, token-1);
                    comma++;
                    break;
                default:
                    break;
            }
            token = strtok(NULL, delim);
        }
        index++;
    }
    
    /*
     Sort by name
     */
    
    employee temp;
    int i;
    char space[2] = " ";
    name_strct e_name[20];
    
    for (i=0; i<20; i++) {
        char *token;
        token = strtok(e_arr[i].name, space);
        int space_count = 0;
        while (token != NULL) {
            if (space_count == 0) {
                strcpy(e_name[i].l_name, token);
//                printf("%s\n", e_name[i].l_name);
                space_count++;
            }
            char *last = strrchr(e_arr[i].name, '\0');
            
            if (last != NULL) {
                printf("%s\n", last+1);
            }
            
            token = strtok(NULL, delim);
        }
//        printf("%s\n", e_name[i].l_name);
    }
    
    name_strct cur;
    for (i = 0; i < 19; i++) {
        for (int j = i+1; j < 20; j++) {
            if (strcmp(e_name[i].l_name, e_name[j].l_name) > 0) {
                cur = e_name[i];
                temp = e_arr[i];
                e_name[i] = e_name[j];
                e_arr[i] = e_arr[j];
                e_name[j] = cur;
                e_arr[j] = temp;
            }
            
            if (strcmp(e_name[i].l_name, e_name[j].l_name) == 0 && (strcmp(e_name[i].f_name, e_name[j].f_name) > 0)) {
                cur = e_name[i];
                temp = e_arr[i];
                e_name[i] = e_name[j];
                e_arr[i] = e_arr[j];
                e_name[j] = cur;
                e_arr[j] = temp;
            }
        }
    }
    
    FILE *name_list;
    
    name_list = fopen("/Users/trangnguyen/Desktop/sort_name.txt", "r+");
    for (i=0; i<20; i++) {
        char tmp[255] = "";
        strcpy(tmp, e_arr[i].name);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].age);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].birth_place);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].salary);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].year);
        strcat(tmp, "\n");
        fputs(tmp, name_list);
    }
    
    /*
     Sort by age
     */
    
    for (i = 0; i < 19; i++) {
        for (int j = i+1; j < 20; j++) {
            if (strcmp(e_arr[i].age, e_arr[j].age) > 0) {
                temp = e_arr[i];
                e_arr[i] = e_arr[j];
                e_arr[j] = temp;
            }
        }
    }
    
    FILE *age_list;
    
    age_list = fopen("/Users/trangnguyen/Desktop/sort_age.txt", "r+");
    for (i=0; i<20; i++) {
        char tmp[255] = "";
        strcpy(tmp, e_arr[i].name);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].age);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].birth_place);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].salary);
        strcat(tmp, ", ");
        strcat(tmp, e_arr[i].year);
        strcat(tmp, "\n");
        fputs(tmp, age_list);
    }
    
    fclose(e_list);
    fclose(name_list);
    fclose(age_list);
    
    return 0;
}
