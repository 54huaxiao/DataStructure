#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
int main() {
    char alp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w','x',
    'y', 'z'};
    int num[26] = {2, 4, 6, 3,6, 9, 4, 8, 12, 5, 10, 15, 6, 12, 18,
    7, 14, 21, 28, 8, 16, 24, 9, 18, 27, 36};
    map<char, int> keyboard;
    for (int i = 0; i < 26; i++) {
        keyboard[alp[i]] = num[i];
    }
    int words;
    int sum = 0;
    char *word;
    word = new char[101];
    scanf("%d", &words);
    for (int i = 0; i < words; i++) {
        scanf("%s", word);
        int len = strlen(word);
        for (int j = 0; j < len; j++) {
            if ( 'A' <= word[j] && word[j] <= 'Z')
                 word[j] = word[j] + 32;
            sum += keyboard[word[j]];
        }
        printf("%d\n", sum);
        sum = 0;
   }
   return 0;
}                                 
