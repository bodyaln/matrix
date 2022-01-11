/*
* 1.Матрицю 7х7 заповнити випадковими значеннями від -20 до 20. У матриці знайти рядки з максимальним і мінімальним елементом та поміняти їх місцями. Вивести на екран обидві.
2.	Для динамічної матриці 10×10 цілих чисел, відсортувати головну діагональ за зменшенням її елементів. Знайти максимальне число серед елементів що розташовані нижче побічної діагоналі.
3.	Для динамічної матриці 9×9 дійсних цілих чисел знайти максимальний елемент у кожному парному стовпчику, та мінімальний елемент у кожному непарному стовпчику.
4.	Для динамічної матриці 7×7 цілих чисел знайти суму елементів, що розташовані нижче побічної діагоналі, та відсортувати головну діагональ за зменшенням її елементів.
5.	Для динамічної матриці 9×9 дійсних цілих чисел знайти максимальний елемент у кожному стовпчику та відсортувати третю строку за збільшенням її елементів.

*/

#include <iostream>
#include <iomanip>
using namespace std;
int max_elem(int , int** );
int min_elem(int** , int );
void _swap(int** , int , int, int );
void show_array(int** , int );
void sortmaindiag(int** , int );
int maxdownsidediag(int** A, int );
void parmaxmincol(int**, int);
void sort3row(int** A, int size);
void maxminrow(int** A, int size);
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL)); // Инициализируем генератор случайных чисел. 
	int n = 0;
	cin >> n; // Считываем с клавиатуры n
	int** mass = new int* [n]; // Создаем массив указателей
	for (int i = 0; i < n; i++)
	{
		mass[i] = new int[n]; // Создаем элементы
	}
	// А дальше работа как с обычным массивом. 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mass[i][j] = rand() % 10;// 40 -20; // Каждый элемент случайному числу от 0 до 9
			cout << mass[i][j] << " "; // Вывести элементы на консольку
		}
		cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
	}
	cout << endl;

	//cout << maxdownsidediag(mass, n) << endl;
	//maxmincol(mass, n);
	//sortmaindiag(mass, n);
	//sort3row(mass, n);
	//show_array(mass, n);

	/*  1 ЗАДАНИЕ
	// У матриці знайти рядки з максимальним і мінімальним елементом та поміняти їх місцями. Вивести на екран обидві.*/

	int pos1 = max_elem(n, mass);
	int pos2 = min_elem(mass, n);
	cout << endl;
	cout << "pos1 = " << pos1+1 << "\t pos2 = " << pos2+1 << endl<<endl;
	if (pos1 == pos2)
		show_array(mass, n);

	else
	{
		_swap(mass, n, pos1, pos2);
		show_array(mass, n);
	}
	cout << "Рядок с максимальным елементом" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << mass[pos1][j]<<setw(4);
	}
	cout << "\nРядок с минимальным елементом" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << mass[pos2][j]<<setw(4);
	}
	//Конец 1 задания ну и делете отой добавить надо шо снизу
	
	

	//ОБЯЗАТЕЛЬНО ЧИСТИМ 
	for (int i = 0; i < n; i++) {

		delete[] mass[i];
	}

	delete[] mass;

	return 0;
}
//1 Задание
int max_elem(int size,int** A)
{
	int max = -20, pos;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (A[i][j] >= max)
			{
				max = A[i][j];
				pos = i;
			}
	cout << "Max element = " << max << endl;
	return pos;
}
//1 Задание
int min_elem(int** A, int size)
{
	int min = 20, pos;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (A[i][j] <= min)
			{
				min = A[i][j];
				pos = i;
			}
	cout << "Min element = " << min << endl;
	return pos;
}
//1 Задание
void _swap(int**A, int size, int pos1, int pos2)
{
	using namespace std;
	for (int j = 0; j < size; j++)
	{
		int k = A[pos1][j];
		A[pos1][j] = A[pos2][j];
		A[pos2][j] = k;
	}
}
//показать массив
void show_array(int** A, int size)
{
	using namespace std;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
//відсортувати головну діагональ за зменшенням її елементів (2 задание) (4 задание)
void sortmaindiag(int** A, int size) {
	int tmp;
	for (int i = 1; i < size; i++) {
		for (int i = 1; i < size; i++) {
			if (A[i - 1][i - 1] > A[i][i]) {
				tmp = A[i][i];
				A[i][i] = A[i - 1][i - 1];
				A[i - 1][i - 1] = tmp;
			}
		}
	}
}
// Нахождение max элемента ниже ПОБОЧНОЙ диагонали  (2 задание)
int maxdownsidediag(int** A, int size) {
	int max = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = size - i; j < size; ++j) {
			if (max < A[i][j])
				max = A[i][j];
		}
	}
	return max;
}
//знайти максимальний елемент у кожному парному стовпчику, та мінімальний елемент у кожному непарному стовпчику. (3 задание)
void parmaxmincol(int** A, int size) {
	for (int j = 0; j < size; ++j)
	{	
		if (j % 2 == 0) {

			int max = A[0][j];
			for (int i = 0; i < size; ++i)
				if (A[i][j] > max)
					max = A[i][j];
			cout << "Макс значение в " << j << " столбце = " << max << endl << endl;
		}

		else {
			int min = A[0][j];
			for (int i = 0; i < size; ++i)
				if (A[i][j] < min)
					min = A[i][j];
			cout << "Минимальное значение в " << j << " столбце = " << min << endl << endl;
		}
	}
}

//знайти суму елементів, що розташовані нижче побічної діагоналі (4 задание)
void sumsidediagsortmindiag(int** A, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - i; j < size; j++)
		{
			sum += A[i][j];
		}
	}
	cout << "Sum:" << sum << '\n';
}
//максимальный и мининмальный елемент в СТОЛБЦЕ
void maxmincol(int** A, int size) {
		for (int j = 0; j < size; ++j)
		{
			//максимальный елемент в столбце 
			int max = A[0][j];
			for (int i = 0; i < size; ++i)
				if (A[i][j] > max)
					max = A[i][j];
			cout << "Макс значение в " << j << " столбце = " << max << endl << endl;
			//мининмальный в стобце
			int min = A[0][j];
			for (int i = 0; i < size; ++i)
				if (A[i][j] < min)
					min = A[i][j];
			cout << "Минимальное значение в " << j << " столбце = " << min << endl << endl;
		}
}
//максимальный и мининмальный елемент в СТРОКЕ
void maxminrow(int** A, int size) {
	for (int i = 0; i < size; ++i)
	{
		//минимальный елемент в строке
		int min = A[i][0];
		for (int j = 1; j < size; ++j)
			if (A[i][j] < min)
				min = A[i][j];
		cout << "Мин значение в " << i + 1 << " строке = " << min << endl;

		//максимальный елемент в строке
		int max = A[i][0];
		for (int j = 1; j < size; ++j)
			if (A[i][j] > max)
				max = A[i][j];
		cout << "Мин значение в " << i + 1 << " строке = " << max << endl;
	}
}
//відсортувати третю строку за збільшенням її елементів. (5 задание)
void sort3row(int** A, int size) 
{
		int temp;
		bool sorted = false;
		int last = size;
		while (!sorted)
		{
			sorted = true;
			--last;
			for (int j = 0; j < last; ++j)
				if (A[2][j] > A[2][j + 1])
				{
					temp = A[2][j];
					A[2][j] = A[2][j + 1];
					A[2][j + 1] = temp;
					sorted = false;
				}
		}
}