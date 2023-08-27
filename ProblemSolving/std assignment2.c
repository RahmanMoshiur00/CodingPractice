#include <stdio.h>

int tree[21];

void insertion(int x, int i)
{
    if(tree[i] == -1){
        tree[i] = x;
        return;
    }
    if(x >= tree[i]){
        insertion(x, 2*i + 1);
    }
    else{
        insertion(x, 2*i);
    }
}

void show()
{
    printf("Current status of the array:\n");
    int i;
    for(i=0; i<21; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    int i;
    for(i=0; i<21; i++) tree[i] = -1;

    if(choice == 1){ // inserting a new value into the BST
        printf("Enter a value: ");
        int v;
        scanf("%d", &v);

        insertion(v, 1);

        show();
    }

    return 0;
}
