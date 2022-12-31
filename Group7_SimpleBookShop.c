#include <stdio.h>  // to import standard input and output like printf scanf fgets
#include <string.h> // provides functions for manipulating strings like strcpy, strcasecmp
#include <stdlib.h> // provides functions for general utility operations in C, such as exit

#define MAX_BOOKS 500 //identifier that MAX_BOOKS should be replaced with the value 500
//MAX_BOOKS is used to define the size of the books array to store information about the books in the shop


// declare all variables which store their respective data using structure 'Book'
 struct Book {

    char title[50];  // to store name of the book
    char author[30];  // to store name of the author of the book
    float price;  // to store cost of the book
    int copies;  // to store number of copies of the book
};

    int numBooks = 0; //initial book number
    struct Book b[MAX_BOOKS];//array declaration in C language that declares an array of struct Book objects with the name b


void WelcomeMessage()
{
    printf("\n\n\n");
    printf("\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\tWelcome to Simple Book Management System\n");
    printf("\n\t\t********************************************************************************************\n");


}

void showMenuOptions()
{
        printf("\n\n\t\tPlease select a menu option number:");
        printf("\n\n\t\t1)Display this menu.");
        printf("\n\t\t2)Show all available books.");
        printf("\n\t\t3)Add a book to the book shop.");
        printf("\n\t\t4)Search a book by title.");
        printf("\n\t\t5)Display the total number of books.");
        printf("\n\t\t6)Exit from this book shop system.");

}


void addBook()
 {
// Use an if statement to check if the book shop is full
    if (numBooks == MAX_BOOKS)
    {
        printf("\n\t\tError: Book shop is full.\n");

    }

  else{
// Get the book information from the user
    fflush(stdin);
    printf("\n\t\t\tEnter book title: ");
    fgets(b[numBooks].title, 50, stdin);
//function call in C language that reads a line of text from the standard input stream and stores it in the 'title' field of the 'numBooks' element of the b array

    printf("\t\t\tEnter book author: ");
    fgets(b[numBooks].author, 30, stdin);

    printf("\t\t\tEnter book price: ");
    scanf("%f", &b[numBooks].price);

    printf("\t\t\tEnter number of copies: ");
    scanf("%d", &b[numBooks].copies);

    // Increment the number of books in the book shop
      numBooks++;

    }
}


// Function to show a list of all the books in the book shop
void showBooks()
{
    if(numBooks == 0)
    {
        printf("\n\t\t\tThere are no books stored!!\n\n ");
    }

    else
    { printf("\n\n\t\tList of books: ");
        for (int i = 0; i < numBooks; i++)
        {
        //printf() statements that print the details of the books in the b array.
            printf("\n\t\t\tBook title: %s", b[i].title);
        //The i element of the b array is accessed using the b[i] syntax, and the fields of the Book structure are accessed using the '.' operator. b[i].title
            printf("\t\t\tBook author: %s", b[i].author);
            printf("\t\t\tBook price: %.2f", b[i].price);
            printf("\n\t\t\tBook copies: %d\n", b[i].copies);
                        //The loop terminates when the loop counter variable i reaches numBooks
        }
    }
}

// Function to search for a book in the book shop by title
    void searchBook() {
    char title[50];
    fflush(stdin);
    printf("\n\n\t\tEnter book title to search: ");
    fgets(title, 50, stdin); //fgets function is used to read a line of input from the stdin stream and store it in the title char array

// Use a for loop to search for the book in the book shop

    int found = 0; //found is used to keep track of whether a book with the specified title has been found in the list of books

    for (int i = 0; i < numBooks; i++)
{
    if (strcasecmp(b[i].title, title) == 0) { //strcasecmp function is a function in C standard library that compares two strings by ignoring the case of the characters

// Use a printf statement to print the book information
        printf("\n\t\t\tBook title: %s", b[i].title);
        printf("\t\t\tBook author: %s", b[i].author);
        printf("\t\t\tBook price: %.2f", b[i].price);
        printf("\n\t\t\tBook pages: %d", b[i].copies);
    found = 1; //if statement sets the value of found to 1, when the book is found
    break;
}
}
// Use an if statement to print a message if the book was not found
    if (!found) {
    printf("\n\t\t\tBook not found.");
    }
}

// Function to show the number of books in the book shop
   void showNumberOfBooks()
{
    printf("\n\t\t\tNumber of books in the book shop: %d\n", numBooks);
}


void GoodByeMessage()
{
    printf("\n\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\tThank You for using Simple Book Management System.\n");
    printf("\n\t\t********************************************************************************************\n");

}


// main function
    int main() {

    int choice;

    WelcomeMessage();
    showMenuOptions();

// Use a while loop to allow the user to perform multiple actions
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
            // to exit from the program
                GoodByeMessage();
            exit(0);
                break;

            default:
            // if any number other than 1, 2, 3, 4, 5, 6 is entered
            printf("\n\n\n\t\t\tINVALID INPUT!! Try again...");
                                                    //Switch Ended
        }

    }

}

