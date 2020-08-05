//https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/


#include <stdio.h> 
#include <stdlib.h> 

#define INTERVAL 10 

  
int main() {
    int interval = 0, i = 0; 
    float  rand_x = 0.0 , rand_y = 0.0, origin_dist = 0.0, pi = 0.0; 
    int circle_points = 0, square_points = 0; 
  
    // Initializing rand() 
    srand(time(NULL)); 
  
    // Total Random numbers generated = possible x values * possible y values 
    for (i = 0; i < (INTERVAL * INTERVAL); i++) { 
  
        // Randomly generated x and y values 
        rand_x = (float) (rand() % (INTERVAL + 1)) / INTERVAL; 
        rand_y = (float) (rand() % (INTERVAL + 1)) / INTERVAL; 
  
        // Distance between (x, y) from the origin 
        origin_dist = rand_x * rand_x + rand_y * rand_y; 
  
        // Checking if (x, y) lies inside the circle with R=1 
        if (origin_dist <= 1){
            circle_points++;
        }
  
        // Total number of points generated 
        square_points++; 
  
        // estimated pi after this iteration 
        pi = (float)(4 * circle_points) / square_points; 
  
        printf("rand_x = %f, rand_y = %f, circle_points = %d, square_points = %d, pi = %f \n",
                 rand_x, rand_y, circle_points, square_points, pi);
  
    } 
  

    printf("Final Estimation of Pi = %f", pi); 
  
    return 0; 
} 