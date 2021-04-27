/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int r2, int c1, int c2);
double** transposeMatrix(double** mat, int r, int c);
double** inverseMatrix(double **matA, int r, int c);

double** W(double** matrix,double ** Y,int row, int col);
double** CTone(double** sample, int i, int j,int row,int col);
double** CTzero(double** sample, int i, int j,int row,int col);
double** RCTzero(double** sample, int i, int j,int row,int col);
double** sub(double** test, double** w,int row,int col);

//******************************************************************************************


int main(int argc, char** argv){
   
    int attribN,caseN,testN;

    FILE* train;
    train=fopen(argv[1], "r");

    if(train==NULL){
        printf("error\n");
        return 0;
    }

    FILE* test;
    test=fopen(argv[2], "r");

    if(test==NULL){
        printf("error\n");
        return 0;
    }

    fscanf(train, "%d\n", &attribN);//square year
    fscanf(train, "%d\n", &caseN);//how many house
    fscanf(test, "%d\n", &testN);//how many test house

    
int i;
int j;
int p;
    double** trainmatrix = malloc(caseN*sizeof(double*));
        for(i=0;i<caseN;i++){
            trainmatrix[i] = malloc((attribN+1)*sizeof(double));
    }

    double** testmatrix = malloc(testN*sizeof(double*));
        for(i=0;i<testN;i++){
            testmatrix[i] = malloc((attribN)*sizeof(double));
    }

    double** Y = malloc(caseN*sizeof(double*));    //price
        for(i=0;i<caseN;i++){
            Y[i] = malloc(1*sizeof(double));
    }

    double** final = malloc((attribN+1)*sizeof(double*));
        for(p=0;p<=attribN;p++){
            final[p] = malloc(1*sizeof(double));
    }

//final predict price
    double** finalresult = malloc(testN*sizeof(double*));
        for(p=0;p<testN;p++){
            finalresult[p] = malloc(1*sizeof(double));
    }

    // matrix training
    for(i=0;i<caseN;i++){
    for(j=1;j<=attribN;j++){
        fscanf(train,"%lf%*[,]",&trainmatrix[i][j]);//%IF读取double      %*[,]readuntill , stop
        //because there as * so the , will not print out
    }
    fscanf(train,"%lf",&Y[i][0]); //price save in another matrix
    fscanf(train,"\n"); //move the pointer to the next line
}
    //add one to dirst one
for(i=0;i<caseN;i++){
    trainmatrix[i][0] = 1;
}
    // test matrix
for(i=0;i<testN;i++){
    for(j=0;j<attribN;j++){
        fscanf(test,"%lf%*[,]",&testmatrix[i][j]);
    }
    fscanf(test,"\n");
}

final=W(trainmatrix,Y,caseN,attribN+1);

finalresult=sub(testmatrix,final,testN,attribN);




free(trainmatrix);
free(testmatrix);
free(finalresult);
free(Y);
free(final);

return 0;
}


//******************************************************************************************

double** W(double** matrix,double ** Y,int row, int col){
    int o;

    double** xt = malloc(col*sizeof(double*));//lay down the matrix
        for(o=0;o<col;o++){
            xt[o] = malloc((row)*sizeof(double));
    }

    double** xinverse = malloc(col*sizeof(double*));
        for(o=0;o<col;o++){
            xinverse[o] = malloc((col)*sizeof(double));
    }

    double** xtx = malloc(col*sizeof(double*));
        for(o=0;o<col;o++){
            xtx[o] = malloc((col)*sizeof(double));
    }

    double** finalx = malloc(col*sizeof(double*));
        for(o=0;o<col;o++){
            finalx[o] = malloc(row*sizeof(double));
    }
    double** finaly = malloc(col*sizeof(double*));
        for(o=0;o<col;o++){
            finaly[o] = malloc(1*sizeof(double));
    }
    
    xt = transposeMatrix(matrix,row,col);//Xt
    
    xtx = multiplyMatrix(xt,matrix,col,row,row,col);//(Xt*x)
     
    xinverse = inverseMatrix(xtx,col,col);//(Xt*x)^-1
    
    finalx = multiplyMatrix(xinverse,xt,col,col,col,row);//(Xt*x)^-1 * Xt
    
    finaly = multiplyMatrix(finalx,Y,col,row,row,1);//(Xt*x)^-1 * Xt * Y
    
    return finaly;
    
}

//******************************************************************************************


double** multiplyMatrix(double **matA, double **matB, int r1, int r2, int c1, int c2)
{
    double** result = malloc(r1*sizeof(double*));
    int o,i,j,k;
    double num = 0;
    for(o=0;o<r1;o++){
        result[o] = malloc((c2)*sizeof(double));
    }
    for(i=0; i<r1;i++){
        for(j=0; j<c2;j++){
            for(k=0; k<r2;k++){
                num = num+matA[i][k]*matB[k][j];

            }
            result[i][j] = num;

            num = 0;

        }

    }
    
    return result;
}


//******************************************************************************************




