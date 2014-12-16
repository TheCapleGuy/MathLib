#include "math.h"
#include "MathLib.h"

float MiscMath::degreesToRadians(float angleInDegs) 
{ 
	return (angleInDegs * M_PI) / 180; 
}

float MiscMath::radiansToDegrees(float angleInRads) 
{
	return (angleInRads * 180) / M_PI; 
}

bool MiscMath::CheckPowerOfTwo(unsigned int ScalarValue)
{
	if ((ScalarValue & 1) == 0 && ScalarValue > 1)
	{
		if ((ScalarValue != 0) && !(ScalarValue & (ScalarValue - 1)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

unsigned int MiscMath::ShiftingPowerOfTwo(unsigned int ScalarValue)
{
	if (CheckPowerOfTwo(ScalarValue) != true)
	{
		ScalarValue--;
		ScalarValue|= ScalarValue>> 1;
		ScalarValue|= ScalarValue>> 2;
		ScalarValue|= ScalarValue>> 4;
		ScalarValue|= ScalarValue>> 8;
		ScalarValue|= ScalarValue>> 16;
		ScalarValue++;
		return ScalarValue;
	}
	else
	{
		return ScalarValue;
	}
}