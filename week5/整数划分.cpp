#include<stdio.h>
int list[255];
void split(int n, int m){
    // 如果分割完毕
    if (n == 0){
        // 遍历输出数组
        for (int i = 0; i < m - 1; i++){
            printf("%d+", list[i]);
        }
        printf("%d\n", list[m - 1]);

        return;
    }

    // 由大到小进行分割
    for (int i = n; i >= 1; i--){
        // 如果未分割或当前分割的数字不大于上一个分割的数字
        if (m == 0 || i <= list[m - 1]){
            // 将分割的数字存入数组
            list[m] = i;
            // 分割剩下的数字
            split(n - i, m + 1);
        }
    }
}

int main() {
    int T, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        split(n, 0);
    }
    return 0;
}                               
