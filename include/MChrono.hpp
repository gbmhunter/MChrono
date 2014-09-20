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
#include <cstdint>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	constexpr uint8_t daysInMonth[] =
	{
		31, // Janurary
		28, // February
		31, // March
		30, // April
		31, // May
		30, // June
		31, // July
		31, // August
		30, // September
		31, // October
		30, // November
		31, // December
	};

	constexpr uint16_t daysInNonLeapYear = 365;
	constexpr uint16_t daysInLeapYear = 366;
	constexpr uint8_t numHoursInDay = 24;
	constexpr uint8_t numMinsInHour = 60;
	constexpr uint8_t numSecsInMin = 60;

	class UtcTime
	{
	public:

		uint16_t year;
		uint8_t month;
		uint8_t day;
		uint8_t hour;
		uint8_t minute;
		uint8_t second;

	};

	constexpr UtcTime epoch =
	{
			1970,
			1,
			1,
			0,
			0,
			0
	};




	class MChrono
	{	
		
		public:



		//======================================================================================//
		//==================================== PUBLIC METHODS ==================================//
		//======================================================================================//
					
		//! @brief		Converts UTC time to UNIX time.
		static uint64_t UtcToUnix(UtcTime utcTime)
		{
			// Find how many years from Epoch
			uint16_t numYears = utcTime.year - epoch.year;
			std::cout << "Num years = '" << numYears << "'." << std::endl;

			// Find num seconds to current year
			uint64_t numSecsToCurrYear = MChrono::YearsToSecs(epoch.year, utcTime.year);
			std::cout << "Num secs to curr year = '" << numSecsToCurrYear << "'." << std::endl;


			uint64_t numSecsFromStartOfYearToCurrMonth = MChrono::MonthsToSecs(1, utcTime.month);
			std::cout << "Num secs to curr month = '" << numSecsFromStartOfYearToCurrMonth << "'." << std::endl;

			// Do not include current day
			uint64_t numSecsFromStartOfMonthToCurrDay = MChrono::DaysToSecs(utcTime.day - 1);
			std::cout << "Num secs to curr day = '" << numSecsFromStartOfMonthToCurrDay << "'." << std::endl;

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
				if(x % 4 == 0)
				{
					std::cout << "Year '" << x << "' was a leap year." << std::endl;
					numLeapYears++;
				}
				else
					std::cout << "Year '" << x << "' was not a leap year." << std::endl;
			}

			std::cout << "Total num leap years = '" << numLeapYears << "'." << std::endl;
			uint16_t numNonLeapYears = numYears - numLeapYears;

			// Find out how many days
			uint32_t numDays = numNonLeapYears * daysInNonLeapYear + numLeapYears * daysInLeapYear;
			std::cout << "Num days = '" << numDays << "'." << std::endl;

			// Which is how many hours
			uint32_t numHours = numDays * numHoursInDay;
			std::cout << "Num hours = '" << numHours << "'." << std::endl;

			// Which is how many mins
			uint32_t numMins = numHours * numMinsInHour;
			std::cout << "Num mins = '" << numMins << "'." << std::endl;

			// Which is how many seconds
			uint64_t numSecs = numMins * numSecsInMin;
			std::cout << "Num secs = '" << numSecs << "'." << std::endl;

			return numSecs;
		}

		//! @param [in]		startMonth 	The 1-indexed start month to start counting from (inclusive).
		//! @param [out]	endMonth	The 1-indexed end month to stop counting at (exclusive)
		static uint64_t MonthsToSecs(uint16_t startMonth, uint16_t endMonth)
		{
			std::cout << "MonthsToSeconds() called with startMonth = '" << startMonth <<
					" and endMonth = '" << endMonth << "'." << std::endl;

			uint32_t numDays= 0 ;
			for(uint8_t x = startMonth; x < endMonth; x++)
			{
				// Remember that array is 0-indexed hence the -1
				numDays += daysInMonth[x-1];
			}

			uint64_t numSecs = numDays*numHoursInDay*numMinsInHour*numSecsInMin;

			std::cout << "Num secs from start of month '" << startMonth <<
					"' to start of month '" << endMonth <<
					"' = '" << numSecs << "'." << std::endl;

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


} // namespace MbeddedNinja

#endif	// #ifndef MCHRONO_MCHRONO_H

// EOF
