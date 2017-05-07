#pragma once

#include <cstdlib>
#include <memory>
#include <algorithm>
#include <exception>
#include <string>
#include <sstream>


/*!
	Matrix - representing MxN matrix (N- Rows,M- Columns)

	Elements should be accessed via (Row_index,Column_index) scheme.

	In this version elements are stored in dynamic 2d array (array of pointers) where elements are accessed as ptr[row_index][column_index].
	A revision might store elements in different version of container (vector of vectors?,
	Acccess outside class is provided by referece to element via Matrix::at(row_index,column_index) method.
*/
template<typename T>
class Matrix
{
	//#TODO consider typedefing std::size_t ? No obvious short name at the time
public:
	
	/*!
		ctor
	*/
	Matrix();
	Matrix(std::size_t size1, std::size_t size2);
	Matrix(const Matrix &M);
	virtual ~Matrix();

	/*!
		returns reference to object at given positions
	*/
	virtual inline T& at(std::size_t size1=0, std::size_t col = 0) const ;

	/*!
		checks if the object has been allocated with any values 
	*/
	bool isAllocated() const;

	void fillRow(T *const data, std::size_t n, std::size_t row);
	void fillCol(T *const data, std::size_t n, std::size_t col);


	/*!
		reallocate Matrix - change it's size
	*/
	virtual void reallocate(std::size_t newSize1, std::size_t newSize2, bool keepData = false);;

	/*!
		return string representation of matrix
	*/
	virtual std::string toString(std::size_t row, std::size_t col, char separator = ' ');;

	virtual std::string toString(char separator = ' ');



	std::size_t getSize1() const;
	std::size_t getSize2() const;


private:
	virtual T** allocate(std::size_t size1, std::size_t size2);

	std::size_t size1; //rows
	std::size_t size2; //columns

	T **ptr; //pointer to 2d array

	bool allocated;


};




template<typename T>
Matrix<T>::Matrix() :
	size1(0), size2(0), allocated(false)
{

}

template<typename T>
Matrix<T>::Matrix(std::size_t size1, std::size_t size2) :
	size1(size1), size2(size2)
{
	ptr = allocate(size1, size2);
}

template<typename T>
Matrix<T>::Matrix(const Matrix & M)
{
	this->ptr = allocate(M.size1, M.size2);
	for (std::size_t i = 0; i < M.size1; i++)
		for (std::size_t j = 0; j < M.size2; j++)
			this->at(i,j) = M.at(i, j);
		//std::copy(M.ptr[i][0], M.ptr[i][size2], this->ptr[i][0]);
	this->allocated = M.allocated;
}

template<typename T>
bool Matrix<T>::isAllocated() const
{
	return allocated;
}

template<typename T>
inline void Matrix<T>::fillRow( T *const data, std::size_t n, std::size_t row)
{
	if (row > size1 || n > size2) //check if trying to access out of bounds regions
	{
		//#TODO throw exception?
		throw std::out_of_range("Out of range element in Matrix!");
		
	}
	T *data_ptr = data;

	for (std::size_t i = 0; i < n; i++)
	{
		this->at(row,i) = *(data_ptr++);
	}


}

template<typename T>
inline void Matrix<T>::fillCol( T *const data, std::size_t n, std::size_t col)
{
	if (col > size2 || n > size1) //check if trying to access out of bounds regions
	{
		//#TODO throw exception?
		throw std::out_of_range("Out of range element in Matrix!");
	}
	T *data_ptr = data;

	for (std::size_t i = 0; i < n; i++)
	{
		this->at(i,col) = *(data_ptr++);
	}

	

}


/*!
reallocate Matrix - change it's size
*/
template<typename T>
inline void Matrix<T>::reallocate(std::size_t newSize1, std::size_t newSize2, bool keepData)
{
	T **newPtr = nullptr;
	std::size_t oldSize1 = size1;
	std::size_t oldSize2 = size2;
	allocated = false;


	newPtr = allocate(newSize1, newSize2);

	if (keepData)
	{
		std::size_t bound1 = std::min(oldSize1, newSize1); // boundary value for iterating through row 
		std::size_t bound2 = std::min(oldSize2, newSize2); //boundary value for column

		std::cout << "bound:" << bound1 << " " << bound2 << std::endl;
		for (std::size_t i = 0; i < bound1; i++)
		{
			//fill columns with old values #TODO rewrite methods to use fillCol(ptr[i], bound2, i) <-it's currently modyfing ptr only
			
			//copy of fillCol method
			

			for (std::size_t j = 0; j < bound2; j++)
			{
				newPtr[i][j]=this->at(i, j) ;
			}

		}

		allocated = true;
	}

	for (std::size_t i = 0; i < oldSize1; i++)
		delete[] ptr[i];
	delete[] ptr;

	ptr = newPtr;


}


/*!
return string representation of matrix
*/
template<typename T>
inline std::string Matrix<T>::toString(std::size_t row, std::size_t col, char separator)
{

	std::ostringstream  oss;

	for (std::size_t i = 0; i < row; i++)
	{
		for (std::size_t j = 0; j < col; j++)
		{
			oss << this->at(i, j) << separator;
		}
		oss << "\n";
	}

	return oss.str();

}

template<typename T>
inline std::string Matrix<T>::toString(char separator)
{

	std::ostringstream  oss;

	for (std::size_t i = 0; i < size1; i++)
	{
		for (std::size_t j = 0; j < size2; j++)
		{
			oss << this->at(i, j) << separator;
		}
		oss << "\n";
	}

	return oss.str();

}

template<typename T>
inline std::size_t Matrix<T>::getSize1() const
{
	return size1;
}

template<typename T>
inline std::size_t Matrix<T>::getSize2() const
{
	return size1;
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (std::size_t i = 0; i < size1; i++)
		delete[] ptr[i];
	delete[] ptr;
}

template<typename T>
T& Matrix<T>::at(std::size_t row ,std::size_t col) const
{
	if (row > size1 || col > size2)
		throw std::out_of_range("Bad range accessed on Matrix");

	return this->ptr[row][col];
}

template<typename T>
T** Matrix<T>::allocate(std::size_t size1, std::size_t size2)
{
	T** pointer = nullptr;


	try
	{
		pointer = new T*[size1]();
	}
	catch (const std::bad_alloc&)
	{

		throw std::exception("Failed to allocate memory for Matrix");
		
	}
	for (std::size_t i = 0; i < size1; i++)
	{
		try
		{
			pointer[i] = new T[size2]();
		}
		catch (const std::bad_alloc&)
		{
			exit(0);
		}
	}
	allocated = true;
	this->size1 = size1;
	this->size2 = size2;
	return pointer;
}


