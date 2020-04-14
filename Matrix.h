#pragma once
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class Matrix
{
private:
	int rows;
	int columns;
	T** matrix;

public:
	Matrix(int r, int c)    // Parameterized Constructor that intialize objects attributes and creat a Matrix 
	{
		rows = r;
		columns = c;
		matrix = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new T[columns];
		}
		
	}
	
	void transpose()           // Function to transpose a Matrix 
	{
		int newRows, newColumns;
		newRows = columns;
		newColumns = rows;
		queue <T> transpose;
		T** matrix2 = new T * [newRows];
		for (int i = 0; i < newRows; i++)
		{
			matrix2[i] = new T[newColumns];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				transpose.push(matrix[i][j]);
			}
		}
		for (int i = 0; i < newColumns; i++)
		{
			for (int j = 0; j < newRows; j++)
			{
				matrix2[j][i] = transpose.front();
				transpose.pop();
			}
		}
		rows = newRows;
		columns = newColumns;
		matrix = matrix2;
	}
	Matrix(const Matrix& obj)     // copy constructor 
	{
		rows = obj.rows;
		columns = obj.columns;
		matrix = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new T[columns];
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				matrix[i][j] = obj.matrix[i][j];
			}
		}
	}
	
	Matrix operator*(Matrix const& m2)     // Operator overloading for multiplication *
	{
		Matrix  m1(rows, m2.columns);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < m2.columns; j++)
			{
				m1.matrix[i][j] = 0;
				for (int k = 0; k < columns; k++)
				{
					m1.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
				}
			}
		}
		return m1;
	}

	Matrix operator+(Matrix const& m2)      // Operator overloading for addition +
	{
		Matrix  m1(rows, columns);
		
		for (int i = 0; i < rows ; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				m1.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return m1;
	}
	Matrix operator-(Matrix const& m2)       // Operator overloading for subtraction -
	{
		Matrix  m1(rows, columns);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				m1.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
			}
		}
		return m1;
	}
	void operator=(Matrix const& m2)      // Operator overloading for assignment = 
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = m2.matrix[i][j];
			}
		}
	}
	friend ostream& operator<<(ostream& output, const Matrix<T>& m)     // Operator overloading for <<
	{
		for ( int i = 0; i < m.rows; i++)
		{
			for ( int j = 0; j < m.columns; j++)
			{
				output<< m.matrix[i][j]<<' ' ;
			}
			cout << endl;
		}
		return output;
	}

	friend istream& operator>> (istream& input, const Matrix<T>& m)     // Operator overloading for >>
	{
		T element;
		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.columns; j++)
			{
				cout << "Enter the element of index " << i + 1 << " " << j + 1 << ":";
				input >> m.matrix[i][j];
			}
		}
		return input;
	}
	~Matrix()     // Destractor for deleting the Matrix 
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
};


