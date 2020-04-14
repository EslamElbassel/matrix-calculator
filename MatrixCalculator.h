#pragma once
#include<iostream>
#include"Matrix.h"
class MatrixCalculator
{

public:
	int choice;
	string name;
	MatrixCalculator();
	
	void addition();       //this function to add two  matrices of integers
 	
	void subtraction();    //This function to subtract two matrices of integers
	
	void multiplication();  //This function to multiply two matrices of integers
	
	void transpose();       //This function to transpose matrix of integers
	
};

