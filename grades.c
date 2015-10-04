/* Emily Koh 
FCI
Lab 4 - part1 */

#include <stdio.h>
#include <math.h>

int main () {

  float value, sum, count;
  float average, standardDeviation;


  //declare variables
  sum=0;
  count=0;
  
  //create array
  int numbers[50];
  int temp, i;

  //compute average
  for (i = 0; i < 50; i++){
    scanf("%d", &temp);
    if (temp >= 0){
      numbers[i] = temp;
      sum += numbers[i];
      count += 1;
    } else {
      break;
    }
  }
  
  average = sum/count;
  printf("The average of these numbers is %0.2lf\n", average);

  //compute standard deviation
  sum = 0;
  value = 0;
  for (i = 0; i < count; i++) {
    sum += (pow((numbers[i]-average), 2.0)/count);
  }
  
  standardDeviation = sqrt(sum);
  printf("The standard deviation of these numbers is %0.2lf\n", standardDeviation);
 

  return 0;
}


