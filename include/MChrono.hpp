//!
//! @file				MChrono.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-20
//! @last-modified		2014-09-20
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MCHRONO_MCHRONO_H
#define MCHRONO_MCHRONO_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{

}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===== USER SOURCE =====//
#include "./TimeConstants.hpp"
#include "./Utc.hpp"


//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MChronoNs
	{

		class MChrono
		{

			public:



			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//

			static bool IsLeapYear(uint16_t year)
			{
				// The following expression says, yes, this is a leap year, if:
				// the year is divisible by four AND
				// the year is NOT divisble by 100, unless it is also
				// divisble by 400. e.g. 2000 is a leap year, 2100 is not a leap year,
				// neither is 2200 or 2300, but 2400 is (400 year cycle).
				if((year % 4 == 0) && !((year % 100 == 0) && !(year % 400 == 0)))
					return true;
				else
					return false;
			}

			//! @brief		Converts UTC time to UNIX time.
			static uint64_t UtcToUnix(Utc utcTime)
			{
				// Find how many years from Epoch
				//uint16_t numYears = utcTime.year - epoch.year;
				//std::cout << "Num years = '" << numYears << "'." << std::endl;

				// Find num seconds to current year
				uint64_t numSecsToCurrYear = MChrono::YearsToSecs(epoch.year, utcTime.year);
				//std::cout << "Num secs to curr year = '" << numSecsToCurrYear << "'." << std::endl;


				uint64_t numSecsFromStartOfYearToCurrMonth =
						MChrono::MonthsToSecs(utcTime.year, 1, utcTime.month);
				//std::cout << "Num secs to curr month = '" << numSecsFromStartOfYearToCurrMonth << "'." << std::endl;

				// Do not include current day
				uint64_t numSecsFromStartOfMonthToCurrDay = MChrono::DaysToSecs(utcTime.day - 1);
				//std::cout << "Num secs to curr day = '" << numSecsFromStartOfMonthToCurrDay << "'." << std::endl;

				uint64_t numSecsFromStartOfDayToCurrHour = MChrono::HoursToSecs(utcTime.hour);

				uint64_t numSecsFromStartOfHourToCurrMin = MChrono::MinsToSecs(utcTime.minute);

				uint64_t numSecsFromStartOfMinToCurrSec = utcTime.second;

				uint64_t totalNumSecs =
					numSecsToCurrYear +
					numSecsFromStartOfYearToCurrMonth +
					numSecsFromStartOfMonthToCurrDay +
					numSecsFromStartOfDayToCurrHour +
					numSecsFromStartOfHourToCurrMin +
					numSecsFromStartOfMinToCurrSec;

				return totalNumSecs;
			}

			static uint64_t YearsToSecs(uint16_t startYear, uint16_t endYear)
			{
				// Find total number of years, leap and non-leap years
				uint16_t numYears = endYear - startYear;

				// Find out how many leap years in this range
				uint16_t numLeapYears = 0;
				for(uint16_t x = startYear; x < endYear; x++)
				{
					// The following expression says, yes, this is a leap year, if:
					// the year is divisible by four AND
					// the year is NOT divisble by 100, unless it is also
					// divisble by 400. e.g. 2000 is a leap year, 2100 is not a leap year,
					// neither is 2200 or 2300, but 2400 is (400 year cycle).
					if(MChrono::IsLeapYear(x))
					{
						numLeapYears++;
					}
					else
					{
						//std::cout << "Year '" << x << "' was not a leap year." << std::endl;
					}
				}

				//std::cout << "Total num leap years = '" << numLeapYears << "'." << std::endl;
				uint16_t numNonLeapYears = numYears - numLeapYears;

				// Find out how many days
				uint32_t numDays = numNonLeapYears * daysInNonLeapYear + numLeapYears * daysInLeapYear;
				//std::cout << "Num days = '" << numDays << "'." << std::endl;

				// Which is how many hours
				uint32_t numHours = numDays * numHoursInDay;
				//std::cout << "Num hours = '" << numHours << "'." << std::endl;

				// Which is how many mins
				uint32_t numMins = numHours * numMinsInHour;
				//std::cout << "Num mins = '" << numMins << "'." << std::endl;

				// Which is how many seconds
				uint64_t numSecs = numMins * numSecsInMin;
				//std::cout << "Num secs = '" << numSecs << "'." << std::endl;

				return numSecs;
			}

			//! @param[in]		year		The year that the startMonth and endMonth are applicable too (we have to know the year because in a leap year February has 29 days).
			//! @param[in]		startMonth 	The 1-indexed start month to start counting from (inclusive).
			//! @param[in]		endMonth	The 1-indexed end month to stop counting at (exclusive)
			static uint64_t MonthsToSecs(uint16_t year, uint16_t startMonth, uint16_t endMonth)
			{
				//std::cout << "MonthsToSeconds() called with startMonth = '" << startMonth <<
				//		" and endMonth = '" << endMonth << "'." << std::endl;

				uint32_t numDays= 0 ;

				if(MChrono::IsLeapYear(year))
				{
					for(uint8_t x = startMonth; x < endMonth; x++)
					{
						// Remember that array is 0-indexed hence the -1
						numDays += numDaysInMonthWhenInLeapYear[x-1];
					}
				}
				else // not in leap year
				{
					for(uint8_t x = startMonth; x < endMonth; x++)
					{
						// Remember that array is 0-indexed hence the -1
						numDays += numDaysInMonthWhenInNormalYear[x-1];
					}
				}

				uint64_t numSecs = numDays*numHoursInDay*numMinsInHour*numSecsInMin;

				//std::cout << "Num secs from start of month '" << startMonth <<
				//		"' to start of month '" << endMonth <<
				//		"' = '" << numSecs << "'." << std::endl;

				return numSecs;
			}

			static uint64_t DaysToSecs(uint8_t numDays)
			{
				uint64_t numSecs = numDays*numHoursInDay*numMinsInHour*numSecsInMin;

				return numSecs;
			}

			static uint64_t HoursToSecs(uint8_t numHours)
			{
				uint64_t numSecs = numHours*numMinsInHour*numSecsInMin;

				return numSecs;
			}

			static uint64_t MinsToSecs(uint8_t numMins)
			{
				uint64_t numSecs = numMins*numSecsInMin;

				return numSecs;
			}

			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//



			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//



			private:

				//======================================================================================//
				//=================================== PRIVATE METHODS ==================================//
				//======================================================================================//

				// none

				//======================================================================================//
				//================================== PRIVATE VARIABLES =================================//
				//======================================================================================//



			protected:

				//======================================================================================//
				//=================================== PROTECTED METHODS ================================//
				//======================================================================================//

				// none

				//======================================================================================//
				//================================== PROTECTED VARIABLES ===============================//
				//======================================================================================//

				// none
			
		}; // class MChrono

	} // namespace MChronoNs
} // namespace MbeddedNinja

#endif	// #ifndef MCHRONO_MCHRONO_H

// EOF
