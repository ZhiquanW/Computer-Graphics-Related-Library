using System;

namespace MatrixOperations {
    class Matrix {
        private int row;
        private int column;
        private float[,] data;

        public Matrix(int _row, int _col) {
            row = _row;
            column = _col;
            data = new float[_row, _col];
        }
        public Matrix(float[,] _mat) {
            row = _mat.GetLength(0);
            column = _mat.GetLength(1);
            data = _mat;
        }

        public int Row { get => row; set => row = value; }
        public int Column { get => column; set => column = value; }

        public void setValue(int _row, int _col, float _val) {
            data[_row, _col] = _val;
        }
        public float getValue(int _row, int _col) {
            return data[_row, _col];
        }
        public void setValues(float[] _vals) {
            data = new float[row, column];
            int counter = 0;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    data[i, j] = _vals[counter++];
                }
            }
        }

        // Verification of the sizes of the Matrixs
        public bool CompareSize(Matrix _mat) {
            if (row == _mat.Row && column == _mat.Column)
                return true;
            return false;
        }

        //Addition of two matrix
        public static Matrix operator +(Matrix _m1, Matrix _m2) {
            if (_m1.CompareSize(_m2) == false) {
                throw new Exception("The Size of Matrix Does Not Match");
            }
            Matrix result = new Matrix(_m1.row, _m1.column);
            for (int i = 0; i < _m1.row; i++)
                for (int j = 0; j < _m1.column; j++)
                    result.setValue(i, j, _m1.getValue(i, j) + _m2.getValue(i, j));
            return result;
        }

        // Substraction of two dataes
        public static Matrix operator -(Matrix _m1, Matrix _m2) {
            if (_m1.CompareSize(_m2) == false) {
                throw new Exception("Matrix Size Does Not Match");
            }
            Matrix result = new Matrix(_m1.row, _m1.column);
            for (int i = 0; i < _m1.row; i++)
                for (int j = 0; j < _m1.column; j++)
                    result.setValue(i, j, _m1.getValue(i, j) - _m2.getValue(i, j));
            return result;
        }

        // Get new data which is multipled on the decimal number
        // public Matrix MulAInteger (int integer) {
        //     Matrix result = new Matrix (row, column);
        //     for (int i = 0; i < row; i++)
        //         for (int j = 0; j < column; j++)
        //             result.data[i, j] = data[i, j] * integer;
        //     return result;
        // }

        // Multiplication of the Matrixes
        public static Matrix operator *(Matrix _m1, Matrix _m2) {
            if (_m1.Column != _m2.Row) {
                throw new Exception("The Size of Matrix Does Not Match ");
            }
            Matrix result = new Matrix(_m1.Row, _m2.Column);
            for (int i = 0; i < _m1.Row; i++)
                for (int j = 0; j < _m2.Column; j++)
                    for (int k = 0; k < _m1.Column; k++)
                        result.setValue(i, j, _m1.getValue(i, j) * _m2.getValue(i, j));
            return result;
        }

        public bool Equals(Matrix _mat) {
            if (CompareSize(_mat) == false) {
                return false;
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    if (data[i, j] != _mat.getValue(i, j)) {
                        return false;
                    }
                }
            }
            return true;
        }

        public override bool Equals(object _obj) {
            if(_obj == null || this.GetType()!= _obj.GetType()) {
                return false;
            }
            return Equals((Matrix)_obj);
        }

        public override int GetHashCode() {
            String tmp_str = "Matrix";
            for(int i =0;i < row;++i) {
                for(int j = 0;j < column;++j) {
                    tmp_str += data[i, j].ToString();
                }
                tmp_str += "n";
            }
            return base.GetHashCode() ^ tmp_str.GetHashCode();
        }
        //Verification of the Matrix
        public static bool operator ==(Matrix m1, Matrix m2) {
            if (m1.CompareSize(m2) == false) {
                return false;
            }
            for (int i = 0; i < m1.Column; i++)
                for (int j = 0; j < m1.Row; j++)
                    if (m1.data[i, j] != m2.data[i, j])
                        return false;
            return true;
        }
        public static bool operator !=(Matrix _m1, Matrix _m2) {
            if (_m1 == _m2) {
                return false;
            }
            return true;
        }

        // Matrix transposition
        public Matrix Transpose() {
            Matrix result = new Matrix(column, row);
            for (int i = 0; i < column; i++) {
                for (int j = 0; j < row; j++) {
                    result.setValue(i, j, data[j, i]);
                }
            }
            return result;
        }

        //Useless Function
        /*
        public void InputMatrix() {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    data[i, j] = Convert.ToInt32(Console.ReadLine());
        }

        public void Print(string typePrint) {
            Console.WriteLine(typePrint);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    Console.Write(data[i, j] + " ");
            Console.WriteLine();
        }
        */
    }
}