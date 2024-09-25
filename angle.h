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
	
	double getDegrees() 
	{
		return convertToDegrees(radians);
	}

	double getRadians() 
	{
		return radians;
	}

	void setDegrees(double degrees)
	{
		radians = normalize(convertToRadians(degrees));
	}

	void setRadians(double rad)
	{
		radians = normalize(rad);
	}

	void display(ostream& out)
	{
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);         // Set the precision to 1 decimal place of accuracy
		out << convertToDegrees(radians) << "degrees";
	}

private:

	double normalize(double rad)
	{
		rad = fmod(rad, TWO_PI);
		if (rad < 0)
			rad = rad + TWO_PI;
		return rad;
	}

	double convertToDegrees(double rad)
	{
		double degrees;
		degrees = normalize(rad);
		return degrees * (180 / M_PI);
	}

	double convertToRadians(double degrees)
	{
		double rad;
		rad = degrees * (M_PI / 180);
		rad = normalize(rad);
		return rad;
	}

};