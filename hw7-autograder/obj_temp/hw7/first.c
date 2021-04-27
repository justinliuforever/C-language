#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct ComNode *Hash;    // initialize the Hash Map
int Spc;
int PlaceH;

struct ComNode {
    char Variable[1000];
    short *Array;
};

int isValid(char input[5000]) {
    if (input[0] == '1' || input[0] == '0')
        return 1;
    
    int t;
    for (t = 0; t < Spc; t++) {
        if (strcmp(input, Hash[t].Variable) == 0) return 1;
    }
        return 0;
}


void Wcompute(char Input1[1000], char Input2[1000], char temp[1000], int MAX, char OP) {
    int one, two, index, i, dupl = 0;
    for (i = 0; i < Spc; i++) {
        if (strcmp(Hash[i].Variable, Input1) == 0) {
            one = i;
        }
       if (strcmp(Hash[i].Variable, temp) == 0) {
            dupl = 1;
            index = i;
        }
        if (OP != 'T') {
            if (strcmp(Hash[i].Variable, Input2) == 0) {
                two = i;
            }
        }
    }
    
    int num, mark = 0;
    if (OP != 'T') {
        if (Input1[0] == '0' || Input1[0] == '1' || Input2[0] == '0' || Input2[0] == '1') {
            if (Input1[0] == '0') {
                mark = 1;
                num = 0;
            } else if (Input1[0] == '1') {
                mark = 1;
                num = 1;
            } else if (Input2[0] == '0') {
                mark = 2;
                num = 0;
            } else if (Input2[0] == '1') {
                mark = 2;
                num = 1;
            }
        }
    } else if (OP == 'T') {
        if (Input1[0] == '1' || Input1[0] == '0') {
            if (Input1[0] == '1') {
                mark = 1;
                num = 1;
            } else if (Input1[0] == '0') {
                mark = 1;
                num = 0;
            }
        }
    }
    
    if (dupl == 0) {
        Spc++;
        Hash = realloc(Hash, sizeof(struct ComNode) * Spc);
        strcpy(Hash[Spc-1].Variable, temp);
        Hash[Spc-1].Array = malloc(sizeof(short) * MAX);
        
        for (i = 0; i < MAX; i++) {
            if (OP == 'A') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = Hash[one].Array[i] & Hash[two].Array[i];
                if (mark == 1)
                    Hash[Spc-1].Array[i] = num & Hash[two].Array[i];
                if (mark == 2)
                    Hash[Spc-1].Array[i] = Hash[one].Array[i] & num;
                //printf("here1")
            } else if (OP == 'O') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = Hash[one].Array[i] | Hash[two].Array[i];
                if (mark == 1)
                    Hash[Spc-1].Array[i] = num | Hash[two].Array[i];
                if (mark == 2)
                    Hash[Spc-1].Array[i] = Hash[one].Array[i] | num;
                //printf("here2")
            } else if (OP == 'X') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = Hash[one].Array[i] ^ Hash[two].Array[i];
                if (mark == 1)
                    Hash[Spc-1].Array[i] = num ^ Hash[two].Array[i];
                if (mark == 2) Hash[Spc-1].Array[i] = Hash[one].Array[i] ^ num;
                //printf("here3")
            } else if (OP == 'D') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = !(Hash[one].Array[i] & Hash[two].Array[i]);
                if (mark == 1)
                    Hash[Spc-1].Array[i] = !(num & Hash[two].Array[i]);
                if (mark == 2)
                    Hash[Spc-1].Array[i] = !(Hash[one].Array[i] & num);
                //printf("here4")
            } else if (OP == 'R') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = !(Hash[one].Array[i] | Hash[two].Array[i]);
                if (mark == 1)
                    Hash[Spc-1].Array[i] = !(num | Hash[two].Array[i]);
                if (mark == 2)
                    Hash[Spc-1].Array[i] = !(Hash[one].Array[i] | num);
                //printf("here5")
            } else if (OP == 'T') {
                if (mark == 0)
                    Hash[Spc-1].Array[i] = !Hash[one].Array[i];
                if (mark == 1)
                    Hash[Spc-1].Array[i] = !num;
                //printf("here6")
            }
        }
    } else {
        for (i = 0; i < MAX; i++) {
            if (OP == 'A') {
                if (mark == 0)
                    Hash[index].Array[i] = Hash[one].Array[i] & Hash[two].Array[i];
                if (mark == 1)
                    Hash[index].Array[i] = num & Hash[two].Array[i];
                if (mark == 2)
                    Hash[index].Array[i] = Hash[one].Array[i] & num;
                //printf("here7")
            }
            else if (OP == 'O') {
                if (mark == 0)
                    Hash[index].Array[i] = Hash[one].Array[i] | Hash[two].Array[i];
                if (mark == 1)
                    Hash[index].Array[i] = num | Hash[two].Array[i];
                if (mark == 2)
                    Hash[index].Array[i] = Hash[one].Array[i] | num;
                //printf("here8")
            }
            else if (OP == 'T') {
                if (mark == 0)
                    Hash[index].Array[i] = !Hash[one].Array[i];
                if (mark == 1)
                    Hash[index].Array[i] = !num;
                //printf("here9")
            }
            else if (OP == 'X') {
                if (mark == 0)
                    Hash[index].Array[i] = Hash[one].Array[i] ^ Hash[two].Array[i];
                if (mark == 1)
                    Hash[index].Array[i] = num ^ Hash[two].Array[i];
                if (mark == 2)
                    Hash[index].Array[i] = Hash[one].Array[i] ^ num;
                //printf(" here10 ")
            }
            else if (OP == 'D') {
                if (mark == 0)
                    Hash[index].Array[i] = !(Hash[one].Array[i] & Hash[two].Array[i]);
                if (mark == 1)
                    Hash[index].Array[i] = !(num & Hash[two].Array[i]);
                if (mark == 2)
                    Hash[index].Array[i] = !(Hash[one].Array[i] & num);
                //printf(" here11 ")
            }
            else if (OP == 'R') {
                if (mark == 0)
                    Hash[index].Array[i] = !(Hash[one].Array[i] | Hash[two].Array[i]);
                if (mark == 1)
                    Hash[index].Array[i] = !(num | Hash[two].Array[i]);
                if (mark == 2)
                    Hash[index].Array[i] = !(Hash[one].Array[i] | num);
                //printf(" here12 ")
            }
            
        }
    }
}

