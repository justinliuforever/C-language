#include<stdio.h>

#include<stdlib.h>

#define Size 10000

typedef struct List{

    int value;
    struct List *next;

}List;

List* bucket[Size];

//creat new node in bucket[10000]
List* createNode(int value){

    List *node = (List*)calloc(1,sizeof(List));

    node->value = value;

    node->next = NULL;

    return node;

}

int insert(int number){

    int hashValue = number % Size;
    if(hashValue < 0){
       
        hashValue = Size-hashValue;
    }

    int collision=0;
    int duplicateExist=0;

    //check if it's new node in bucket
    if(bucket[hashValue]==NULL){
        bucket[hashValue] = createNode(number);
        collision = 0;
    }
    //collision
    else{
        List *pre=NULL;
        List *cur=bucket[hashValue];
        collision = 1;
        
        //enter the bucket[] collision location
        while(cur!=NULL){
            //loop to the last one in this collsion place, also check whether it's duplicate or not
            if(cur->value == number){
                duplicateExist = 1;
                break;
            }
            pre= cur;
            cur= cur->next;
        }

        if(duplicateExist == 0){
            pre->next = createNode(number);
        }
    }

    return collision;//if there is a collision, count1++;
                    //if there is no collision, count1 =count1+0;

}

int search(int number){

    int hashValue = number % Size;
    
    //when the hashvalue become negetive, the index of buket cannot be negetive, so we have this step;
    if(hashValue < 0){
        
        hashValue = Size - hashValue;
    }

    List *cur= bucket[hashValue];
    int valueFound=0;
    
    while(cur!=NULL){

        if(cur->value==number){
            valueFound = 1;
        }
        cur=cur->next;
    }
    return valueFound;
}


int main(int argc,char *argv[]){

    if(argc != 2){
        printf("error\n");
    }

    else{

        FILE * pf;

        pf = fopen (argv[1], "r");

        if(pf == NULL){

            printf("error\n");

            exit(2);

        }

        else{

            int i;
           
            char choice;// i or s
            
            int number;

            int count1=0, count2=0;

            //initailize bucket[10000]
            for(i=0;i<Size;i++){
                bucket[i]=NULL;
            }

            int x=fscanf(pf, "%c\t%d\n", &choice, &number);

            while(x==2){
                if(choice=='i' || choice == 'I'){
                    //count the collison when it insert
                   count1 += insert(number);
                    
                }
                else if(choice=='s' || choice=='S'){
                    // count the search
                    count2 += search(number);
                }

                x=fscanf(pf, "%c\t%d\n", &choice, &number) ;//next line

            }

            printf("%d\n%d\n",count1,count2);
            fclose(pf);

        }
    }

    return 0;

}
