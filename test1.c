#include <stdio.h>
#pragma warning (disable: 4996)
int main(){
    const int MAX = 50;
    int size, Array[MAX];
    FILE *f1, *f2;
    //Read file into variables
    f1 = fopen("input.txt", "rt");
    fscanf(f1, "%d", &size);
    for (int i = 0; i < size; i++)
        fscanf(f1, "%d", &Array[i]);

    fclose(f1);

    //Result data after input from file
    for (int i = 0; i < size; i++)
        printf("%1d", Array[i]);
    
    return 0;
}