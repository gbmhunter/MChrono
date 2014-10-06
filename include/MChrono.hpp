//!
//! @file				MChrono.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-20
//! @last-modified		2014-10-07
//! @brief				Contains methods which are not attached to any other specific time-related class.
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
	namespace MChronoNs
	{
		class MChrono;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
//#include <iostream>

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

			//! @brief		Use this to determine if the specified year is a leap year.
			//! @details	Takes into account the 100/400 leap year rule (e.g. 2100 is not a leap year, but 2400 will be).
			//! @param[in]	year	The year you want to investigate.
			//! @returns	True if the provided year is a leap year, otherwise false.
			static bool IsLeapYear(uint16_t year);

			//! @brief		Converts UTC time to UNIX time.
			//! @param[in]	utcTime		The UTC time that you wish to convert to UNIX time.
			//! @returns	The UNIX time.
			static uint64_t UtcToUnix(Utc utcTime);

			//! @brief		Converts the specified year range into seconds, taking into account the entire first year but not the last year.
			//! @details	Takes into account leap years, but does not take into account leap seconds.
			//! @param[in]	startYear		The start year for the year range (inclusive).
			//! @param[in]	endYear			The end year for the year range (exclusive).
			//! @returns	The converted number of seconds.
			//! @warning	Does not take into account leap seconds.
			static uint64_t YearsToSecs(uint16_t startYear, uint16_t endYear);

			//! @brief		Converts the specified months range into seconds. Takes into account leap years, but does not take into account leap seconds.
			//! @param[in]		year		The year that the startMonth and endMonth are applicable too (we have to know the year because in a leap year February has 29 days).
			//! @param[in]		startMonth 	The 1-indexed start month to start counting from (inclusive).
			//! @param[in]		endMonth	The 1-indexed end month to stop counting at (exclusive).
			//! @returns	The converted number of seconds.
			//! @warning	Does not take into account leap seconds.
			static uint64_t MonthsToSecs(uint16_t year, uint16_t startMonth, uint16_t endMonth);

			//! @brief		Converts a specified number of days into normal seconds (does not take into account leap seconds).
			//! @param[in]	numDays			The number of days to convert into normal seconds.
			//! @returns	The converted number of seconds.
			//! @warning	Does not take into account leap seconds.
			static uint64_t DaysToSecs(uint8_t numDays);

			//! @brief		Converts a specified number of hours into normal seconds (does not take into account leap seconds).
			//! @param[in]	numHours		The number of hours to convert into normal seconds.
			//! @returns	The converted number of seconds.
			//! @warning	Does not take into account leap seconds.
			static uint64_t HoursToSecs(uint8_t numHours);

			//! @brief		Converts a specified number of minutes into normal seconds.
			//! @param[in]	numMins			The number of minutes to convert into normal seconds.
			//! @returns	The converted number of seconds.
			//! @warning	Does not take into account leap seconds.
			static uint64_t MinsToSecs(uint8_t numMins);

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
