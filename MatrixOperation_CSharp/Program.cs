using System;

namespace MatrixOperations{
    class Program{
        static void Main(string[] args){
            Matrix m1 = new Matrix(2, 3);
            m1.setValues(new float[] {1.1f,2.2f,3f,1f,2f,3f});
            Matrix m2 = new Matrix(3, 2);
            m2.setValues(new float[] {1f,2f,1f,2f,1f,2f});
            Matrix tmp_mat = m1*m2;
            for(int i = 0;i < 2;++ i){
                for(int j  =0;j <2 ;++ j){
                    Console.Write(tmp_mat.getValue(i,j));
                }
                Console.WriteLine();
            }
            Matrix m3 = new Matrix(new float[2,3] {{0,1,-1},{2,3,3}});
            tmp_mat = m1+m3;
            for(int i = 0;i < 2;++ i){
                for(int j  =0;j <3 ;++ j){
                    Console.Write(tmp_mat.getValue(i,j));
                }
                Console.WriteLine();
            }
            tmp_mat = m1-m3;
            for(int i = 0;i < 2;++ i){
                for(int j  =0;j <3 ;++ j){
                    Console.Write(tmp_mat.getValue(i,j));
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}