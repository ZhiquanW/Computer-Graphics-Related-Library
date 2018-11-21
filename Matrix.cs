using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Matrix
    {
        private int row;
        private int column;
        private double[,] data;

        public int Row { get => row; set => row = value; }
        public int Column { get => column; set => column = value; }

        public Matrix(int row, int column, double[] data)
        {
            this.row = row;
            this.column = column;
            int counter = 0;
            for (int i = 0; i < Row; i++)
            {
                for (int j = 0; j < Column; j++)
                {
                    this.data[i, j] = data[counter++];
                }
            }
        }

        public Matrix(double[,] data)
        {
            this.row = data.GetLength(0);
            this.column = data.GetLength(1);
            this.data = data;
        }

        public Matrix() { }

        private static bool CompareSize1(Matrix matrix1, Matrix matrix2)
        {
            if(matrix1.Row == matrix2.Row && matrix1.Column == matrix2.Column)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private static bool CompareSize2(Matrix matrix1, Matrix matrix2)
        {
            if(matrix1.Column == matrix2.Row)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static Matrix operator +(Matrix matrix1, Matrix matrix2)
        {
            double[,] temp = new double[matrix1.Row, matrix1.Column];
            if(CompareSize1(matrix1, matrix2))
            {
                for (int i = 0; i < matrix1.Row; i++)
                {
                    for (int j = 0; j < matrix1.Column; j++)
                    {
                        temp[i, j] = matrix1.data[i, j] + matrix2.data[i, j];
                    }
                }
            }
            else
            {
                throw new Exception("There are somthing wrong with your input");
            }
            Matrix result = new Matrix(temp);
            return result;
        }

        public static Matrix operator -(Matrix matrix1, Matrix matrix2)
        {
            double[,] temp = new double[matrix1.Row, matrix1.Column];
            if (CompareSize1(matrix1, matrix2))
            {
                for (int i = 0; i < matrix1.Row; i++)
                {
                    for (int j = 0; j < matrix1.Column; j++)
                    {
                        temp[i, j] = matrix1.data[i, j] - matrix2.data[i, j];
                    }
                }
            }
            else
            {
                throw new Exception("There are somthing wrong with your input");
            }
            Matrix result = new Matrix(temp);
            return result;
        }

        public static Matrix operator *(Matrix matrix1, Matrix matrix2)
        {
            double[,] temp = new double[matrix1.Row, matrix2.Column];
            if (CompareSize2(matrix1, matrix2))
            {
                for (int i = 0; i < matrix1.Row; i++)
                {
                    for (int j = 0; j < matrix2.Column; j++)
                    {
                        for (int k = 0; k < matrix1.Column; k++)
                        {
                            temp[i, j] += matrix1.data[i, k] * matrix2.data[k, j];
                        }
                    }
                }
            }
            else
            {
                throw new Exception("There are somthing wrong with your input!");
            }
            Matrix result = new Matrix(temp);
            return result;
        }

        public static Matrix operator *(Matrix matrix, double k)
        {
            double[,] temp = new double[matrix.Row, matrix.Column];
            for (int i = 0; i < matrix.Row; i++)
            {
                for (int j = 0; j < matrix.Column; j++)
                {
                    temp[i, j] = k * matrix.data[i, j];
                }
            }
            Matrix result = new Matrix(temp);
            return result;
        }

        public Matrix TransposeMatrix(Matrix matrix)
        {
            double[,]temp = new double[matrix.Column, matrix.Row];
            for (int i = 0; i < matrix.Column; i++)
            {
                for (int j = 0; j < matrix.Row; j++)
                {
                    temp[i, j] = matrix.data[j, i];
                }
            }
            Matrix result = new Matrix(temp);
            return result;
        }

        public Matrix GetInverseMatrix(Matrix matrix)
        {
            double[,] result = new double[matrix.Row, matrix.Column];
            if (matrix.Row != matrix.Column)
            {
                throw new Exception("There are somthing wrong with your input");
            }
            //初始化矩阵
            double[,] temp = new double[matrix.Row * 2 + 1, matrix.Column * 2 + 1];

            for (int i = 0; i < matrix.Row; i++)
            {
                for (int j = 0; j < matrix.Column; j++)
                {
                    temp[i, j] = matrix.data[i, j];
                }
            }
            for (int i = 0; i < matrix.Row; i++)
            {
                temp[i, i + matrix.Column] = 1;
            }
            //求逆矩阵
            for (int k = 0; k <matrix.Row; k++)
            {
                if (temp[k, k] != 1)
                {
                    double bs = temp[k, k];
                    temp[k, k] = 1;
                    for (int p = k + 1; p < 2 * matrix.Column; p++)
                    {
                        temp[k, p] /= bs;
                    }
                }
                for (int q = 0; q < matrix.Row; q++)
                {
                    if (q != k)
                    {
                        double bs = temp[q, k];
                        for (int p = 0; p < 2 *matrix.Column; p++)
                        {
                            temp[q, p] -= bs * temp[k, p];
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            //将结果赋值给新矩阵
            for (int x = 0; x < matrix.Row; x++)
            {
                for (int y = matrix.Column; y < 2 * matrix.Column; y++)
                {
                    result[x, y - matrix.Column] = temp[x, y];
                }
            }
            Matrix res = new Matrix(result);
            return res;
        }
    }
}
