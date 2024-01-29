#include <stdio.h>
#include <string.h>

int main() {
    char time[6];
    int age;
    int price;

    printf("Enter 'day' or 'night': ");
    scanf("%s", time);

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 4) {
        price = 0;
    } else if (strcmp(time, "day") == 0) {
        price = 8;
    } else if (age <= 16) {
        price = 12;
    } else if (age <= 54) {
        price = 15;
    } else {
        price = 13;
    }

    printf("Your movie ticket price is: $%d\n", price);

    return 0;
}
