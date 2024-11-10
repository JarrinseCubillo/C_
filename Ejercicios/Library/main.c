#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Library {
    char bookName[30];
    char authorName[30];
    int pagesNumber;
    float price;
};

void main() {
    struct Library library[100];
    char authorName[30], bookName[30];
    int cont=0,cont2=0,keepcount=0,itemFound=0;

    printf("<---*** Library Management System ***--->");

    while(cont2 !=6) {
        printf("\n\n1. Add book information\n2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&cont2);

        switch(cont2) {
            case 1:
                printf("Enter book name: ");
                scanf("%s",library[cont].bookName);

                printf("Enter author: ");
                scanf("%s",library[cont].authorName);

                printf("Enter pages number: ");
                scanf("%d",&library[cont].pagesNumber);

                printf("Enter price: ");
                scanf("%f",&library[cont].price);

                keepcount++;
                break;
            case 2:
                printf("You have entered the following information:\n ");
                printf("***********************************");
                for(cont=0;cont<keepcount;cont++) {
                    printf("Book name: %s\n",library[cont].bookName);
                    printf("Author: %s\n",library[cont].authorName);
                    printf("Pages number: %d\n",library[cont].pagesNumber);
                    printf("Price: %.2f\n",library[cont].price);
                }
                break;
            case 3:
                itemFound=0;
                printf("Enter author name: ");
                scanf("%s",authorName);
                for(cont=0;cont<keepcount;cont++) {
                    if(strcmp(authorName,library[cont].authorName)==0) {
                        printf("%s %s %d %f", library[cont].bookName,
                                                    library[cont].authorName,
                                                    library[cont].pagesNumber,
                                                    library[cont].price);
                        itemFound=1;
                    }
                }

                if(itemFound==0){
                  printf("Author %s is not available in the Library",authorName);  
                }
                break;
            case 4:
                itemFound=0;
                printf("Enter book name: ");
                scanf("%s",bookName);
                for(cont=0;cont<keepcount;cont++) {
                    if(strcmp(bookName,library[cont].bookName)==0) {
                        printf("%s \t %s \t %d \t %.2f", library[cont].bookName,
                                                       library[cont].authorName,
                                                       library[cont].pagesNumber,
                                                       library[cont].price);
                        itemFound=1;
                    }
                }

                if(itemFound==0){
                  printf("Book %s is not available in the Library",bookName);  
                }
                break;
            case 5:
                printf("\n Number of books in Library: %d",keepcount);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.");
                break;
        }
    }
}
