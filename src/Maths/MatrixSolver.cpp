#include "MatrixSolver.hpp"

namespace PhysEn {
namespace Maths {

// TODO: Append to not require square matrix
bool makeUpperTriangle(Matrix& matrix){
	if (!matrix.getSize().isSquare())
		return false;

	double diagonal;
	size_t rowCount = matrix.getSize().rows;

	for (size_t i = 0; i < rowCount; i++){
		// Divide the i-th row by the diagonal element
		diagonal = matrix.at(i, i);
		for(size_t j = i; j < rowCount; j++){
			matrix.at(i, j) /= diagonal;
		}

		// Subtract the normalized equation from all the other rowCount of the matrix
		for(size_t k = i + 1; k < rowCount; k++){
			diagonal = matrix.at(k, i);

			for(size_t j = i; j < rowCount; j++)
				matrix.at(k, j) -= matrix.at(i, j) * diagonal;
		}
	}

	return true;
}

Maths::Vector solveEquation(Matrix& components, Vector& result){
	if (components.getSize().rows != result.getSize())
		throw std::invalid_argument("Result vector dimension does not line up with component row count!");

	double diagonal;
	size_t rowCount = components.getSize().rows;

	for (size_t i = 0; i < rowCount; i++){
		// Divide the i-th row by the diagonal element
		diagonal = components.at(i, i);
		for(size_t j = i; j < rowCount; j++){
			components.at(i, j) /= diagonal;
		}

		// Divide the i-th known term by the diagonal element
		result[i] /= diagonal;

		// Subtract the normalized equation from all the other rowCount of the components
		for(size_t k = i + 1; k < rowCount; k++){
			diagonal = components.at(k, i);

			for(size_t j = i; j < rowCount; j++)
				components.at(k, j) -= components.at(i, j) * diagonal;

			// Do the same also for the known terms
			result[k] -= diagonal * result[i];
		}
	}

	Maths::Vector x(result.getSize());
	double sum = 0;
	// Index k is incremented for nested loop and will be -1 in the end!
	for (int k = (int)rowCount - 1; k >= 0; k--) {
		sum = 0;
		for (size_t i = k + 1; i < rowCount; i++)
			sum += components.at(k, i) * x[i];

		x[k] = result[k] - sum;
	}

	return x;
}

}
}