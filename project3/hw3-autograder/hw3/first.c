#include <stdio.h>

int main(int argc, char *argv[])
{
    int number;
    int n;
    int v;
    int temp;
    char store[1001];
    char way[1000];
    
   FILE *f = fopen(argv[1], "r");
  
   fgets(store, 1000, f); //put into the storeArrau,
   sscanf(store, "%d", &number);   //reading the number
    
   if(f == NULL){
        printf("error\n");
        return 0;
    }
   
   while( fgets(store, 1000, f) )
    {
       sscanf(store, "%s %d %d", way, &n, &v); //reading the commands
       char word = way[0];
        {
            if (word==('g')){
                       temp = 1;
                       temp = temp<<n;   //change to the locate the place
                       printf("%d\n",(number&temp)&&1);
                
         }else if (word==('s')){
                       temp = 1;
                       temp = temp<<n;   //change to the set loctaion
                       if(v)
                       {
                           number = number | temp;
                       }
                       else
                       {
                           temp = ~temp;
                           number = number & temp;
                       }
                       printf("%d\n",number);
                       
            }else  if (word==('c')){
                       temp = 1;
                       temp = temp<<n;   //change to the complement location
                       number = number ^ temp;//c=0, number=1; c=1, number=0;
                       printf("%d\n",number);
                      
            }else{
                       printf("error\n");
           }
       }
   }
   return 0;
}
