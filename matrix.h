#pragma once
#define MATRIX_H
#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>

template<typename T>
class Matrix
{
private:
	size_t row = 0;
	size_t column = 0;
	//T* midware[row] = {};
	//T** matrix{new T*midware[row]};
	T** matrix{};
public:
	Matrix() = default;					//缺省构造函数
	Matrix(size_t m, size_t n)	//构造函数
	{
		//size_t i;
		row = m, column = n;
		matrix = new T * [row];			//初始化行
		for (size_t i = 0; i < row; i++)
			matrix[i] = new T[column];	//初始化列
	}
	Matrix(Matrix& M)					//copy函数
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] = M.matrix[i][j];
	}

	size_t get_row()
	{
		return row;
	}
	size_t get_column()
	{
		return column;
	}
	T** get_matrix()
	{
		return matrix;
	}
	void new_Array2D()		//数组赋值函数(type-in)
	{
		//row = m, column = n;
		//matrix = new T * [row];
		//for (size_t i = 0; i < row; i++)
		//	matrix[i] = new T[column];
		//T** matrix{ new T * [this->row] };
		//for (size_t i = 0; i < this->row; ++i)
		//{
		//	this->matrix[i] = new T[this->column]{};//矩阵的行
		//}
		for (size_t i{}; i < this->row; ++i)
		{
			for (size_t j{}; j < this->column; ++j) {
				std::cout << "Please enter the value of row " << i + 1 << " and column " << j + 1 << std::endl;
				std::cin >> this->matrix[i][j];//输入矩阵第[i+1，j+1]的值
			}
		}
	}
	void delete_Array2D()					//数值删除函数
	{
		for (size_t i{}; i < this->row; ++i)
			delete[] this->matrix[i];//删除第一个矩阵的列
		delete[] this->matrix;//删除第一个矩阵
	}
	Matrix<T> operator *(Matrix& matrix)	//重构*
	{
		Matrix<T> matrix_mid(this->column, matrix.get_row());
		T pvalue{};
		for (size_t i{}; i < this->row; ++i) {
			for (size_t j{}; j < matrix.column; ++j) {
				for (size_t k{}; k < this->column; ++k) {
					pvalue = (this->matrix[i][k] * matrix.matrix[k][j]);//计算第一个矩阵第[i][k]个元素和第二个矩阵第[k][j]个元素的乘积
					matrix_mid[i][j] += pvalue;//第三个元素第[i][j]个元素的值等于k个pavlue的值的和
				}
			}
		}
		return matrix_mid;
	}
	const T& operator =(Matrix& matrix)		//重构=
	{
		this->row = matrix.get_row();
		this->column = matrix.get_column();
		this->matrix = matrix.get_matrix();
		return this;
	}
	T* operator[](size_t i)					//重构下标运算符
	{
		return this->matrix[i];
	}
	void display_Matrix()					//普通输出
	{
		for (size_t i{ }; i < this->row; ++i) {
			std::cout << "|";
			for (size_t j{ }; j < this->column; ++j) {
				std::cout <<" "<< this->matrix[i][j]<<" ";
			}
			std::cout <<"|" << std::endl;
		}//遍历输出整个矩阵
	}
	void display_Boolean_Matrix()			//布尔矩阵输出
	{
		for (size_t i{ }; i < this->row; ++i) {
			std::cout << "|";
			for (size_t j{ }; j < this->column; ++j) {
				if (this->matrix[i][j] > 0)
				{
					std::cout << " " << "1"<<" ";
				}
				else
				{
					std::cout << " " << "0"<<" ";
				}
			}
			std::cout << "|" << std::endl;
		}//遍历输出整个矩阵
	}
	~Matrix()								//析构函数
	{
		delete_Array2D();
	}
};
