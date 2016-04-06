// Problem#: 16582
// Submission#: 4182116
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <cstdlib>
int a[102] = {0};
int sorted_a[102] = {0};
int b[102] = {0};
int sorted_b[102] = {0};
int ans[204] = {0};

void swap(int * first, int * second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}
int partion(int *arr, int low, int high) {
/*
    srand(time(NULL));
    int index = rand() % (high - low) + low;
    swap(arr + low, arr + index);
*/
    int index = low;
    int num = arr[low];
    index = low;
    for (int i = low; i < high + 1; i++) {
        if (num > arr[i]) {
            index++;
            swap(arr + index, arr + i);
        }
    }
    swap(arr + low, arr + index);
    return index;
}
void sort_array(int *arr, int low, int high) {
    if (low < high) {
        int mid = partion(arr, low, high);
        sort_array(arr, low, mid - 1);
        sort_array(arr, mid + 1, high);
    }
}
int bineary_search(int *arr, int num, int low, int high) {
    int mid = low + (high - low) / 2;
    while (low <= high) {
        if (num == arr[mid]) {
            return mid;
        } else if (num > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }
    return -1;
}
void print(int * arr, int upper) {
    for (int i = 0; i < upper; i++) {
        printf("%d ", arr[i]);
    }
}
void jiaoji(int m, int n) {
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (-1 != bineary_search(sorted_b, a[i], 0, n - 1)) {
            ans[k++] = a[i];
        }
    }
    print(ans, k);
    printf("\n");
}
void bingji(int m, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (-1 == bineary_search(sorted_a, b[i], 0, m - 1)) {
            ans[k++] = b[i];
        }
    }
    print(a, m);
    print(ans, k);
    printf("\n");
}
void chaji(int m, int n) {
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (-1 == bineary_search(sorted_b, a[i], 0, n - 1)) {
            ans[k++] = a[i];
        }
    }
    print(ans, k);
    printf("\n");
}

int main(void) {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            sorted_a[i] = a[i];
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            sorted_b[i] = b[i];
        }
        sort_array(sorted_a, 0, m - 1); // print(sorted_a, m); printf("\n");
        sort_array(sorted_b, 0, n - 1); // print(sorted_b, n); printf("\n");

        jiaoji(m, n);
        bingji(m, n);
        chaji(m, n);

    }
    return 0;
}                                 