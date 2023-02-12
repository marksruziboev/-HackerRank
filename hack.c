#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    total_number_of_books = (int*) calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = (int**) calloc(total_number_of_shelves, sizeof(int*));
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            int shelf_index = x - 1;
            int book_index = total_number_of_books[shelf_index];
            
            if (!total_number_of_pages[shelf_index]) {
                total_number_of_pages[shelf_index] = (int*) calloc(1100, sizeof(int));
            }
            
            total_number_of_pages[shelf_index][book_index] = y;
            total_number_of_books[shelf_index]++;
            printf("%d\n", total_number_of_pages[shelf_index][book_index] );
            printf("%d\n", x);
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            int shelf_index = x - 1;
            int book_index = y - 1;
            
            printf("%d\n", total_number_of_pages[shelf_index][book_index]);
        } else {
            int x;
            scanf("%d", &x);
            int shelf_index = x - 1;
            
            printf("%d\n", total_number_of_books[shelf_index]);
        }
    }
    
    free(total_number_of_books);
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (total_number_of_pages[i]) {
            free(total_number_of_pages[i]);
        }
    }
    free(total_number_of_pages);
    
    return 0;
}