void copy(int p, int i){
    int t;
    for (t = p; t>=0; t--){
        
        Hash[t].Array[i] =  Hash[t].Array[i-1];
        //printf("%c", 'b');
        
    }
}

void creatTry (int numOfInputs, int col){
    int MAX = pow(2, numOfInputs), i, p;
    //int i,p;
    for (i = 0; i<MAX; i++){
        for (p = col; p>=0; p--){
        Hash[p].Array[i] = 0;
        }
    }
   // printf("%d", col);
    Hash[col].Array[1] = 1;
    for (i = 2; i<MAX; i++){
        copy(col,i);
        //for (p = col; p>=1; p--){
            if  (Hash[col].Array[i] == 0){
                Hash[col].Array[i] = 1;
                //copy(col,i);
                //printf("%d \n",i);
               // printf("%c", 'a');
                //break;
            }else if ((Hash[col].Array[i] == 1) && (Hash[col-1].Array[i] == 0)){
                Hash[col].Array[i] = 0;
                Hash[col-1].Array[i] = 1;
                //copy(col,i);
               // printf("%c", 'c');
                //break;
            }else if ((Hash[col].Array[i] == 1) && (Hash[col-1].Array[i] == 1)){
                int t = col;
                
                while ((Hash[t].Array[i]) == 1) {
                    Hash[t].Array[i] =0;
                    t--;
                }
                
               // for (int t = col;Hash[t-1].Array[i]) == 0 )
                Hash[t].Array[i] = 1;
               // copy(col,i);
              // printf("%c", 'd');
               // break;
            }
       // }
    }
    
}

