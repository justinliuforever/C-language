#include<stdio.h>
#include<stdlib.h>

//void print(double** matrix,int rownum,int comnum);
//void printone(double* matrix,int rownum);
double** transposeMatrix(double**mat,int r,int c);
double** inverseMatrix(double ** matA,int r,int c);
double** toone(double** sample, int i, int j,int row,int col);
double** tozero(double** sample, int i, int j,int row,int col);
double** newtozero(double** sample, int i, int j,int row,int col);
double** multiplyMatrix(double** matA, double** matB,int r1,int r2,int c1, int c2);
double** wcal(double** matrix,double ** Y,int row, int col);
double** sub(double** test, double** w,int row,int col);
//void printdec(double** matrix,int row);

int main(int argc, char** argv){

	int attribnum,casenum,testnum;

	FILE* train;
	train=fopen(argv[1],"r");

	if(train==NULL){

		printf("cannot find training data file with that name\n");
		return 0;

	}

	FILE* test;
	test=fopen(argv[2],"r");


	if(test==NULL){

		printf("cannot find test data file with that name\n");
		return 0;

	}

	fscanf(train,"%d\n",&attribnum);//面积、年份
	fscanf(train,"%d\n",&casenum);//多少个房子
	fscanf(test,"%d\n",&testnum);//多少个预测房子

	/*printf("attribnum is %d,casenum is %d,testnum is %d \n",attribnum,casenum,testnum);*/
	int o,i,j;
	double** trainmatrix=(double**)malloc(casenum*sizeof(double*));
	for(i=0;i<casenum;i++){
		trainmatrix[i]=(double*)malloc((attribnum+1)*sizeof(double));//没有包含price
	}

	double** testmatrix=(double**)malloc(testnum*sizeof(double*));
	for(i=0;i<testnum;i++){
		testmatrix[i]=(double*)malloc((attribnum)*sizeof(double));
	}

	double** Y=(double**)malloc(casenum*sizeof(double*));    //价格
	for(i=0;i<casenum;i++){
		Y[i]=(double*)malloc(1*sizeof(double));
	}

	double** final=(double**)malloc((attribnum+1)*sizeof(double*));
	for(o=0;o<=attribnum;o++){
		final[o]=(double*)malloc(1*sizeof(double));
	}
//最后结果的价格
	double** finalresult=(double**)malloc(testnum*sizeof(double*));
	for(o=0;o<testnum;o++){
		finalresult[o]=(double*)malloc(1*sizeof(double));
	}

    // matrix training
	for(i=0;i<casenum;i++){
	for(j=1;j<=attribnum;j++){
		fscanf(train,"%lf%*[,]",&trainmatrix[i][j]);//%IF读取double      %*[,]是读取到，停止 但是因为有*，所以不会输入，
	}
	fscanf(train,"%lf",&Y[i][0]); //price save in another matrix
	fscanf(train,"\n"); //move the pointer to the next line
}
    //这里是把每排第一个写成1
for(i=0;i<casenum;i++){
	trainmatrix[i][0]=1;
}
    // test matrix
for(i=0;i<testnum;i++){
	for(j=0;j<attribnum;j++){
		fscanf(test,"%lf%*[,]",&testmatrix[i][j]);
	}
	fscanf(test,"\n");
}

final=wcal(trainmatrix,Y,casenum,attribnum+1);

finalresult=sub(testmatrix,final,testnum,attribnum);




free(trainmatrix);
free(testmatrix);
free(finalresult);
free(Y);
free(final);

/*print(trainmatrix,casenum,attribnum);
printf("\n");
printf("\n");
print(testmatrix,testnum,attribnum);
printf("\n");
printf("\n");
printone(Y,casenum);
printf("\n");
printf("\n");
trainmatrix=inverseMatrix(trainmatrix,casenum,attribnum);
print(trainmatrix,casenum,attribnum);
*/


	return 0;
}

//==================================================================================

