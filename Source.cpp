#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int* createArray(int&);
void processingArray(int*, int&);
void output(const char querty[50], int*, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	int sizeArray = 0;

	int* myNeedArray = createArray(sizeArray);
	output("Исходный массив: ", myNeedArray, sizeArray);
	processingArray(myNeedArray, sizeArray);
	output("Полученный массив: ", myNeedArray, sizeArray);

	delete[] myNeedArray;
	return 0;
}

int* createArray(int& sizeArray)
{
	cout << "Введите кол-во элементов массива: ";
	cin >> sizeArray;
	int* myArray = new int[sizeArray];
	int min, max;
	cout << "Введите минимальное значение диапазона: ";
	cin >> min;
	cout << "Введите максимальное значение диапазона: ";
	cin >> max;
	srand(time(NULL));
	for (int i = 0; i < sizeArray; i++)
	{
		myArray[i] = min + rand() % (max - min + 1);
	}
	return myArray;
}

void processingArray(int* myArray, int& sizeArray)
{
	int minElement = myArray[0];
	for (int i = 1; i < sizeArray; i++)
	{
		if (myArray[i] < minElement)
			minElement = myArray[i];
	}
	cout << "Минимальный элемент: " << minElement << endl;

	int k;
	cout << "Введите значение k для выполнения условия (желательно небольшое): ";
	cin >> k;
	int counter = 1;
	for (int i = 0; i < sizeArray; i++)
	{
		counter = 1;
		for (int j = i + 1; j < sizeArray; j++)
		{
			if (myArray[j] == myArray[i])
				counter++;
			else
				break;
		}
		if (counter > k)
		{
			myArray[i] = minElement;
			for (int z = i + 1; z < sizeArray - 1; z++)
			{
				myArray[z] = myArray[z + counter - 1];
			}
			sizeArray = sizeArray - counter + 1;
		}
	}
}

void output(const char querty[50], int* myArray, int sizeArray)
{
	cout << querty << setw(5);
	for (int i = 0; i < sizeArray; i++)
	{
		cout << setw(4) << myArray[i];
	}
	cout << endl;
}