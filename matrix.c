#include"../include/matrix.h"
#include <stdlib.h>
#include<string.h>
#include <stdio.h>

void printMatrix(const Matrix * mat){
    if (mat==NULL)
    {
        printf("The matrix does not exist!\n");
        return;
    }
    else{
        for (int i = 0; i < mat->rows; i++)
        {
            for (int j = 0; j < mat->cols; j++)
            {
                printf("%f ",mat->pData[i][j]);
            }
            printf("\n");
        }
        return;
    }
}

Matrix * creatMatrix(const int row, const int col, const char * filename){
    if (row<=0||col<=0)
    {
        printf("The parameters should be positive integer!\n");
        return NULL;
    }
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = row;
    mat->cols = col;
    mat->pData =  (float **)malloc(row*sizeof(float*));
    //allocate memory for rows in **
    for (int i = 0; i < row; i++)
    {
        mat->pData[i] = (float *)malloc(col*sizeof(float));
        //allocate memory for cols in *
    }
    if (filename!=NULL)
    {
        FILE *file = fopen(filename,"r");
    if (file==NULL)
        {
            printf("Input file does not exist.\n");
            return NULL;
        }
    else
        {
            float temp;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    fscanf(file, "%f", &temp);
                    mat->pData[i][j] = temp;
                }
            }
        }
    }
    return mat;
}

void deleteMatrix(Matrix ** p_mat){
    Matrix * mat = *p_mat;
    if (mat==NULL)
    {
        printf("The aimed matrix does not exist!\n");
        return;
    }
    else
    {
        for (int i = 0; i < mat->rows; i++)
        {
            free(mat->pData[i]);//free the cols for mat
        }
        free(mat->pData);//free the rows for mat
        free(mat);//free the created structure 
        printf("The matrix has been deleted.\n");
        memset(mat, 0, sizeof(Matrix)); //this step is not needed, but to ensure privacy
        *p_mat = NULL;
        return;
    }
}

Matrix * copyMatrix(const Matrix * mat){
    Matrix * mat_copy = creatMatrix(mat->rows,mat->cols,NULL);
    if (mat==NULL)
    {
        printf("The aimed matrix does not exist!\n");
        return NULL;
    }
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            mat_copy->pData[i][j] = mat->pData[i][j];
        }
    }
    return mat_copy;
}

Matrix * addMatrix( const Matrix *mat1, const  Matrix *mat2){
    Matrix * mat_add = creatMatrix(mat1->rows,mat1->cols,NULL);
    if (mat1==NULL||mat2==NULL)
    {
        printf("The input matrixes do not exist!\n");
        return NULL;
    }
    else if (mat1->cols!=mat2->cols||mat1->rows!=mat2->rows)
    {
        printf("The size of input matrixes is not the same!\n");
        return NULL;
    }
    else 
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            mat_add->pData[i][j] = mat1->pData[i][j]+mat2->pData[i][j];
        }
    }
    return mat_add;
}

Matrix * subtractMatrix(const  Matrix *mat1, const  Matrix *mat2){
    Matrix * mat_sub = creatMatrix(mat1->rows,mat1->cols,NULL);
    if (mat1==NULL||mat2==NULL)
    {
        printf("The input matrixes do not exist!\n");
        return NULL;
    }
    else if (mat1->cols!=mat2->cols||mat1->rows!=mat2->rows)
    {
        printf("The size of input matrixes is not the same!\n");
        return NULL;
    }
    else 
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            mat_sub->pData[i][j] = mat1->pData[i][j]-mat2->pData[i][j];
        }
    }
    return mat_sub;
}

Matrix * addScalar(const  Matrix * mat1, float num){
    Matrix * mat_add_sca = creatMatrix(mat1->rows,mat1->cols,NULL);
    if (mat1==NULL)
    {
        printf("The input matrix does not exist!\n");
        return NULL;
    }
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            mat_add_sca->pData[i][j] = mat1->pData[i][j]+num;
        }
    }
    return mat_add_sca;
}

Matrix * subtractScalar( const  Matrix * mat1, float num){
    Matrix * mat_sub_sca = creatMatrix(mat1->rows,mat1->cols,NULL);
    if (mat1==NULL)
    {
        printf("The input matrix does not exist!\n");
        return NULL;
    }
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            mat_sub_sca->pData[i][j] = mat1->pData[i][j]-num;
        }
    }
    return mat_sub_sca;
}

Matrix * mulScalar(const  Matrix * mat1, float num){
    Matrix * mat_mul_sca = creatMatrix(mat1->rows,mat1->cols,NULL);
    if (mat1==NULL)
    {
        printf("The input matrix does not exist!\n");
        return NULL;
    }
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            mat_mul_sca->pData[i][j] = mat1->pData[i][j]*num;
        }
    }
    return mat_mul_sca;
}

Matrix * mulMatrix(const  Matrix * mat1,const  Matrix * mat2){
    if (mat1->cols!=mat2->rows)
    {
        printf("The column of the first matrix and the row of the second matrix is not the same!\n");
        return NULL;
    }
    Matrix * mat_mul = creatMatrix(mat1->rows,mat2->cols,NULL);
    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat2->cols; j++)
        {
            float sum = 0;
            for (int x = 0; x < mat1->cols; x++)
            {
                sum += mat1->pData[i][x]*mat2->pData[x][j];
            }
            mat_mul->pData[i][j] = sum;
        }
    }
    return mat_mul;
}

float matrixMax(const  Matrix * mat){
    float max = 0;
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            max = (max < mat->pData[i][j])?mat->pData[i][j] : max;
        }
    }
    return max;
}

float matrixMin(const  Matrix * mat){
    float min = 0;
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            min = (min < mat->pData[i][j])?min : mat->pData[i][j];
        }
    }
    return min;
}