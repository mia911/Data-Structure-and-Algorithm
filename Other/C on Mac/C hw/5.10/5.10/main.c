#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char ho_ten[30];
    char hoten[30];
    printf("Nhap vao ho va ten: ");fflush(stdin);
    gets(ho_ten);
    strcpy(hoten,ho_ten+1);
    // Bo khoang trang ben phai
    while(1){
        if(ho_ten[0]==' '){
            strcpy(ho_ten, hoten);
        }else{
            break;
        }
    }
    // Bo khoang trang ben trai
    while(1){
        int l = strlen(ho_ten)-1;
        if(ho_ten[l]==' '){
            ho_ten[l]='\0';
        }else{
            break;
        }
    }
    
    // Bo khoang trang khong co nghia o giua
    int k=0, l = strlen(ho_ten);
    while(k<l-1){
        if((ho_ten[k]==' ') && (ho_ten[k+1] == ' ')){
            strcpy(ho_ten+k, ho_ten+k+1);
        }else{
            k++;
        }
    }
    
    
    for(int m = 0; m<strlen(ho_ten);m++){
        ho_ten[m] = toupper(ho_ten[m]);
    }
    printf("Ho va ten:%s\n",ho_ten);
    
    for(int m = 0; m<strlen(ho_ten);m++){
        ho_ten[m] = tolower(ho_ten[m]);
    }
    printf("Ho va ten:%s",ho_ten);
    
    return 0;
}