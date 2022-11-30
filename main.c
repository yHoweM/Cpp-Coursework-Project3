#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include"../include/matrix.h"
//#include"matrix.h"
int main(){
    char input1 [100];
    printf("Please choose the type you want for matrix.\n");
    scanf("%s",input1);
    if (!strcmp(input1,"mulMatrix"))
    {
        printf("The multiplier for two matrixes is conducting.\n");
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * mat2 = creatMatrix(2,3,"2r3c2.txt");
        Matrix * mat3 = creatMatrix(3,4,"3r4c1.txt");
        Matrix * mul_mat1 = mulMatrix(mat1,mat2);
        Matrix * mul_mat2 = mulMatrix(mat1,mat3);
        printf("Matrix 1 is:\n");
        printMatrix(mat1);
        printf("Matrix 2 is:\n");
        printMatrix(mat2);
        printf("Matrix 3 is:\n");
        printMatrix(mat3);
        printf("------------------------------\n");
        printf("The operation for matrix 1 and 2 is:\n");
        printMatrix(mul_mat2);
    }
    else if (!strcmp(input1,"creatMatrix"))
    {
        printf("The matrix is creating.\n");
        Matrix * mat = creatMatrix(2,3,"2r3c1.txt");
        printMatrix(mat);
    }
    else if (!strcmp(input1,"deleteMatrix"))
    {
        printMatrix(mat);
        deleteMatrix(&mat);
        printMatrix(mat);
    }
    else if (!strcmp(input1,"copyMatrix"))
    {
        Matrix * mat = creatMatrix(2,3,"2r3c1.txt");
        Matrix * copy_mat = copyMatrix(mat);
        printf("The initialized matrix is:\n");
        printMatrix(mat);
        printf("The copied matrix is:\n");
        printMatrix(copy_mat);
    }
    else if (!strcmp(input1,"addMatrix"))
    {
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * mat2 = creatMatrix(2,3,"2r3c2.txt");
        Matrix * mat3 = creatMatrix(3,4,"3r4c1.txt");
        Matrix * add_mat1 = addMatrix(mat1,mat2);
        Matrix * add_mat2 = addMatrix(mat1,mat3);
        printf("Matrix 1 is:\n");
        printMatrix(mat1);
        printf("Matrix 2 is:\n");
        printMatrix(mat2);
        printf("Matrix 3 is:\n");
        printMatrix(mat3);
        printf("------------------------------\n");
        printf("The operation for matrix 1 and 3 is:\n");
        printMatrix(add_mat1);
    }
    else if (!strcmp(input1,"subtractMatrix"))
    {
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * mat2 = creatMatrix(2,3,"2r3c2.txt");
        Matrix * mat3 = creatMatrix(3,4,"3r4c1.txt");
        Matrix * sub_mat1 = addMatrix(mat1,mat2);
        Matrix * sub_mat2 = addMatrix(mat1,mat3);
        printf("Matrix 1 is:\n");
        printMatrix(mat1);
        printf("Matrix 2 is:\n");
        printMatrix(mat2);
        printf("Matrix 3 is:\n");
        printMatrix(mat3);
        printf("------------------------------\n");
        printf("The operation for matrix 1 and 2 is:\n");
        printMatrix(sub_mat1);
    }
    else if (!strcmp(input1,"addScalar"))
    {   
        float number = 9.9;
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * add_sca_mat = addScalar(mat1,number);
        printMatrix(mat1);
        printf("After adding number %f, the matrix is:\n",number);
        printMatrix(add_sca_mat);
    }
    else if (!strcmp(input1,"subtractScalar"))
    {
        float number = 9.8;
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * sub_sca_mat = subtractScalar(mat1,number);
        printMatrix(mat1);
        printf("After subtracting number %f, the matrix is:\n",number);
        printMatrix(sub_sca_mat);
    }
    else if (!strcmp(input1,"mulScalar"))
    {
        float number = 5;
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        Matrix * mul_sca_mat = mulScalar(mat1,number);
        printMatrix(mat1);
        printf("After multiplying number %f, the matrix is:\n",number);
        printMatrix(mul_sca_mat);
    }
    else if (!strcmp(input1,"matrixMax"))
    {
        Matrix * mat1 = creatMatrix(2,3,"2r3c1.txt");
        float max = matrixMax(mat1);
        printMatrix(mat1);
        printf("The max value of the input matrix is: %f.\n",max);
    }
    else if (!strcmp(input1,"matrixMin"))
    {
        Matrix * mat1 = creatMatrix(2,3,"2r3c2.txt");
        float min = matrixMin(mat1);
        printMatrix(mat1);
        printf("The min value of the input matrix is: %f.\n",min);
    }
    return 0;
}