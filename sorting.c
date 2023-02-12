#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) 
{
    int i = 0;
    while ((a[i] || b[i]) && a[i] == b[i])
        i++;
    if (a[i] > b[i])
        return(1);
    else if (a[i] < b[i])
        return (-1);
    else 
        return (0);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    int i = 0;
     while ((a[i] || b[i]) && a[i] == b[i])
    {
        i++;
    }
    if (a[i] > b[i])
        return(-1);
    else if (a[i] < b[i])
         return(1);
    else 
        return (0);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int i = 0, j = 0, c1 = 0, c2 = 0;
    
    while(a[i])
    {
        if (i == 0)
            c1++;
        else if ( i > 0) 
        {
            j = i - 1;
            while(a[i] != a[j] && j >= 0)
                j--;
            if ( j == -1)
                c1++;
        }
        i++;
    }
    i = 0;
     while(b[i])
    {
        if (i == 0)
            c2++;
        else if ( i > 0) 
        {
            j = i - 1;
            while(b[i] != b[j] && j >= 0)
                j--;
            if ( j == -1)
                c2++;
        }
        i++;
    }
    if (c1 > c2)
        return (1);
    else if (c1 < c2)
        return (-1);
    else 
        return(lexicographic_sort(a, b)); 
}

int sort_by_length(const char* a, const char* b) 
{
    int i = 0, j = 0;
    while(a[i])
        i++;
    while(b[j])
        j++;
      if (i > j)
        return (1);
    else if (i < j)
        return (-1);
    else 
        return(lexicographic_sort(a, b)); 
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    int i = 0, j = 0;
    
    while(i < len )
    {
        j = i + 1;
        while (j < len)
        {
            if(cmp_func(arr[i], arr[j]) > 0)
            {
                char *c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
            j++;
        }
        i++;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
