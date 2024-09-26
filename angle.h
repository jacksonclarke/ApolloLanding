/*************************************************************
 * 1. Name:
 *      Jackson Clarke and Tyler Phillips
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      Normalizing in radians was the worst because we weren't given a mathematical formula, and wasted a lot of time 
        troubleshooting and researching different trig formulas instead of learning C++ principles.
 * 5. How long did it take for you to complete the assignment?
 *      3 hours
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718
#define _USE_MATH_DEFINES // for M_PI

#include <iostream>  // for cout
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
	/************************************
	* Get Degrees
	* Recieves no paramenters.
	* Returns the value of radians as degrees, normalized.
	************************************/
	double getDegrees() 
	{
		return convertToDegrees(radians);
	}

	/************************************
	* Get Radians
	* Recieves no paramenters.
	* Returns the value of radians.
	************************************/
	double getRadians() 
	{
		return radians;
	}

	/************************************
	* Set Degrees
	* Recieves the degrees as a double.
	* Converts degrees to normalized radians, and sets it as radians.
	* Returns nothing.
	************************************/
	void setDegrees(double degrees)
	{
		radians = normalize(convertToRadians(degrees));
	}

	/************************************
	* Set Radians
	* Recieves the radians as a double, normalizes it, and sets it as radians.
	* Returns nothing.
	************************************/
	void setRadians(double rad)
	{
		radians = normalize(rad);
	}

	/************************************
	* Display
	* Prints the radians in the form of degrees to the out iostream, followed by "degrees".
	* Returns nothing.
	************************************/
	void display(ostream& out)
	{
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);         // Set the precision to 1 decimal place of accuracy
		out << convertToDegrees(radians) << "degrees";
	}

private:
	/************************************
	* Normalize
	* Recieves some amount of radians as a double.
	* Truncates the radian value and expresses it in its simplest form. (0 < x < 2pi)
	* Returns the normalized radians.
	************************************/
	double normalize(double rad)
	{
		rad = fmod(rad, TWO_PI); // Sets rad as the remainder of radians / 2pi, which can be positive or negative.
		if (rad < 0) 
			rad = rad + TWO_PI; // Makes negative radians positive while preserving their position on the unit circle.
		return rad;
	}

	/************************************
	* Radians to Degrees
	* Recieves some amount of radians as a double.
	* Normalizes the radians and multiplies them by 180 / pi to get degrees.
	* Returns the normalized degrees.
	************************************/
	double convertToDegrees(double rad)
	{
		double degrees;
		degrees = normalize(rad);
		return degrees * (180 / M_PI);
	}

	/************************************
	* Degrees to Radians
	* Recieves some amount of degrees as a double.
	* Multiplies it by pi / 180 to get radians and normalizes it.
	* Returns the normalized radians.
	************************************/
	double convertToRadians(double degrees)
	{
		double rad;
		rad = degrees * (M_PI / 180);
		rad = normalize(rad);
		return rad;
	}
};