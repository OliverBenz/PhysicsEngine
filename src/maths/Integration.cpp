#include "Integration.hpp"

#include <array>

#include "../common/Tree.hpp"

namespace PhysEn {
namespace Maths {

// TODO: Calculate the amount values based on function and interval
static constexpr int AMOUNT_VALUES = 20000;
static constexpr double MAX_AREA = 60.0;


/**
 * @brief Split the integration area into specific sub-areas.
 * @param limitA  [in]  Lower bound integration limit.
 * @param limitB  [in]  Upper bound integration limit.
 * @param xValues [out] Vector containing resulting areas.
 */
static void generateXValues(double limitA, double limitB, std::array<double, AMOUNT_VALUES> &xValues) {
	double distance = (limitB - limitA) / (double) AMOUNT_VALUES;

	for (int i = 0; i < AMOUNT_VALUES; i++)
		xValues[i] = limitA + i * distance;
	xValues[AMOUNT_VALUES-1] = limitB;
}

/**
 * @brief Calculate integral using trapezoid rule with given value pairs.
 * @param xValues x-Values of the function.
 * @param yValues y-Values of the function. (Corresponding to x-Values)
 * @return Result of integral.
 */
static double compute_integral(std::array<double, AMOUNT_VALUES> &xValues,
                               std::array<double, AMOUNT_VALUES> &yValues) {
	double result = 0;

	for (int i = 0; i < AMOUNT_VALUES - 1; i++)
		result += (xValues[i + 1] - xValues[i]) * 0.5f * (yValues[i] + yValues[i + 1]);

	return result;
}

// TODO: Store values as std::array<std::pair<double, double>, AMOUNT_VALUES> ??
double integrate(double (*function)(double x), double limitA, double limitB) {
	// We can invert the bounds of the integral by changing the sign of the result
	bool invertBounds = false;
	if(limitA > limitB){
		std::swap(limitA, limitB);
		invertBounds = true;
	}

	// Sum of all sub-areas
	double sum = 0.0;
	std::array<double, AMOUNT_VALUES> xValues = {};
	std::array<double, AMOUNT_VALUES> yValues = {};

	double startArea = limitA;
	do {
		// Calculate x values
		if(startArea+MAX_AREA <= limitB)
			generateXValues(startArea, startArea + MAX_AREA, xValues);
		else
			generateXValues(startArea, limitB, xValues);

		// Calculate y values from passed function
		for(int j = 0; j < AMOUNT_VALUES; j++)
			yValues[j] = (*function)(xValues[j]);

		sum += compute_integral(xValues, yValues);

		startArea += MAX_AREA;
	} while(startArea < limitB);

	if(invertBounds)
		sum = -sum;

	return sum;
}

// ----------------------
// Analytical Integration
// ----------------------
static bool parseFunction(std::string& value, Tree* tree) {
	std::string buffer{};

	// Add a number to the tree
	auto pushNumber = [&](){
		if (! buffer.empty()) {
			Node* node = new Node;
			node->value = buffer;
			buffer.clear();

			tree->push_back(node);
		}
	};

	// Add a single character to the tree
	auto pushCharacter = [&](char c){
		Node* node = new Node;
		node->value = "";
		node->value.push_back(c);

		tree->push_back(node);
	};

	for(char val: value){
		// Number or "."
		if ((val >= 48 && val <= 57) || val == 46) {
			buffer.push_back(val);
		}
			// Variable
		else if(val >= 97 && val <= 123) {
			if (! buffer.empty()) {   // Cannot have syntax 23y34
				std::cerr << "Error in print: Invalid syntax at: " << val << "\n";
				return false;
			}
			pushCharacter(val);
		}
			// Operators
		else {
			bool found = false;
			switch(val) {
				case '+':
				case '/':
				case '-':
				case '*':
				case '(':
				case ')':
					found = true;
					break;
				case ' ':
					break;
				default:
					std::cerr << "Error in print: Case not covered: " << val << "\n";
					return false;
			}

			if (found){
				pushNumber();
				pushCharacter(val);
			}
		}
	}
	pushNumber();
	return true;
}

std::string integrateAnalytic(std::string& value){
	Tree tree;
	parseFunction(value, &tree);

	// Just for testing
	std::cout << tree;
	return "";
}

}
}