double** sub(double** test, double** w,int row,int col){
	int o,p;
	double num=0;

	double** final=(double**)malloc(row*sizeof(double*));
	for(o=0;o<row;o++){
		final[o]=(double*)malloc(1*sizeof(double));
	}

	for(o=0;o<row;o++){
		num=w[0][0]; //a factor
		for(p=0;p<col;p++){

			num=num+(test[o][p]*w[p+1][0]); //面积、年的.. multiplyMatrix matrix
}
final[o][0]=num;
printf("%0.0lf\n", final[o][0]);
}

return final;
}

//==================================================================================//对折
double** transposeMatrix(double**mat,int r,int c){
double** matTran=(double**)malloc(c*sizeof(double*));
int i,j;
for(i=0;i<c;i++){
    matTran[i]=(double*)malloc(r*sizeof(double));
}

for(i=0;i<c;i++){
for(j=0;j<r;j++){
    matTran[i][j]=mat[j][i];

}


}

return matTran;
}
//==================================================================================
/*
void printdec(double** matrix,int row){
	int i;
	for(i=0;i<row;i++){

		printf("%0.0lf\n",matrix[i][0]);

}


}
void print(double** matrix,int rownum,int comnum){
	int i,j;
	for(i=0;i<rownum;i++){
	for(j=0;j<comnum;j++){
		printf("%lf\t",matrix[i][j]);

}
	printf("\n");
}

}
void printone(double* matrix,int rownum){
	int i;
	for(i=0;i<rownum;i++){

		printf("%lf\t",matrix[i]);

}
	printf("\n");
}
*/
//=================================================================================

double** inverseMatrix(double ** matA, int r, int c){
double** matI=(double**)malloc(r*sizeof(double*));
int i,j,k;
for(i=0;i<r;i++){
    matI[i]=(double*)malloc((c*2)*sizeof(double)); //the right side
}

for(i=0;i<r;i++){
	for(j=0;j<c;j++){
        matI[i][j]=matA[i][j];
	}
}
    //the right side new standard matrix
for(i=0;i<r;i++){
	for(j=c;j<(c*2);j++){
		if(j-c==i){
            matI[i][j]=1;
		}else{
            matI[i][j]=0;
		}

	}
}
//print(matI,row,col*2);
//printf("\n");
for(i=0;i<r;i++){
	for(j=0;j<c;j++){
		if(i==j){  //pivot
            matI=toone(matI,i,j,r,c*2);

			for(k=i+1;k<r;k++){ //all the value below the pivot = 0
                matI=tozero(matI,k,j,r,c*2);
			}
		}
		}

	}
//	print(matI,row,col*2);
//	printf("\n");

for(i=r-1;i>=0;i--){ //loop again, set all other to zero
	for(j=c-1;j>=0;j--){
		if(i!=j&&matI[i][j]!=0){
            matI=newtozero(matI,i,j,r,c*2);
		}

	}
}
//print(matI,row,col*2);
//printf("\n");
double** final=(double**)malloc(r*sizeof(double*));
for(i=0;i<r;i++){
	final[i]=(double*)malloc((c)*sizeof(double));
}
    
for(i=0;i<r;i++){ //only copy the right side matrix, which is we only need
	for(j=0;j<c;j++){
		final[i][j]=matI[i][j+c];
	}
}

return final;
}
//=================================================================================

