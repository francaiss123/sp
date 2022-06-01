#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

    const int SIZE = 3;
    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = rand() % 10;
    }

    for (int i = 0; i< SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    int sum;    
    int *mat = &matrix[SIZE-1][SIZE-1];// Ссылка на последний элемент матрицы

    asm(
            "mov %[mat], %%rsi;"// В rsi кидаем ссылку на послед. эл.
            "movl %[SIZE], %%r8d;"// r8 - аналог i (только не от 0 до SIZE-1, а наоборот)
            "dec %%r8d;"
            "xorl %%edx, %%edx;"// Будущая сумма
            

        "i:" //цикл i
            // Инициализируем j
            "movl %[SIZE], %%r9d;"
            "dec %%r9d;"
        
        "j:" //цикл j
            // Проверка на глав. диагональ
            "cmpl %%r9d, %%r8d;"
            "je sum;"

            // Если не подходит, то просто перепрыгиваем суммирование
            "jmp end_sum;"

        // Суммирование
        "sum:"
            // Вытаскиваем элемент с матрицы
            "movl (%%rsi), %%ebx;"
            // Суммируем с суммой
            "addl %%ebx, %%edx;"
            
        // Проверка на конец строки
        "end_sum:"
            // Уменьшаем j
            "dec %%r9d;"
            // Перемещаем указатель на элемент как бы назад
            "sub $4, %%rsi;"
            // Если j не ушел за массив
            "cmpl $-1, %%r9d;"
            // Повторяем цикл j
            "jne j;"

            // Аналогичен выше, только с i
            "dec %%r8d;"
            "cmpl $-1, %%r8d;"
            "jne i;"

            // Записываем сумму из вставки в переменную из проги
            "movl %%edx, %[sum];"
            :
            :[mat]"m"(mat), [SIZE]"m"(SIZE), [sum]"m"(sum) // Используемые переменные из проги
            :
       );

    // Выводим сумму
    cout << "  Sum = " << sum << endl;

    return 0;
}
