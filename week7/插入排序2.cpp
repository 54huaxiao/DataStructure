// Problem#: 16215
// Submission#: 4084060
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int test, n, num;
    int max, count;
    scanf("%d", &test);
    while (test--)
    {
        count = 0;
        scanf("%d", &n);
        scanf("%d", &max);
        for (int i = 1; i < n; i++){
            scanf("%d", &num);
            if (max < num)
            {
                 max = num;  
            }
            else
            {
                 count += 5;                
            }
        }  
        printf("%d\n", count);   
    }
    
   // system("PAUSE");
    return 0;    
}                                 