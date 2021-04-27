#include <stdio.h>
#include <stdlib.h>

void Test(unsigned short int n)
{

int bitNumber[16];
for(int i=0; i<16; i++)   //set all to zero
{
   bitNumber[i]=0;
}
            
int i = 0;
while (n>0) {  // change to binary and put into
bitNumber[i] = n % 2;
n = n / 2;
i++;
}
    /*for (int x=0; x<16; x++)
    printf("%i", bitNumber[x]);
    printf("\n");
    for (int x=15; x>=0; x--)
    printf("%i", bitNumber[x]);
    */
for(int v=0; v<16; v++)
{
   if(bitNumber[v]!=bitNumber[15-v])
   {
       printf("Not-Palindrome\n");
       return;
       }
   }
   printf("Is-Palindrome\n");
}

int main(int argc, char* argv[])
{
    unsigned short int numb = atoi(argv[1]);
    Test(numb);
   
    return 0;
}
