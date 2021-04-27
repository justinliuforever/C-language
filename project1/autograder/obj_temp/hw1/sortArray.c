#include <stdio.h>

int main(int argc, char *argv[])
{

FILE *fp;
  
// Open file and check whether it can open or not
if( (fp = fopen(argv[1], "r") ) == NULL )
{
//printf("Error__--__\nCannot open file: %s\n", argv[1]);
printf("error\n");
return -1;
}
  

int i;
int j;
int temp;
int size;
  
// look how many number
fscanf(fp, "%d", &size);
int numberArray[size];
  
// put the rest number into array
for (i = 0; i < size; i++)
{
fscanf(fp, "%d", &numberArray[i]);
    
}

 
//even number first, odd number after
  

int index;
int change = 0;
for(i=0;i<size;i++)
{
//even?
if(numberArray[i]%2 == 0)
{
//index = i;
change ++;
continue;
}
 //change location, put even first odd later
for(j=i+1;j<size;j++)
{
if(numberArray[j]%2 == 0)
{
temp = numberArray[i];
numberArray[i] = numberArray[j];
numberArray[j] = temp;
index = i;
break;}
}
}
//new! if the orginal array already in order, it will use this function
if (change == 0){
    for (i=0;i<size;i++){
        if(numberArray[i]%2 == 0)
            index=i;
    }
    }
  
// Sort
for(i=0;i<size;i++)
{
if(i<=index)
{
// Sort the even numbers
for(j=i+1;j<=index;j++)
{
if(numberArray[i] > numberArray[j])//ascending even
{
temp = numberArray[i];
numberArray[i] = numberArray[j];
numberArray[j] = temp;
}
}
}
else
{
// Sort the even numbers in descending order
for(j=i+1;j<size;j++)
{
if(numberArray[i] < numberArray[j]) //descending odd
{
temp = numberArray[i];
numberArray[i] = numberArray[j];
numberArray[j] = temp;
}
}
}
}
  
// Displaying the array after separating even and odd numbers
//printf("\nArray after Sorting:\n");
for(i=0;i<size;i++)
printf("%d\t",numberArray[i]);
fclose(fp);
return 0;
 
}


