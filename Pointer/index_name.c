//co 1 danh sach co san. neu danh so thu tu thi tra lai dung ten

#include <stdio.h>

int main() {
    char answer = 'Y';
    while (answer == 'Y') {
        static char *list[] = {"Sai ma", "Nguyen Van Mot", "Tran Thi Hai", "Bui Thi Ba", "Le Thi Na",   "Le Van Xa", "Nguyen Xi"};
    
        int index;
        printf("Input the index number: "); scanf("%d", &index);
    
        printf("Index %d is: %s\n", index, (index < 1 || index > 6) ? list[0] : list[index]);
        
        printf("Do you want to restart the program? (Y/N)\n");
        scanf("%s", &answer);
    }
    return 0;
}