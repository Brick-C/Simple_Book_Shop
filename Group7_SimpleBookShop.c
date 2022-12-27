#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 500

 struct Book {
    char title[50];
    char author[30];
    float price;
    int copies;
};

    int numBooks;
    struct Book b[MAX_BOOKS];


void addBook()
 {
// Use an if statement to check if the book shop is full
    if (numBooks == MAX_BOOKS)
    {
    printf("\n\t\tError: Book shop is full.\n");
    return 0;
  }
  else{
// Get the book information from the user
    fflush(stdin);
    printf("\n\t\t\tEnter book title: ");
    fgets(b[numBooks].title, 50, stdin);

    printf("\n\t\t\tEnter book author: ");
    fgets(b[numBooks].author, 30, stdin);

    printf("\n\t\t\tEnter book price: ");
    scanf("%f", &b[numBooks].price);

    printf("\n\t\t\tEnter number of copies: ");
    scanf("%d", &b[numBooks].copies);

    // Increment the number of books in the book shop
      numBooks++;
      return 1;
    }
}


// Function to show a list of all the books in the book shop
void showBooks()
{
    if(numBooks == 0)
    {
        printf("\n\t\tThere are no books stored!!\n\n ");
    }

    else
    { printf("\n\n\t\tList of books: ");
        for (int i = 0; i < numBooks; i++)
        {
            printf("\n\t\t\tBook title: %s", b[i].title);
            printf("\t\t\tBook author: %s", b[i].author);
            printf("\t\t\tBook price: %.2f", b[i].price);
            printf("\n\t\t\tBook copies: %d\n", b[i].copies);

        }
    }
}

// Function to search for a book in the book shop by title
    void searchBook() {
    char title[50];
    fflush(stdin);
    printf("\n\n\t\tEnter book title to search: ");
    fgets(title, 50, stdin);

// Use a for loop to search for the book in the book shop
    int found = 0;

    for (int i = 0; i < numBooks; i++)
{
    if (strcasecmp(b[i].title, title) == 0) {
// Use a printf statement to print the book information
        printf("\n\t\t\tBook title: %s", b[i].title);
        printf("\t\t\tBook author: %s", b[i].author);
        printf("\t\t\tBook price: %.2f", b[i].price);
        printf("\n\t\t\tBook pages: %d", b[i].copies);
    found = 1;
    break;
}
}
// Use an if statement to print a message if the book was not found
    if (!found) {
    printf("\n\t\tBook not found.");
    }
}

// Function to show the number of books in the book shop
   void showNumberOfBooks()
{
    printf("\n\t\tNumber of books in the book shop: %d\n", numBooks);
}




void WelcomeMessage()
{
    printf("\n\n\n");
    printf("\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\tWelcome to Simple Book Management System\n");
    printf("\n\t\t********************************************************************************************\n");


}

void showMenuOptions()
{

        printf("\n\n\n\t\t1)Display this menu.");
        printf("\n\t\t2)Show all available books.");
        printf("\n\t\t3)Add a book to the book shop.");
        printf("\n\t\t4)Search a book by title.");
        printf("\n\t\t5)Display the total number of books.");
        printf("\n\t\t6)Exit from this book shop system.");

}

void GoodByeMessage()
{
    printf("\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\tThank You for using Simple Book Management System.\n");
    printf("\n\t\t********************************************************************************************\n");

}

    int main() {
// Array of structures to store information about books
    struct Book b[MAX_BOOKS];
    int numBooks = 0;

// Use a while loop to allow the user to perform multiple actions
    char input[50];

    int i, choice, count;
    i = choice = count = 0;

    WelcomeMessage();
    showMenuOptions();


    while(choice!=6)
    {

        printf("\n\n\n\t\tEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            // in order to add the book details
            case 1:
                showMenuOptions();
                break;

            case 2:
                showBooks();
                break;

            case 3:
                addBook();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                showNumberOfBooks();
                break;

            case 6:
                GoodByeMessage();
            exit(1);
                break;

            default:
            printf("\n\n\n\t\t\tINVALID INPUT!! Try again...");
                                                    //Switch Ended
        }

    }

}

