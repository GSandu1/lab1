#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int n;
    int aleg = 0, mem = 0, complet = 0;
    int l;
    system("cls");
    do
    {
        printf(" \n _______________________________  Meniu  _______________________________ \n");
        printf(" \n |1. Create the list in Dinamic memory.                                |");
        printf(" \n |2. Type list elements                                                |");
        printf(" \n |3. Append                                                            |");
        printf(" \n |4. Prepend                                                           |");
        printf(" \n |5. Reverse                                                           |");
        printf(" \n |6. Add a value to the specific index                                 |");
        printf(" \n |7. Remove a value to the specific index                              |");
        printf(" \n |8. Sort the linked lis, with re-arranging the cells                  |");
        printf(" \n |9. Search for a value                                                |");
        printf(" \n |10.Join two linked list                                              |");
        printf(" \n |11.Backwards traversal                                               |");
        printf(" \n |11.Exit the program                                                  |");
        printf(" \n _______________________________________________________________________ \n");

        printf(" \n\n\nChoose an option: ");
        scanf("%d", &aleg);

        switch (aleg)
        {
        case 1:
            //crearea liste
            printf("Type number of elements");
            scanf("%d", &n);
            if (n<=0)
            {
                printf(" Enter a number bigger than 0.\n Type the number: ");
                scanf("%d", &n);
            }
            creare(n);
            if (head == NULL)
            {
                 printf(" ERROR: List was not created \n");
                 return 1;
            }
            else
            {
                printf("List was created with succes \n");
            }
            mem = 1;
            printf(" \n\n-------------------------- \n");
            break;



         case 2:
            //introducerea datelor
            if (mem == 1)
            {
                printf(" Type the elements : \n");
                scan_stat();
                complet = 1;
                printf(" -------------------------- \n");
            }
            else
            {
                system("cls");
                printf(" You didn't allocate memory \n Acces point '1' for alocating memory \n\n");
                printf(" --------------------------\n");
            }
            break;


           case 3:
           //append(Add a node after a given node)
                append();
           break;

           case 4:
           //prepend(add a node at the front)
                prepend();
           break;

           case 5:
           //reverse the list
                reverse();
           break;

           case 6:
           //add value to a specific index
                add_value();
           break;

           case 7:
           //remobe a value from a specific index
                remove_value();
           break;

           case 8:
           //sorting with re-arranging the cells
                sort();
           break;

           case 9:
           //searching for a value
                search_value();
           break;

           case 10:
           //joining two lists
                 join_list();
           break;

           case 11:
           //backwards trsversa;
                 back_traversal();
           break;

           case 0:
           printf(" \n Program had been stoped. ");
           break;


           default:
             system("cls");
             printf(" \n\nError  There is no such an option in the meniu\n\n ");
             printf(" -------------------------- \n");

        }
    } while (aleg !=0);
    return 0;
}
