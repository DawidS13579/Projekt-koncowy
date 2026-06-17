#include <iostream>
#define  SIZE 10

void Array_print(int *numbers,int size) {
    for (int i = 0; i < size; i++) {
        printf("number[%d]=%d\n",i,*(numbers+i));
    }

}
int max_array(int *numbers,int size) {
    int max = *numbers;
    for (int i = 0; i < size; i++) {
        if  (max < *(numbers+i )) {
            max = *(numbers+i );
        }
    }return max;
}
int min_array(int *numbers,int size) {
    int min = *numbers;
    for (int i = 0; i < size; i++) {
        if (min > *(numbers+i)) {
            min = *(numbers+i);
        }
    }return min;
}
int sum(int *numbers,int size) {
    int sum=0;
    for (int i = 0; i < size; i++) {
        sum += *(numbers+i);
    }return sum;
}
float average(int *numbers,int size) {

    float avg = sum(numbers,size)/size;
    return avg;

}



void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void copy_array(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];

    }
}

double median(int *numbers, int size) {
    int temp_array[size];
    copy_array(numbers,temp_array,size);
    sort_array(temp_array,size);
    double median;
    if (size % 2 != 0) {
        median = (double)temp_array[size / 2];
        printf("median=%.2f\n", median);
    } else {

        median = (temp_array[size / 2 - 1] + temp_array[size / 2]) / 2.0;
        printf("median=%.2f\n", median);
    }
    return median;
}



int main() {
    printf("Arrays\n");
    int numbers[SIZE] = {1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    Array_print(numbers,SIZE);
    printf("max=%d\n", max_array(numbers,SIZE));
    printf("min=%d\n", min_array(numbers,SIZE));
    printf("sum=%d\n", sum(numbers,SIZE));
    printf("average=%.2f\n", average(numbers,SIZE));
    printf("median=%.2f\n", median(numbers,SIZE));
    return 0;
}
