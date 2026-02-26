/*
 * mathUtils.c
 *
 *  Created on: 10/02/2026
 *      Author: mr-chama
 */

double linear_interpolation(double xValues[], double yValues[], int numValues, double pointX, bool trim)
{
	if (trim)
	{
		if (pointX <= xValues[0]) return yValues[0];
		if (pointX >= xValues[numValues - 1]) return yValues[numValues - 1];
	}

	auto i = 0;
	double rst = 0;
	if (pointX <= xValues[0])
	{
		i = 0;
		auto t = (pointX - xValues[i]) / (xValues[i + 1] - xValues[i]);
		rst = yValues[i] * (1 - t) + yValues[i + 1] * t;
	}
	else if (pointX >= xValues[numValues - 1])
	{
		auto t = (pointX - xValues[numValues - 2]) / (xValues[numValues - 1] - xValues[numValues - 2]);
		rst = yValues[numValues - 2] * (1 - t) + yValues[numValues - 1] * t;
	}
	else
	{
		while (pointX >= xValues[i + 1]) i++;
		auto t = (pointX - xValues[i]) / (xValues[i + 1] - xValues[i]);
		rst = yValues[i] * (1 - t) + yValues[i + 1] * t;
	}

	return rst;

}