double** toone(double** sample, int i, int j,int row,int col){

	double** matrix=(double**)malloc(row*sizeof(double*));
	int o,p;
	for(o=0;o<row;o++){
		matrix[o]=(double*)malloc((col)*sizeof(double));
	}
//copy in to the matrix
	for(o=0;o<row;o++){
		for(p=0;p<col;p++){
			matrix[o][p]=sample[o][p];
		}
	}

double fac;
int k,d;
	if(matrix[i][j]==1){
		return matrix;
	}else if(matrix[i][j]==0){ //plus one of the row with current row
for(k=1;k<row;k++){
if(matrix[k][j]!=0){
	for(d=0;d<col;d++){
		matrix[i][d]=matrix[i][d]+matrix[k][d];
	}
return matrix;
}


}
printf("error");
return matrix;

	}else{
fac=matrix[i][j];
for(k=0;k<col;k++){ //be one

matrix[i][k]=matrix[i][k]/fac;

}

return matrix;
	}

printf("error");
return matrix;
}
//=================================================================================
double** tozero(double** sample, int i, int j,int row,int col){
	if(sample[i][j]==0){
		return sample;
	}
	double** matrix=(double**)malloc(row*sizeof(double*));
	int o,p;
	for(o=0;o<row;o++){
		matrix[o]=(double*)malloc((col)*sizeof(double));
	}
//copy to the new matrix
	for(o=0;o<row;o++){
		for(p=0;p<col;p++){
			matrix[o][p]=sample[o][p];
		}
	}

double fac=matrix[i][j];

//let the value be one
	for(p=0;p<col;p++){
matrix[i][p]=matrix[i][p]/fac;

	}

int k;
// after the first value be one, minue the pivot row(which also the first value be one)
	for(k=0;k<col;k++){
		matrix[i][k]=matrix[i][k]-matrix[j][k];
	}


return matrix;





}
//======================================================================================
double** newtozero(double** sample, int i, int j,int row,int col){
	if(sample[i][j]==0){
		return sample;
	}
	double** matrix=(double**)malloc(row*sizeof(double*));
	int o,p;
	for(o=0;o<row;o++){
		matrix[o]=(double*)malloc((col)*sizeof(double));
	}
//copy to new matrix
	for(o=0;o<row;o++){
		for(p=0;p<col;p++){
			matrix[o][p]=sample[o][p];
		}
	}

double fac=matrix[i][j];

int k;

	for(k=0;k<col;k++){   //倒着一排一排往上减
		matrix[i][k]=matrix[i][k]-(matrix[j][k]*fac);
	}


return matrix;





}
//=======================================================================================

double** multiplyMatrix(double** matA, double** matB,int r1,int r2,int c1, int c2){

	double** result=(double**)malloc(r1*sizeof(double*));
	int o,i,j,k;
	double num=0;
	for(o=0;o<r1;o++){
		result[o]=(double*)malloc((c2)*sizeof(double));
	}
	for(i=0; i<r1;i++){
		for(j=0; j<c2;j++){
			for(k=0; k<r2;k++){
				num=num+matA[i][k]*matB[k][j];

			}
			result[i][j]=num;

			num=0;

		}

	}

	return result;

}


//=======================================================================================

double** wcal(double** matrix,double ** Y,int row, int col){
	int o;

	double** xt=(double**)malloc(col*sizeof(double*));//相当于matrix倒过来
	for(o=0;o<col;o++){
		xt[o]=(double*)malloc((row)*sizeof(double));
	}

	double** xinverse=(double**)malloc(col*sizeof(double*));
	for(o=0;o<col;o++){
		xinverse[o]=(double*)malloc((col)*sizeof(double));
	}

	double** xtx=(double**)malloc(col*sizeof(double*));
	for(o=0;o<col;o++){
		xtx[o]=(double*)malloc((col)*sizeof(double));
	}

	double** finalx=(double**)malloc(col*sizeof(double*));
	for(o=0;o<col;o++){
		finalx[o]=(double*)malloc(row*sizeof(double));
	}
	double** finaly=(double**)malloc(col*sizeof(double*));
	for(o=0;o<col;o++){
		finaly[o]=(double*)malloc(1*sizeof(double));
	}

xt=transposeMatrix(matrix,row,col);//倒一下 弄立起来 Xt
//print(xt,col,row);
//printf("\n");

xtx=multiplyMatrix(xt,matrix,col,row,row,col);//(Xt*x)
//print(xtx,col,col);
//printf("\n");


xinverse=inverseMatrix(xtx,col,col);//(Xt*x)^-1
//print(xinverse,col,col);
//printf("\n");

finalx=multiplyMatrix(xinverse,xt,col,col,col,row);//(Xt*x)^-1 * Xt
//print(xinverse,col,row);
//printf("\n");

finaly=multiplyMatrix(finalx,Y,col,row,row,1);//(Xt*x)^-1 * Xt * Y
//print(finaly,col,1);
//printf("\n");

return finaly;


}
