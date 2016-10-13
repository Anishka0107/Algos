#include <stdio.h>
#define INDEX 7

int main() {
    int n, i, hoax = 0;
    printf ("Enter the number of elements you want : ");
    scanf ("%d", &n);
    int arr[n], iarr[(n/INDEX)+1];
    printf ("Enter the array of data : ");
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    // filling the index maintaining array    
    for (i = 0; ; i++) {
        if (hoax >= n)
            break;
        iarr[i] = arr[hoax];
        hoax = hoax + INDEX;
    }
    for (i = 0; i<(n/INDEX)+1;i++)
    printf("%d   ",iarr[i]);
    printf("\n");
    int search;
    printf ("Enter the element you wish to search for : ");
    scanf ("%d", &search);
    if (search < arr[0]) {
        printf ("Sorry! Element not found!");
        return 0;
    }
    for (i = 0; i < (n/INDEX)+1; i++) {
        hoax = i;
        if (search < iarr[i])
            break;
    }
    hoax--;
    if (hoax == (n/INDEX)-1) {
        for(i = INDEX*(hoax+1); i < n; i++) {
            if ( arr[i] == search){
                printf ("Element found at index %d", i);
                return 0;
            }            
        }
    }
    if (iarr[hoax] == search) {
        printf ("Element found at index %d", INDEX * hoax);
        return 0;
    }
    for (i = INDEX*hoax+1; i <= INDEX*(hoax+1); i++) {
        if ( arr[i] == search){
            printf ("Element found at index %d", i);
            return 0;
        }
    }
    printf ("Sorry! Element not found!");
    return 0;
}