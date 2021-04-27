#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
  
char read[10000];

for (int i=1; i<argc; i++){
    
memset(read,'\0',10000);

strcpy(read, argv[i]);

    
for(int i=0; read[i]!='\0'; i++){

if(read[i]=='A'||read[i]=='a'||read[i]=='E'||read[i]=='e'||
read[i]=='I'||read[i]=='i'||read[i]=='O'||read[i]=='o'||
read[i]=='U'||read[i]=='u'){
    
    printf("%c",read[i]);
    
        }
    }
 
}
return 0;
}

