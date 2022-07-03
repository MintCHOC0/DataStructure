#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>

//srand((unsigned int)time(NULL) * 45)
using namespace std;

random_device rd;
mt19937 gen(rd());

int my_lot_arr[6] = { 0, };
int game_lot_arr[6] = { 0, };

int test_arr1[7] = { 3,1,2,5,6,4,7 };
int test_arr2[7] = { 1,5,8,6,3,2,7 };

void set_lot_arr(int* target_lot) {
	int* ptr = target_lot;
	for (int i = 0; i < 6; i++) {
		target_lot[i] = (rand() % 45) + 1;
		for (int j = 0; j < i; j++) {
			if (target_lot[j] == target_lot[i]) {
				i--;
				break;
			}
		}
	}
}
void set_rad_arr(int* target_lot, int arr_length, int start, int end) {
	int* ptr = target_lot;
	int RANGE = end - start + 1;
	for (int i = 0; i < arr_length; i++) {
		target_lot[i] = (rand() % RANGE) + start;
		for (int j = 0; j < i; j++) {
			if (target_lot[j] == target_lot[i]) {
				i--;
				break;
			}
		}
	}
}
int getRadNum(int start, int end) {
	uniform_int_distribution<int> dis(start, end);
	return dis(gen);
}

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubbleSort(int* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		for (int j = i + 1; j < arr_length; j++) {
			if (*(arr + i) > *(arr + j)) { swap(arr + i, arr + j); }
		}
	}
}
void bubbleSort2(int arr[], int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		for (int j = i + 1; j < arr_length; j++) {
			if (arr[i] > arr[j]) { swap(arr[i], arr[j]); }
		}
	}
}

void selectionSort(int arr[], int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		int local_min_idx = i;
		for (int j = i; j < arr_length; j++) {
			if (arr[j] < arr[local_min_idx]) { local_min_idx = j; }
		}
		if (local_min_idx != i) {
			swap(&arr[i], &arr[local_min_idx]);
		}
	}
}

void cocktailSort(int arr[], int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if (i % 2 == 0) {
			int min_idx = i / 2;
			for (int j = i / 2; j < arr_length - i / 2; j++) { if (arr[min_idx] > arr[j]) { min_idx = j; } }
			if (min_idx != i / 2) { swap(&arr[i / 2], &arr[min_idx]); }
		}
		else {
			int max_idx = arr_length - (i + 1) / 2;
			for (int j = arr_length - (i + 1) / 2; j > (i + 1) / 2; j--) {
				if (arr[max_idx] < arr[j]) { max_idx = j; }
			}
			if (max_idx != arr_length - (i + 1) / 2) { swap(&arr[arr_length - (i + 1) / 2], &arr[max_idx]); }
		}
	}
}

void improvedBogoSort(int arr[], int arr_length) {
	for (int i = 0; i < (arr_length - 1); i++) {
		if (arr[i] > arr[i + 1]) {
			int n1 = getRadNum(i, arr_length - 1);
			int n2 = getRadNum(i, arr_length - 1);
			while (n1 == n2) {
				n2 = getRadNum(i, arr_length - 1);
			}
			swap(arr[n1],arr[n2]);
			i = 0;
		}
	}
}

bool checkEqualArray(int arr1[], int arr2[], int arr_length) {
	selectionSort(arr1,arr_length);
	selectionSort(arr2, arr_length);
	for (int i = 0; i < arr_length; i++) { if (arr1[i] != arr2[i]) { return false; } }
	return true;
}

bool checkEqArrByBrute(int arr1[], int arr2[], int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		for (int j = 0; j < arr_length; j++) {
			if (arr1[i] == arr2[j]) { break; }
			if (j == arr_length - 1) { return false; }
		}
	}
	return true;
}

int main() {
	int t1 = time(NULL);
	// Program Start
	sdkmfdsmfdmlkfmfmlkfmslfmlmslkfmlsk
	// Program End
	int t2 = time(NULL);
	cout << "Time : " << t2 - t1 << endl;
}