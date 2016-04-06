// Problem#: 16363
// Submission#: 4152647
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 16356
// Submission#: 4152642
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    void Qsort(int a[], int low, int high);
    int count;
    float sum = 0.0;
    int time[1001];
    int position[1001];
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> time[i];
        position[i] = i + 1;
    }
    int temp = 0, flag = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (time[j] > time[j + 1]) {
                temp = time[j];
                flag = position[j];
                time[j] = time[j + 1];
                position[j] = position[j + 1];
                time[j + 1] = temp;
                position[j + 1] = flag;
            }
        }
    }
    for (int i = 0; i < count-1; i++) {
        cout << position[i] << " ";
    }
    cout << position[count-1] << endl;
    for (int i = 0; i < count; i++)
        sum += (count - i-1)*time[i];
    printf("%.2f\n", sum / count);
    //system("pause");
    return 0;
}
void Qsort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while (first < last)
    {
        while (first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while (first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
        /*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}                                 