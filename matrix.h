#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix
{   int rows;
    int cols;
    float ** pData;
}Matrix;

void printMatrix(const Matrix * mat);

Matrix * creatMatrix(const int row, const int col, const char * filename);

void deleteMatrix(Matrix ** p_mat);

Matrix * copyMatrix(const Matrix * mat);

Matrix * addMatrix(const  Matrix *mat1, const  Matrix *mat2);

Matrix * subtractMatrix(const  Matrix *mat1, const  Matrix *mat2);

Matrix * addScalar(const  Matrix * mat1, float num);    

Matrix * subtractScalar(const  Matrix * mat1, float num);

Matrix * mulScalar(const  Matrix * mat1, float num);

Matrix * mulMatrix(const  Matrix * mat1,const  Matrix * mat2);

float matrixMax(const  Matrix * mat);     

float matrixMin(const  Matrix * mat);  

#endif