int main(int argc, char** argv) {

    if (argc != 2) {                //check valid
        printf("error");
        return -1;
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error");
        return -1;
    }

    int MAX, i, j, numOfInputs, numOfOutputs;
    fscanf(fp, "INPUTVAR %d ", &numOfInputs);
    if (numOfInputs == 0) {
        printf("error");
        return -1;
    }
    
    MAX = pow(2, numOfInputs);
    Hash = malloc(sizeof(struct ComNode) * numOfInputs);
    
    for (i = 0; i < numOfInputs; i++) {
        (i == numOfInputs - 1) ? fscanf(fp, "%s\n", Hash[i].Variable) :  fscanf(fp, "%s ", Hash[i].Variable);
        Hash[i].Array = malloc(sizeof(short) * MAX);
        for (j = 0; j < MAX; j++)
            Hash[i].Array[j] = 0;
    }
    

    fscanf(fp, "OUTPUTVAR %d ", &numOfOutputs);
    if (numOfOutputs == 0) {
        printf("error");
        return 1;
    }
    

    PlaceH = numOfOutputs + numOfInputs;

    Hash = realloc(Hash, sizeof(struct ComNode) * (PlaceH));
    for (i = numOfInputs; i < (PlaceH); i++) {
        (i == (PlaceH) - 1) ? fscanf(fp, "%s\n", Hash[i].Variable) :  fscanf(fp, "%s ", Hash[i].Variable);
        Hash[i].Array = malloc(sizeof(short) * MAX);
    }
    
   
    creatTry(numOfInputs, numOfInputs-1);
    
   // printf("\n");
   // printf("%d  \n", numOfInputs);
    
    int counter = 0;
    char * LC = malloc(sizeof(char) * 100000);
    while (fgets(LC,100000,fp)) {
        counter++;
    }
    
    Spc = PlaceH;                                                           //Spc track the number of actural varible in temp
    short *validLine = malloc(sizeof(short) * counter);
    int Quit = 0;
    for (i = 0; i < counter; i++)
        validLine[i] = 0;
    do {
        fclose(fp);
        fp = fopen(argv[1], "r");
        fgets(LC,100000,fp);
        fgets(LC,100000,fp);
        j = 0;
        while (!feof(fp)) {
            char tmp[1000];
            char temp[1000];
            char Input1[1000];
            char Input2[1000];
            
            
            if (fscanf(fp, "%s ", tmp) != EOF) {
                if (strcmp(tmp, "AND") == 0) {        // And case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s %s\n", Input1, Input2, temp);
                        if (isValid(Input1) && isValid(Input2)) {
                            Wcompute(Input1, Input2, temp, MAX, 'A');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                } else if (strcmp(tmp, "OR") == 0) {    // Or case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s %s\n", Input1, Input2, temp);
                        if (isValid(Input1) && isValid(Input2)) {
                            Wcompute(Input1, Input2, temp, MAX, 'O');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                } else if (strcmp(tmp, "NOT") == 0) {    // Not case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s\n", Input1, temp);
                        if (isValid(Input1)) {
                            Wcompute(Input1, NULL, temp, MAX, 'T');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                } else if (strcmp(tmp, "XOR") == 0) {    // Xor case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s %s\n", Input1, Input2, temp);
                        if (isValid(Input1) && isValid(Input2)) {
                            Wcompute(Input1, Input2, temp, MAX, 'X');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                } else if (strcmp(tmp, "NAND") == 0) {    // Nand case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s %s\n", Input1, Input2, temp);
                        if (isValid(Input1) && isValid(Input2)) {
                            Wcompute(Input1, Input2, temp, MAX, 'D');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                } else if (strcmp(tmp, "NOR") == 0) {    // Nor case
                    if (validLine[j] == 0) {
                        fscanf(fp, "%s %s %s\n", Input1, Input2, temp);
                        if (isValid(Input1) && isValid(Input2)) {
                            Wcompute(Input1, Input2, temp, MAX, 'R');
                            validLine[j] = 1;
                        }
                    } else fgets(LC, 100000, fp);
                }else {
                    printf("error");
                    return -1;
                }
            } else break;
            j++;
        }
        for (i = 0; i < counter; i++) {
            if (validLine[i] == 1) {
                Quit = 1;
            }
            break;
        }
    } while (Quit != 1);
    
    for (int i = 0; i < MAX; i++) {                                     // printout
        for (int j = 0; j < PlaceH; j++) {
            printf((j == PlaceH - 1) ? "%d\n" : "%d ", Hash[j].Array[i]);
        }
    }
    
    free(LC);
    free(validLine);
    fclose(fp);
    return 0;
}
