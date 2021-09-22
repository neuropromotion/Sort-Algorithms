/* Сортировка кучей, она же пирамидальная сортировка (heap sort)
Основная задача создать двоичную структуру данных, которая называется кучей. Из представленного массива создается инициальное
дерево, где в корне стоит 0-ой элемент, а его дочерними узлами будут 1-й и 2-й элемент. У последних дочерними будут 3-й, 4-й, 5-й и 6-й
соответственно, и тд, до конца массива. После чего происходит сортировка дерева по принципу "любой дочерний элемент дерева младше родительского".
Когда сортировка завершена, и куча сформирована, происходит обмен местами между корнем дерева (самый большой элемент) с последним элементом дерева, 
после чего сортировка по принципу "любой дочерний элемент младше родительского" снова повторяется. В корень снова попадет самый большой элемент и цикл
повторяется пока весь массив не будет отсортирован.
Сама куча, как структура данных имеет разные приложения, помимо пирамидальной сортировки, например очередь в приоритетом или алгоритмы на графах.
Куча бывает двух видов: max heap и min heap.
Общая формула для max heap: arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2]
Сложность статична, в любом случае это О(n*log n), расход памяти статичен и не зависит от размера массива , тоесть О(1).*/
#include <stdio.h>
#include <stdbool.h>
void shifDown (int * numbers, int root, int bottom);
void heapSort (int * numbers, int array_size);
int main (void)
{  
    int arr [] = {5, 6, 23, 43, 2, 1, 66, 4, 34, 0, -2, -666, 666, 102, 233, 421, 2, 66};
    int size = sizeof(arr)/sizeof(int);
    int temp;
    puts("Array before pyramis sort:");
    for (int i = 0; i < size; i++)
        printf("%d)%d\n", i + 1, arr[i]);
    heapSort(arr, size);
    puts("Array after pyramis sort:");
    for (int i = 0; i < size; i++)
        printf("%d)[%d]\n", i + 1, arr[i]);
} 


void shifDown (int * numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    bool done = false; // индикатор сформировавшейся кучи
    while ((root * 2 <= bottom) && (!done)) // пока не дошли до последнего потомка 
    {
        if (root * 2 == bottom) // если мы в последнем ряду
        {
            maxChild = root * 2;
        } else if (numbers[root * 2] > numbers [root * 2 + 1]) // запоминаем больший потомок из двух
        {
            maxChild = root * 2;
        } else maxChild = root * 2 + 1;
        if (numbers[root] < numbers[maxChild]) // если элемент вершины меньше максимального потомка, меняем их местами
        {
            int tmp;
            tmp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = tmp;
            root = maxChild;
        }
        else done = true; // иначе пирамида сформирована
    }

}
void heapSort (int * numbers, int array_size)
{
    //формируем нижний ряд пирамиды
    for (int i = array_size / 2; i >= 0; i--) 
        shifDown(numbers, i, array_size - 1); 
    // просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int tmp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = tmp;
        shifDown(numbers, 0, i - 1);
    }
}