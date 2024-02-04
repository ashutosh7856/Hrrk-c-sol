#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;

int** total_number_of_pages;

int main()
{

    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    total_number_of_books = (int*)malloc(total_number_of_shelves * sizeof(int));
    for (int i = 0; i < total_number_of_shelves; i++){
        total_number_of_books[i] = 0;
    }
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {

            int shelf, pages_on_book;
            scanf("%d %d", &shelf, &pages_on_book);
            int number_of_books_shelf = total_number_of_books[shelf];
            
            if (total_number_of_pages[shelf] == NULL){
                total_number_of_pages[shelf] = (int*)malloc(sizeof(int));
            } else {
                total_number_of_pages[shelf] = (int*) realloc(total_number_of_pages[shelf], (number_of_books_shelf+1) * sizeof(int));
    
            }
            
            total_number_of_pages[shelf][number_of_books_shelf] = pages_on_book;
            
            total_number_of_books[shelf]++;

        }
    }
}