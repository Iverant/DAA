#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strmatch(char text[], char pattern[]){

    int n = strlen(text);
    int m = strlen(pattern);

    int i, j;

    for (i = 0; i<=n-m; i++){
        j = 0;
        while (j<m && text[i+j] == pattern[j]){
            j = j+1;

        }
        if(j==m){
            return i;
        }

    }
    return -1;
}

int main(){

    char text[100];
    char pat[100];

    printf("Enter text\n");
    scanf("%s", text);

    printf("Enter pattern\n");
    scanf("%s", pat);

    printf("String matched is %d", strmatch(text, pat));

}