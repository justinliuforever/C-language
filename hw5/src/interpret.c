#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n, m;
int ax = 9996, bx = 9997, cx = 9998, dx = 9999;
int Vax = 0, Vbx = 0, Vcx = 0, Vdx = 0;
//int *ax1=&ax, *bx1=&bx, *cx1=&cx, *dx1=&dx;
char a[101][20];

int temValue = 0, temBe = 0, temAf = 0;
int WhichR = 0;

#define N 20
int ter[101][5]={0};

/*
int  move (int x, int y){
    return x;
}
*/

int add (int x, int y){
    y = x+y;
    return y;
}

int sub (int x, int y){
    y = y-x;
    return y;
}

int mul (int x, int y){
     y = (x)*(y);
    //printf("here %d\n", *x);
    return y;
}

int divi (int x, int y){
     y = (x)/(y);
    return y;
}


int  jmp (int x){
    return x-1;
}

int  je (int Orow, int Nrow, int x, int y){
    if (x == y){
        return Nrow-1;
    }
    return  Orow;
}

int  jne (int Orow, int Nrow, int x, int y){
    if (x != y){
        return Nrow-1;
    }
    return  Orow;
}

int  jg (int Orow, int Nrow, int x, int y){
    if (x > y){
        return Nrow-1;
    }
    return  Orow;
}

int jge (int Orow, int Nrow, int x, int y){
    if (x >= y){
        return Nrow-1;
    }
    return  Orow;
}

int jl (int Orow, int Nrow, int x, int y){
    if (x < y){
        return Nrow-1;
    }
    return  Orow;
}
int  jle (int Orow, int Nrow, int x, int y){
    if (x <= y){
        return Nrow-1;
    }
    return  Orow;
}

void  read (int *a){
    scanf("%d", a);
}

void print (int a){
    printf("%d", a);
}

int powr(int base, int expo){
    int num = base;
    if (expo == 0){
        return 1;
    }
    for (int x=expo; x>0 ; x--){
        num = num*base;
    }
    return num;
}

int distinguish(int r,int q,int p)//q is row ,p is the location of argument,r is the beginning of the argument.
{
    if(('0'<= a[q][r]) && (a[q][r]<='9'))
    {
       // printf("enter the 123\n");
       // printf("%d\n",a[q][r]);
        int tem=0;
        int temp[10];
        while (('0'<= a[q][r])&&(a[q][r]<='9')){
            //printf("enter the while\n");
            temp[tem]=a[q][r]-'0';
           //printf("temp shuzu is %d\n",temp[tem]);
            tem++;
            r++;
        }
        //printf("term is %d\n",tem);
        tem = tem-1;
         for(int temp1=0;temp1<=(tem);temp1++){
            // printf("tem is %d\n",tem);
            // printf("ter is %d\n",ter[q][p]);
         ter[q][p]=ter[q][p] + temp[temp1]*powr(10, tem-temp1);//tem-temp1
             
            
             //printf("p is %d\n", p);
             //printf("q is %d",q);
            // printf("ter is %d\n",ter[q][p]);
    }
        //printf("right  now tem is  %d\n",tem);
        return tem+2;
    }
    else if(('a'<= a[q][r])&&(a[q][r] <='d'))
    {
        //printf("enter the abc\n");
       switch (a[q][r])
       {
           case 'a':
              // ter[q][p]=&ax;
               ter[q][p]=ax;
               break;
           case 'b':
               //ter[q][p]=&bx;
               ter[q][p]=bx;
               break;
           case 'c':
               //ter[q][p]=&cx;
               ter[q][p]=cx;
               break;
           case 'd':
               //ter[q][p]=&dx;
               ter[q][p]=dx;
               break;
       }
        //return 3;
    } return 3;
}


