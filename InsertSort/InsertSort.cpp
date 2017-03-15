#include <stdio.h>
#include <Windows.h>

#define LENGTH 10

int InsertSort(int[]);
int Move(int[], int, int);
void PrintArray(int[], int, int);

void main()
{
	int Array[LENGTH] = { 3, 1, 22, 17, 19, 4, 11, 8, 21, 16 };

	PrintArray(Array, -1, LENGTH);
	Sleep(2000);

	InsertSort(Array);

	PrintArray(Array, -1, LENGTH);
}

int InsertSort(int arr[]){
	int i;
		
	for (i = 1; i < LENGTH; i++){
		PrintArray(arr, i, i);
		Move(arr, i, i + 1);
		PrintArray(arr, i, i);
	}

	return 0;
}

int Move(int arr[], int Position, int Size)
{
	int temp = arr[Position];
	int tempPosition = Position;
	int i, j;

	for (i = Size - 1; i >= 0; i--){
		if (temp < arr[i]){
			tempPosition = i;
		}
	}

	for (j = Position - 1; j >= tempPosition; j--){
		arr[j + 1] = arr[j];
	}
	arr[tempPosition] = temp;

	return 0;
}

void PrintArray(int arr[], int Position, int Size)
{
	int i;

	Sleep(2000);
	system("cls");

	for (i = 0; i < LENGTH; i++){
		if (i == Position)	printf("|%02d| ", arr[i]);
		else printf("%02d    ", arr[i]);
	}

	printf("\n");
	for (i = 0; i <= Size; i++){
		printf("^^^^^");
	}
	printf("\n");
}