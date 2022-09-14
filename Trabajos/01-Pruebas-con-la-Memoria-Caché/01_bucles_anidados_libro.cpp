#include <iostream>
#include <time.h>
#include <chrono>

int main (){
    int MAX = 1000;
    //std::cout << "Size of the array: ";
    //std::cin >> MAX;

    
    double A[MAX][MAX], x[MAX], y[MAX];
    int i, j;

    
    clock_t start, end;
    double cpu_time_used;
    
    
    /* Calculate the time of fist loop */
    //start = clock();
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            A[i][j] = i * j;
        }
    }
    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time of first loop: " << cpu_time_used << std::endl;


    /* Calculate the time of second loop */
    start = clock();
    for (j = 0; j < MAX; j++){
        for (i = 0; i < MAX; i++){
            A[i][j] = i * j;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time of second loop: " << cpu_time_used << std::endl;

    return 0;
}