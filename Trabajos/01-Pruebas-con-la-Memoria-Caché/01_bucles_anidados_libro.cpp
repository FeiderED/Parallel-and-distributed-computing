#include <iostream>
#include <chrono>
#include <time.h>


using namespace std;

int main (){
    FILE *fp;
    int size [10] = {50, 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600};

    for (int z = 0; z < 10; z++){
        int actual_size = size[z];

        int  **matrix = new int*[actual_size];
        double *x = new double[actual_size];
        double *y = new double[actual_size];

        for (int i = 0; i < actual_size; i++){
            matrix[i] = new int[actual_size];
        }

        
        auto start = chrono::high_resolution_clock::now();        
        for (int i = 0; i < actual_size; i++){
            for (int j = 0; j < actual_size; j++){
                y[i] += matrix[i][j] * x[j];
            }
        }
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Bucle 1" << " Tamano: " << actual_size << " Tiempo: " << elapsed.count() << " \t";

        auto start2 = chrono::high_resolution_clock::now();
        for (int j = 0; j < actual_size; j++){
            for (int i = 0; i < actual_size; i++){
                y[i] += matrix[i][j] * x[j];
            } 
        }
        auto finish2 = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed2 = finish2 - start2;
        cout << "Bucle 2" << " Tamano: " << actual_size << " Tiempo: " << elapsed2.count() << endl;


        fp = fopen("extra_files/bucles_anidados.txt", "a");
        fprintf(fp, "%d\t%f\t%f\n", actual_size, elapsed.count(), elapsed2.count());
                
    }

    return 0;
}