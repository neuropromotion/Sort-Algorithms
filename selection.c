/*Сортировка выбором (Selection sort). Сначала происходит поиск в массиве самого большого элемента, и он вставляется на самое последнее месте.
Далее в оставшемся массиве (за исключением последнего элемента, он уже отсортирован) происходит также поиск самого большого элемента и он вставляется
на предпоследнее место и так далее
Сложность: в лучшем , среднем и худшем случае един: O(n^2/2)  */
#include <stdio.h> 
#define MASK 10000000000000000000000000000000 // побитовая маска для получения самого максимального отрицательного числа
int main (void)
{   
    int arr [] = {5, 6, 23, 43, 2, 1, 66, 4, 34, 0, -2, -666, 666, 102, 233, 421, 2, 66};
    int size = sizeof(arr)/sizeof(int);
    int temp, temp_2; // две временные переменные
    int temp_size = size; // получаем размер массива для того что бы сокращать его при каждой итерации во внутреннем цикле
    int index; // переменная запоминает индекс самой большой цифры для того что бы обменять их местами с последним элементом
    for (int i = 0; i < size; i++)
    {
        temp = 0;
        temp = temp | MASK; // получаем самый маленький размер int для сравнения
        for (int j = 0; j < temp_size; j++)  
        {
            if (arr[j] > temp) //ищем самую большое значение элемента массива 
            {
                temp = arr[j]; // сохраняем самое большое значение в переменную temp
                index = j; // сохраняем индекс найденного самого большого элемента массива
            } 
        }
        temp_2 = arr[temp_size - 1]; //после выхода из цикла мы нашли самое большое значение, пора его поменять местами с последним элементом
        arr[temp_size - 1] = arr[index]; // меняем их местами
        arr[index] = temp_2;
        temp_size--; // сокращаем сортировку в массиве на -1 (последний элемент массива уже отсортирован)
    }
    for (int i = 0; i < size; i++)
        printf("Element %d: [%d]\n", i+1, arr[i]);
} 