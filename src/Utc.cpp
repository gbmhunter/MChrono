//!
//! @file				Utc.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-26
//! @last-modified		2014-10-07
//! @brief				Definition of the UTC object used for time keeping.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif


//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <cstdlib>		// strtoul()
#include <cctype>		// isdigit()
#include <cstring>		// strlen()

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"
#include "MString/api/MStringApi.hpp"

//===== USER SOURCE =====//
#include "../include/Utc.hpp"
#include "../include/TimeConstants.hpp"
#include "../include/MChrono.hpp"

namespace MbeddedNinja
{
	namespace MChronoNs
	{
		
		void Utc::FromString(const char * utcString)
		{
			// We need to decode the string
			// which should be in the format 2014-09-19 04:34:56

			// Make sure UTC string is valid, if not,
			// raise an assert
			if(!Utc::ValidateString(utcString))
			{
				M_ASSERT_FAIL("%s", "UTC string not valid.");
				return;
			}

			// Create a string object for clear and safe manipulation
			MString inputString(utcString);

			// Normally just used for debugging purposes
			char * ptrToNextChar;

			// Need to convert year from string to uint16_t
			this->year = strtoul(inputString.cStr, &ptrToNextChar, 10);

			//std::cout << "Year String = '" << &(inputString.cStr[0]) << "'." << std::endl;
			//std::cout << "Year Int = '" << this->year << "'." << std::endl;
			//std::cout << "Ptr to next char = '" << ptrToNextChar << "'." << std::endl;

			this->month = strtoul(&(inputString.cStr[5]),  &ptrToNextChar, 10);
			this->day = strtoul(&(inputString.cStr[8]),  &ptrToNextChar, 10);

			this->hour = strtoul(&(inputString.cStr[11]),  &ptrToNextChar, 10);
			this->minute = strtoul(&(inputString.cStr[14]),  &ptrToNextChar, 10);
			this->second = strtoul(&(inputString.cStr[17]),  &ptrToNextChar, 10);

		}

		//! @brief		Validates a UTC time encoded in a string.
		//! @details	String must be in the UTC form "2014-09-19 04:34:56", with no extra characters (including white-space characters) on either side.
		//! @returns	True if string is a valid UTC time, otherwise false.
		bool Utc::ValidateString(const char * utcString)
		{
			// First of, make sure the string is the right length.
			// This also protects the proceeding code from accessing invalid
			// memory if the string is too short
			if(strlen(utcString) != lengthOfValidUtcString)
				return false;

			// Make sure first four characters are the year numbers
			uint8_t x = 0;

			// Make characters 1-4 are the year
			while(x < 4)
			{
				if(!isdigit(utcString[x++]))
				{
					return false;
				}
			}

			// The year can be any four-digit number, but we still need to convert to decimal
			// for when checking the day is within the valid range for the current month
			// (remember Feb has 29 days in a leap year)
			uint32_t year = strtoul(&utcString[0], nullptr, 10);

			// Make sure character 5 is a hyphen
			// (between the year and month)
			if(utcString[x++] != '-')
				return false;

			// Make characters 6-7 are the month
			while(x < 7)
			{
				if(!isdigit(utcString[x++]))
					return false;
			}

			// Check month is within valid range (1-12)
			uint32_t month = strtoul(&utcString[5], nullptr, 10);
			if(month < 1 || month > numMonthsInYear)
				return false;

			// Make sure character 8 is a hyphen
			// (between the month and day)
			if(utcString[x++] != '-')
				return false;

			// Make characters 9-10 are the day
			while(x < 10)
			{
				if(!isdigit(utcString[x++]))
					return false;
			}

			// Check day is within valid range
			// This is dependent on the year/month we have just worked out!
			// (year is important because Feb has 29 days in leap year)
			uint32_t day = strtoul(&utcString[8], nullptr, 10);
			if(MChrono::IsLeapYear(year))
			{
				if(day < 1 || day > numDaysInMonthWhenInLeapYear[month - 1])
					return false;
			}
			else
			{
				if(day < 1 || day > numDaysInMonthWhenInNormalYear[month - 1])
					return false;
			}

			// Make sure character 11 is a space
			// (between the date and the time of day)
			if(utcString[x++] != ' ')
				return false;

			// Make characters 12-13 are the hour
			while(x < 13)
			{
				if(!isdigit(utcString[x++]))
					return false;
			}

			// Check hour is within valid range
			uint32_t hour = strtoul(&utcString[11], nullptr, 10);
			if(hour >= numHoursInDay)
				return false;

			// Make sure character 14 is a colon
			// (between the hour and minute)
			if(utcString[x++] != ':')
				return false;

			// Make characters 15-16 are the minute
			while(x < 16)
			{
				if(!isdigit(utcString[x++]))
					return false;
			}

			// Check minute is within valid range
			uint32_t minute = strtoul(&utcString[14], nullptr, 10);
			if(minute >= numMinsInHour)
				return false;

			// Make sure character 17 is a colon
			// (between the minute and second)
			if(utcString[x++] != ':')
				return false;

			// Make characters 18-19 are the second
			while(x < 19)
			{
				if(!isdigit(utcString[x++]))
					return false;
			}

			// Check second is within valid range
			uint32_t second = strtoul(&utcString[17], nullptr, 10);
			if(second >= maxNumSecsInAnyMin)
				return false;

			// Make sure character 20 is a terminating null
			// (at the end of the UTC time string)
			if(utcString[x++] != '\0')
				return false;

			// If we get here, UTC time string is correct
			return true;

		}

	} // namespace MChronoNs
} // namespace MbeddedNinja


// EOF
