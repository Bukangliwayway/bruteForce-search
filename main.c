#include <stdio.h>
#include <stdlib.h>
const int size = 5;
int factorial(int num); // Self Explanatory
void arrangeElements(int array[][size], int currentPoint, int point); // Swaps every elements within the array
void copyContents(int array[][size], int basePoint, int currentPoint);
// Copies the elements within the array from point to point

int main(){
    int array[factorial(size)][size];
    int basePoint = 0, currentPoint = 0;
    for(int i = 0; i < size; i++) array[0][i] = i+1; // Setting the First elements

    for(int point = size-1; point > 0; point--){
        basePoint = 0;
        currentPoint = basePoint + factorial(point);
        // Resets the variables for the next point
        do{
            for(int i = size-1; i > point; i--){
            //Loops to check whether the currentPoint is divisible by the higher factorial
                if(currentPoint%factorial(i) == 0){
                    basePoint = currentPoint;
                    currentPoint = basePoint + factorial(point);
                    // Moves the currentPoint to the next factorial
                }
            }
            copyContents(array, basePoint, currentPoint);
            arrangeElements(array, currentPoint, point);
            basePoint = currentPoint; // Updates the basePoint
            currentPoint = basePoint + factorial(point);// Moves the currentPoint to the next factorial
        }while(currentPoint < factorial(size));
    }

    for(int i = 0; i < factorial(size); i++){
        printf("%3d. ", i+1);
        for(int j = 0; j < size; j++){
            printf("\t %3d", array[i][j]);
        }
        printf("\n");
    }
    //prints Datas
}

void copyContents(int array[][size], int basePoint, int currentPoint){
    for(int i = 0 ; i < size; i++)array[currentPoint][i] = array[basePoint][i];
}
void arrangeElements(int array[][size], int currentPoint, int point){
    for(int i = size-1; i > (size-point)-1; i--){
        array[currentPoint][size-point-1] += array[currentPoint][i];
        array[currentPoint][i] = array[currentPoint][size-point-1] - array[currentPoint][i];
        array[currentPoint][size-point-1] -= array[currentPoint][i];
    }
}

int factorial(int num){
    if(num!=1) return num*factorial(num-1);
    return 1;
}
