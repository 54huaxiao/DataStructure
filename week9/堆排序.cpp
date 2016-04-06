// Problem#: 16581
// Submission#: 4214954
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>

int arr[10001], n;

int maxHeap(int i) {
    int cha = 0;
    if (i == 0) {
        return 0;
    }
    int temp;
    if (i % 2 == 0) {
        if (arr[i - 1] >= arr[i]) {
            if (arr[i - 1] > arr[(i - 1) / 2]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[(i - 1) / 2];
                arr[(i - 1) / 2] = temp;
                cha++;
            }
        } else {
            if (arr[i] > arr[(i - 1) / 2]) {
                temp = arr[i];
                arr[i] = arr[(i - 1) / 2];
                arr[(i - 1) / 2] = temp;
                cha++;
            }
        }
        i -= 2;
    } else {
        if (arr[i] > arr[(i - 1) / 2]) {
            temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
            cha++;
        }
        i--;
    }
    cha += maxHeap(i);
    return cha;
}

void delTop(int max) {
    int temp = arr[0];
    arr[0] = arr[max - 1];
    arr[max - 1] = temp;
    while (maxHeap(max - 2));
    return;
}

void print() {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    while (std::cin >> n) {

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        while (maxHeap(n - 1));
        
        print();

        for (int i = 0; i < n - 1; i++) {
            delTop(n - i);
            print();
        }
    }
    return 0;
}                                 