void distri(char a[101][20]){
    for (int q=0; q <101; q++){
        switch (a[q][1]){
            case 'o':
                ter[q][0] = 1;
                distinguish((distinguish(4, q, 1)+ 4), q, 2);
                break;
            case 'd':
                ter[q][0] = 2;
                distinguish(distinguish(4, q, 1)+4, q, 2);
                break;
            case 'u':
                if(a[q][2] == 'b'){
                ter[q][0] = 3;
                distinguish(distinguish(4, q, 1)+4, q, 2);
                break;
                }
                else{
                    ter[q][0] = 4;
                    distinguish(distinguish(4, q, 1)+4, q, 2);
                   // int f = distinguish(4, q, 1)+4;
                   // printf("the f is : %d \n", f);
                   // distinguish(f, q, 2);
                    break;
                }
            case'i':
                ter[q][0] = 5;
                distinguish(distinguish(4, q, 1)+4, q, 2);
                break;
            case 'm':
                ter[q][0] = 6;
                distinguish(4, q, 1);
                break;
           
            case 'e':
                if (a[q][2] == 'a'){
                ter[q][0] = 13;
                   // printf("%d\n",ter[q][0]);
                distinguish(5, q, 1);
                   // printf("%d\n",ter[q][1]);
                    //printf("%d\n",q);
                    
                break;
                }else{
                    ter[q][0] = 7;
                   // distinguish(distinguish(distinguish(3, q, 1), q, 2), q, 3);
                    int f =distinguish(3, q, 1)+3;
                    f = f + distinguish(f, q, 2);
                    distinguish(f, q, 3);
                    break;
                }
            case 'n':
                ter[q][0] = 8;
                //distinguish(distinguish(distinguish(4, q, 1), q, 2), q, 3);
                int f =distinguish(4, q, 1) + 4;
                f = f + distinguish(f, q, 2);
                distinguish(f, q, 3);
                break;
            case 'g':
                if (a[q][2] == 'e'){
                    ter[q][0] = 10;
                    //distinguish(distinguish(distinguish(4, q, 1), q, 2), q, 3);
                    int f = 4 + distinguish(4, q, 1);
                    f = f + distinguish(f, q, 2);
                    distinguish(f, q, 3);
                    break;
                }else{
                    ter[q][0] = 9;
                    //distinguish(distinguish(distinguish(3, q, 1), q, 2), q, 3);
                    int f = 3 + distinguish(3, q, 1);
                    f = f + distinguish(f, q, 2);
                    distinguish(f, q, 3);
                    break;
                }
            case 'l':
                if (a[q][2] == 'e'){
                    ter[q][0] = 12;
                    //distinguish(distinguish(distinguish(4, q, 1), q, 2), q, 3);
                    int f = 4 + distinguish(4, q, 1);
                    f = f + distinguish(f, q, 2);
                    distinguish(f, q, 3);
                    break;
                }else{
                    ter[q][0] = 11;
                    //distinguish(distinguish(distinguish(3, q, 1), q, 2), q, 3);
                    int f = 3 + distinguish(3, q, 1);
                    f = f + distinguish(f, q, 2);
                    distinguish(f, q, 3);
                    break;
                case 'r':
                    ter[q][0] = 14;
                    distinguish(6, q, 1);
                    break;
        }
    }
    
}
}

int meet (int x){
    if (x == ax)
        return Vax;
    if (x == bx)
        return Vbx;
    if (x == cx)
        return Vcx;
    if (x == dx)
        return Vdx;
    return x;
}


