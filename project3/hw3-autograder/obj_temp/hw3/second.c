#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    unsigned short int num = atoi(argv[1]);       //change given string to number
    unsigned short int pairs = 0;
    unsigned short int bitone;
    unsigned short int bit;
    unsigned short int prevBit = 0;
      
    while(num)
       {
           bit = num & 1;
           
        if (bit){                            //if bit=1
            bitone++;                        //increase # of1
            if( prevBit && bit ){           // if 1(two adjecent '1'), increse pairs
                pairs++;
                prevBit = 0;
               
            }else{
                prevBit = bit;
            }
            num >>= 1;
            
         }else{                              //if bit==0
             num >>= 1;
             prevBit = 0;
            
         }
       }
    
    if( bitone % 2 == 0){               // if # of bitone even
           printf("Even-Parity\t%d\n",pairs);
        
    }else{
           printf("Odd-Parity\t%d\n",pairs);
    }
    
    return 0;
}



