#include <stdio.h>
void Savings(int n);
int main() {
    int n;

    printf("Enter number of months: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input.\n");
       
    }else{
    Savings(n);
    }
    return 0;
}
void Savings(int n){
    int a = 1, b = 1;

    printf("Saving Series:\n");

    if (n >= 1)
        printf("Month 1: %d\n", a);
    if (n >= 2)
        printf("Month 2: %d\n", b);

    for (int i = 3; i <= n; i++) {
        int temp = a + b;
        printf("Month %d: %d\n", i, temp);
        a = b;
        b = temp;
    }
}

