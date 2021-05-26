#include "Size.hpp"

namespace PhysEn{

Size::Size(){
	this->rows = 0;
	this->columns = 0;
}

Size::Size(size_t rowsCols){
	this->rows = rowsCols;
	this->columns = rowsCols;
}

Size::Size(size_t rows, size_t columns){
	this->rows = rows;
	this->columns = columns;
}

bool Size::isSquare(){
	return rows == columns;
}

Size operator+(Size left, Size right){
	return Size(left.rows + right.rows, left.columns + right.columns);
}

Size operator-(Size left, Size right){
	Size result;
	if (left.rows < right.rows)
		result.rows = 0;
	else
		result.rows = left.rows - right.rows;
	
	if (left.columns < right.columns)
		result.columns = 0;
	else
		result.columns = left.columns - right.columns;

	return result;
}

bool operator==(Size left, Size right){
	return left.rows == right.rows && left.columns == right.columns;
}

void operator+=(Size& left, Size& right){
	left.rows += right.rows;
	left.columns += right.columns;
}

void operator-=(Size& left, Size& right){
	if (left.rows < right.rows)
		left.rows = 0;
	else
		left.rows = left.rows - right.rows;
	
	if (left.columns < right.columns)
		left.columns = 0;
	else
		left.columns = left.columns - right.columns;
}

void operator*=(Size& left, int right){
	if (right >= 0){
		left.rows *= right;
		left.columns *= right;
	}
}


std::ostream& operator << (std::ostream& os, Size size){
	return os << "Size(" << size.rows << ", " << size.columns << ")\n";
}

}