int main(int argc, char* argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    
    if(fp == NULL){
        printf("error\n");
        exit(2);
    }
    
    //char *name[100][4];
  //  char *line[101];
    char tstr[20];

    
    //int value1 [100], value2 [100], value3 [100];
    //int  a, b, c;
    //, a[6], b[6], c[6];
    
    int i=0;
    
    
    while(fgets(a[i], N, fp) != NULL){
       //strin[i]= tstr;
        //printf("%s", a[i]);
        i++;
    }
   
   distri(a);
/*
    for(int x1 = 0; x1<101; x1++){
        for(int x2 = 0; x2<5; x2++)
            printf("%d ", ter[x1][x2]);
        printf("\n");
    }
    printf("****************************\n");
   */
    for(int x1 = 0; x1<101; x1++){
        int fct = ter[x1][0];
        
        switch (fct) {
            
            case 1:
                temBe = meet(ter[x1][1]);
                WhichR = ter[x1][2];
                temAf = meet(ter[x1][2]);
                temValue = temBe;
                if (WhichR == ax) {
                    Vax = temValue;
                } else if (WhichR == bx){
                    Vbx = temValue;
                }else if (WhichR == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
                break;
            case 2: //add
                temValue = 0;
                temBe = meet(ter[x1][1]);
                WhichR = ter[x1][2];
                temAf = meet(ter[x1][2]);
                temValue = add(temBe, temAf);
                if (WhichR == ax) {
                    Vax = temValue;
                } else if (WhichR == bx){
                    Vbx = temValue;
                }else if (WhichR == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
                break;
                
            case 3: //sub
                temValue = 0;
                temBe = meet(ter[x1][1]);
                WhichR = ter[x1][2];
                temAf = meet(ter[x1][2]);
                temValue = sub(temBe, temAf);
                if (WhichR == ax) {
                    Vax = temValue;
                } else if (WhichR == bx){
                    Vbx = temValue;
                }else if (WhichR == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
                break;
            
            case 4: //mul
                //printf("row0 ax is %d\n",ter[0][1]);
                temValue = 0;
                temBe = meet(ter[x1][1]);// begin to change value
                WhichR = ter[x1][2];
                temAf = meet(ter[x1][2]);
                //printf("row1 ax is %d\n",ter[x1][2]);
                temValue = mul(temBe, temAf);
                if (WhichR == ax) {
                    Vax = temValue;
                } else if (WhichR == bx){
                    Vbx = temValue;
                }else if (WhichR == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
            
                //printf("%d",ter[x1][2]);
                //printf("%d",Vax);
                break;
                
            case 5: //divi
                temValue = 0;
                temBe = meet(ter[x1][1]);
                WhichR = ter[x1][2];
                temAf = meet(ter[x1][2]);
                temValue = divi(temBe, temAf);
                if (WhichR == ax) {
                    Vax = temValue;
                } else if (WhichR == bx){
                    Vbx = temValue;
                }else if (WhichR == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
                break;
                
            case 6: //jmp
                x1 = jmp(meet(ter[x1][1]));
                        // printf("enter jump and x1 is %d\n", x1);
                break;
            case 7: //je
                x1 = je(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                break;
            case 8: //jne
                x1 = jne(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                break;
            case 9: //jg
                x1 = jg(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                break;
            case 10: //jge
                x1 = jge(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                break;
            case 11: //jl
                //temValue = 0;
                x1 = jl(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                //printf("%d",Vax);
                //printf("%d",x1);
                break;
            case 12: //jle
                x1 = jle(x1, ter[x1][1], meet(ter[x1][2]), meet(ter[x1][3]));
                //printf("Vax is %d\n",Vax);
                //printf("x1 is %d\n",x1);
                break;
            case 13:
                //printf("enter read/n");
                //read(&ter[x1][1]);
                temValue = 0;
                //scanf("%d", changeV(ter[x1][1]));
                scanf("%d", &temValue);
                if (ter[x1][1] == ax){
                    Vax = temValue;
                }else if (ter[x1][1] == bx){
                    Vbx = temValue;
                }else if (ter[x1][1] == cx){
                    Vcx = temValue;
                }else {
                    Vdx = temValue;
                }
               //printf("read number is %d\n",Vax );
                break;
            case 14:
                temValue = 0;
                temValue = meet(ter[x1][1]);
                print(temValue);
                break;
                
                
                
        }
       // printf("x1 finial is %d\n",x1);
        
        /*
        if (fct == 13) {
            read(&ter[x1][1]);
            printf("enter read/n");
        }
        */
    }
    
}
