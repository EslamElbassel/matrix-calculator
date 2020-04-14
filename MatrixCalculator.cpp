#include "MatrixCalculator.h"

MatrixCalculator::MatrixCalculator()
{
	cout << "Enter your name: ";
	std::cin >> name;
}

void MatrixCalculator::addition()
{
	int r, c;
	std::cout << "Enter the number of rows: ";
	std::cin >> r;
	std::cout << "Enter the number of columns: ";
	std::cin >> c;
	Matrix<int> m1(r, c);
	Matrix<int> m2(r, c);
	Matrix<int> m3(r, c);
	std::cout << "\nEnter elements of the first matrix\n";
	std::cout << "____________________________________\n";
	cin >> m1;

	std::cout << "\nEnter elements of the secound matrix\n";
	std::cout << "_____________________________________\n";
	cin >> m2;

	std::cout << "\nThe result is\n";
	m3 = m1 + m2;
	cout << m3;
}

void MatrixCalculator::subtraction()
{
	int r, c;
	std::cout << "Enter the number of rows: ";
	std::cin >> r;
	std::cout << "Enter the number of columns: ";
	std::cin >> c;
	Matrix<int> m1(r, c);
	Matrix<int> m2(r, c);
	Matrix<int> m3(r, c);
	std::cout << "\nEnter elements of the first matrix\n";
	std::cout << "____________________________________\n";
	cin >> m1;
	std::cout << "\nEnter elements of the secound matrix\n";
	std::cout << "_____________________________________\n";
	cin >> m2;
	std::cout << "\nThe result is\n";
	m3 = m1 - m2;
	cout << m3;
}

void MatrixCalculator::multiplication()
{
	int r1, r2, c1, c2;
	std::cout << "Enter the number of rows of first matrix : ";
	std::cin >> r1;
	std::cout << "Enter the number of columns of first matrix : ";
	std::cin >> c1;
	std::cout << "Enter the number of rows of secound matrix : ";
	std::cin >> r2;
	std::cout << "Enter the number of columns of secound matrix : ";
	std::cin >> c2;
	if (c1 == r2)
	{
		Matrix<int> m1(r1, c1);
		Matrix<int> m2(r2, c2);
		Matrix<int> m3(r1, c2);
		std::cout << "\nEnter elements of the first matrix\n";
		std::cout << "____________________________________\n";
		cin >> m1;
		std::cout << "\nEnter elements of the secound matrix\n";
		std::cout << "_____________________________________\n";
		cin >> m2;
		std::cout << "\nThe result is\n";
		m3 = m1 * m2;
		cout << m3;
	}
	else if (c2 == r1)
	{
		Matrix<int> m1(r1, c1);
		Matrix<int> m2(r2, c2);
		Matrix<int> m3(r2, c1);
		std::cout << "\nEnter elements of the first matrix\n";
		std::cout << "____________________________________\n";
		cin >> m1;
		std::cout << "\nEnter elements of the secound matrix\n";
		std::cout << "_____________________________________\n";
		cin >> m2;
		std::cout << "\nThe result is\n";
		m3 = m1 * m2;
		cout << m3;
	}
	else
	{
		std::cout << "These two matrices can't be multiplied\n ";
	}
}

void MatrixCalculator::transpose()
{
	int r, c;
	std::cout << "Enter the number of rows: ";
	std::cin >> r;
	std::cout << "Enter the number of columns: ";
	std::cin >> c;
	Matrix<int> m1(r, c);
	cin >> m1;

	cout << m1;
	m1.transpose();
	std::cout << "The matrix after Transpose\n";

	cout << m1;
}
