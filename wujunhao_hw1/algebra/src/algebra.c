#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if(a.rows!=b.rows || a.cols!=b.cols){
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }else{
        Matrix c=create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<a.cols;j++){
                c.data[i][j]=a.data[i][j]+b.data[i][j];
            }
        }
        return c;
    }
    
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if(a.rows!=b.rows || a.cols!=b.cols){
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }else{
        Matrix c=create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<a.cols;j++){
                c.data[i][j]=a.data[i][j]-b.data[i][j];
            }
        }
        return c;
    }
    
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if(a.cols!=b.rows){
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }else{
        Matrix c=create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<b.cols;j++){
                for(int k=0;k<a.cols;k++){
                    c.data[i][j]+=a.data[i][k]*b.data[k][j];


                }
            }
        }
        return c;
    }
}

Matrix scale_matrix(Matrix a, double k)
{
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            a.data[i][j]=a.data[i][j]*k;        
        }
    }
    return a;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix c=create_matrix(a.rows,a.cols);
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            c.data[i][j]=a.data[i][j];
        }
    }
    int x;
    x=a.rows;
    a.rows=a.cols;
    a.cols=x;
    for(int i=0;i<c.rows;i++){
        for(int j=0;j<c.cols;j++){
            a.data[j][i]=c.data[i][j];
        }
    }
    return a;

}

double det_matrix(Matrix a)
{
    if(a.rows!=a.cols){
        printf("Error: The matrix must be a square matrix.\n");
    }else if(a.rows==1&&a.cols==1){
        return a.data[0][0];
    }else{
        Matrix c=create_matrix(a.rows-1,a.cols-1);
        double result=0;
        for(int del=0;del<a.rows;del++){
            int x=-1,y=0;
            for(int i=0;i<c.rows;i++){
                x++;
                if(x==del){
                    x++;
                }
                for(int j=0;j<c.cols;j++){
                    y++;
                    c.data[i][j]=a.data[x][y];
                }
            }
            result+=pow(-1,del)*det_matrix(c);
            c=create_matrix(a.rows-1,a.cols-1);
        }

        return result;
    }
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    if(a.cols!=a.rows){
        printf("Error: The matrix must be a square matrix.\n");

    }else{
        double result=0;
        for(int i=0;i<a.rows;i++){
            result+=a.data[i][i];
        }
        return result; 
    }
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}