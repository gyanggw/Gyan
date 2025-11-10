#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100


int ids[MAX_BOOKS] = {101, 102, 103, 104,105,106,107,108};
char titles[MAX_BOOKS][TITLE_LEN] = {
    "rich dad poor dad",
    "Chemistry",
    "Physics",
    "Maths",
    "Computer",
    "let use c",
    "Aksharanand",
    "Programming in c"
};
int available[MAX_BOOKS] = {1, 0, 1, 1, 1, 1, 1, 1};
int totalBooks = 8;
float fineRate = 20.0;


void totalBooksCount();
void borrowBook(int bookID);
float calculateFine();
int availableBooksList(int ids[], char titles[][TITLE_LEN]);

int main() {
    int choice, id;
    float fine;

    do {
        printf("\n ===== Library Management System ===== \n");
        printf(" 1. Show total number of books \n");
        printf(" 2. Borrow a book  \n");
        printf(" 3. Calculate fine for overdue books \n");
        printf(" 4. Show available books \n");
        printf(" 5. Exit \n");
        printf(" Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                totalBooksCount();
                break;
            case 2:
                printf("Enter Book ID to borrow: ");
                scanf("%d", &id);
                borrowBook(id);
                break;
            case 3:
                fine = calculateFine();
                printf("Fine amount: %.2f\n", fine);
                break;
            case 4:
                availableBooksList(ids, titles);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}


void totalBooksCount() {
    printf("\nTotal number of books in library: %d\n", totalBooks);
}


void borrowBook(int bookID) {
    int found = 0;
    for (int i = 0; i < totalBooks; i++) {
        if (ids[i] == bookID) {
            found = 1;
            if (available[i]) {
                available[i] = 0;
                printf("You borrowed '%s'.\n", titles[i]);
            } else {
                printf("Book '%s' is already borrowed.\n", titles[i]);
            }
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
}

float calculateFine() {
    int days;
    printf("Enter number of overdue days: ");
    scanf("%d", &days);
    if (days <= 0)
        return 0.0;
    else
        return days * fineRate;
}

int availableBooksList(int ids[], char titles[][TITLE_LEN]) {
    int count = 0;
    printf("\nAvailable Books in Library:\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < totalBooks; i++) {
        if (available[i]) {
            printf("ID: %d | Title: %s\n", ids[i], titles[i]);
            count++;
        }
    }
    if (count == 0)
        printf("No books currently available.\n");
    printf("-----------------------------------------\n");
    printf("Total available books: %d\n", count);
    return count;
}
