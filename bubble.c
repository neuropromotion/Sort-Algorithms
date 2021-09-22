/* Пузырьковая сортировка (bubble sort). Сложность О(n) в лучшем случае, O(n^2) в худшем. Подходит для сортировки малых массивов */
#include <stdio.h>
int main (void)
{  
      int arr [] = {5, 6, 23, 43, 2, 1, 66, 4, 34, 0, -2, -666, 666, 102, 233, 421, 2, 66};
      int size = sizeof(arr)/sizeof(int);
      int temp;
 
      for (int i = 1; i < size; i++)
      {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
      }
      for (int i = 0; i < size; i++)
            printf("Element %d: [%d]\n", i+1, arr[i]);
} 