double** transposeMatrix(double** mat, int r, int c)
{
  
    double** matTran = malloc(c*sizeof(double*));
    int i,j;
    for(i=0;i<c;i++){
        matTran[i] = malloc(r*sizeof(double));
    }

    for(i=0;i<c;i++){
    for(j=0;j<r;j++){
        matTran[i][j] = mat[j][i];

    }


    }

    return matTran;
    
}


//******************************************************************************************



double** inverseMatrix(double **matA, int r, int c)
{

    double** matI=malloc(r*sizeof(double*));
    int i,j,k;
    
    for(i=0;i<r;i++){
        matI[i] = malloc((c*2)*sizeof(double)); //the right side
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            matI[i][j] = matA[i][j];
        }
    }
        //the right side new standard matrix
    for(i=0;i<r;i++){
        for(j=c;j<(c*2);j++){
            if(j-c==i){
                matI[i][j] = 1;
            }else{
                matI[i][j] = 0;
            }

        }
    }
    //print(matI,row,col*2);
    //printf("\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(i==j){  //pivot
                matI = CTone(matI,i,j,r,c*2);

                for(k=i+1;k<r;k++){ //all the value below the pivot = 0
                    matI = CTzero(matI,k,j,r,c*2);
                }
            }
            }

        }
   

    for(i=r-1;i>=0;i--){ //loop again, set all other to zero
        for(j=c-1;j>=0;j--){
            if(i!=j&&matI[i][j]!=0){
                matI = RCTzero(matI,i,j,r,c*2);
            }

        }
    }
   
    double** final=malloc(r*sizeof(double*));
    for(i=0;i<r;i++){
        final[i]=malloc((c)*sizeof(double));
    }
        
    for(i=0;i<r;i++){ //only copy the right side matrix, which is we only need
        for(j=0;j<c;j++){
            final[i][j] = matI[i][j+c];
        }
    }

    return final;
}

//******************************************************************************************

double** CTone(double** sample, int i, int j,int row,int col){

    double** matrix = malloc(row*sizeof(double*));
    int o,p;
    for(o=0;o<row;o++){
        matrix[o] = malloc((col)*sizeof(double));
    }
//copy in to the matrix
    for(o=0;o<row;o++){
        for(p=0;p<col;p++){
            matrix[o][p] = sample[o][p];
        }
    }

double fac;
int d;
int k;

if(matrix[i][j]==1){
    return matrix;
    }else if(matrix[i][j]==0){ //plus one of the row with current row
        for(k=1;k<row;k++){
            if(matrix[k][j]!=0){
                for(d=0;d<col;d++){
                    matrix[i][d] = matrix[i][d]+matrix[k][d];
    }
                return matrix;
 }
}

    }else{
        fac = matrix[i][j];
        for(k=0;k<col;k++){ //be one

            matrix[i][k] = matrix[i][k]/fac;
}

return matrix;
    }

return matrix;
}

//******************************************************************************************

    
double** CTzero(double** sample, int i, int j,int row,int col){
    if(sample[i][j]==0){
        return sample;
    }
    double** matrix = malloc(row*sizeof(double*));
    int o,p;
    
    for(o=0;o<row;o++){
        matrix[o] = malloc((col)*sizeof(double));
    }
//copy to the new matrix
    for(o=0;o<row;o++){
        for(p=0;p<col;p++){
            matrix[o][p] = sample[o][p];
        }
    }

double fac=matrix[i][j];

//let the value be one
    for(p=0;p<col;p++){
matrix[i][p] = matrix[i][p]/fac;

    }

int k;
// after the first value be one, minue the pivot row(which also the first value be one)
    for(k=0;k<col;k++){
        matrix[i][k] = matrix[i][k]-matrix[j][k];
    }


return matrix;
}

//******************************************************************************************


double** RCTzero(double** sample, int i, int j,int row,int col){
    if(sample[i][j]==0){
        return sample;
    }
    double** matrix = malloc(row*sizeof(double*));
    int o,p;
    for(o=0;o<row;o++){
        matrix[o] = malloc((col)*sizeof(double));
    }
//copy to new matrix
    for(o=0;o<row;o++){
        for(p=0;p<col;p++){
            matrix[o][p] = sample[o][p];
        }
    }

double fac=matrix[i][j];

int k;

    for(k=0;k<col;k++){   //from the last row, minue all other value, let it become zero
        matrix[i][k] = matrix[i][k]-(matrix[j][k]*fac);
    }


return matrix;
}

//******************************************************************************************

double** sub(double** test, double** w,int row,int col){
    int t;
    int p;
    double num=0;

    double** final = malloc(row*sizeof(double*));
    for(t=0;t<row;t++){
        final[t] = malloc(1*sizeof(double));
    }

    for(t=0;t<row;t++){
        num = w[0][0]; //a factor
        for(p=0;p<col;p++){

            num = num+(test[t][p]*w[p+1][0]); //square, year.. multiplyMatrix matrix
}
final[t][0] = num;
printf("%0.0lf\n", final[t][0]);
}

return final;
}
