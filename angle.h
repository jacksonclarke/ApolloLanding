/*************************************************************
 * 1. Name:
 *      Jackson Clarke
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718
#define _USE_MATH_DEFINES // for M_PI

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include <cmath>     // for normalization
using namespace std;

class TestAngle;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
   friend TestAngle;
   double radians;

public:
	
	double getDegrees() {
		return convertToDegrees(radians);
	}

	double getRadians() {
		return radians;
	}

	void setDegrees(double degrees) {
		radians = normalize(convertToRadians(degrees));
	}

	void setRadians(double rad) {
		radians = normalize(rad);
	}

	void display(ostream& out) {
		// Broken?
		cout.setf(ios::fixed);     // "fixed" means don't use scientific notation
		cout.setf(ios::showpoint); // "showpoint" means always show the decimal point
		cout.precision(1);         // Set the precision to 1 decimal place of accuracy.
		cout << convertToDegrees(radians) << "degrees";
	}

private:

	double normalize(double rad) {
		// Floor???
		return atan2(sin(rad), cos(rad));;
	}

	double convertToDegrees(double rad) {
		double degrees;
		degrees = normalize(rad);
		return degrees * (180 / M_PI);;
	}

	double convertToRadians(double degrees) {
		double rad;
		rad = degrees * M_PI / 180;
		rad = normalize(rad);
		return rad;
	}

};


