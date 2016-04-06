#include<iostream>
const int SIZE = 6;
int coin[6] = {10000, 5000, 2000, 1000, 500, 100};
int exchange(int n);
int num[SIZE];
using namespace std;
int main() {
    int count, money;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> money;
        for (int j = 0; j < SIZE; j++)
            num[j] = 0;
        exchange(money*100);
        cout << num[0]+num[1]+num[2]+num[3]+num[4]+num[5] << endl;
    }
    return 0;
}
int exchange(int n)
{
   int i;
  for (i=0; i<SIZE; i++)
    if (n >= coin[i]) break;
  while (n>0 && i<SIZE)
  {
    if(n >= coin[i])
    {
      n -= coin[i];
      num[i]++;
    }else if(n<10 && n>=5)
    {
      num[SIZE-1]++;
      break;
    }else i++;
  }
  return 0;
}                                 
