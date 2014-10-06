//!
//! @file				TimeConstants.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-26
//! @last-modified		2014-10-07
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MCHRONO_TIME_CONSTANTS_H
#define MCHRONO_TIME_CONSTANTS_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	// No forward declarations needed
	// here
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
//#include <iostream>

//===== USER SOURCE =====//
#include "./Utc.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MChronoNs
	{

		constexpr uint8_t numDaysInMonthWhenInNormalYear[] =
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

		constexpr uint8_t numDaysInMonthWhenInLeapYear[] =
		{
			31, // Janurary
			29, // February (this is the only number that changes)
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

		constexpr uint8_t numMonthsInYear = 12;
		constexpr uint16_t daysInNonLeapYear = 365;
		constexpr uint16_t daysInLeapYear = 366;
		constexpr uint8_t numHoursInDay = 24;
		constexpr uint8_t numMinsInHour = 60;

		//! @brief		The number of seconds in a normal minute (one which hasn't had a leap second added to or removed from).
		constexpr uint8_t numSecsInNormalMin = 60;

		//! @brief		This is to account for minutes which could have leap seconds added to them.
		constexpr uint8_t maxNumSecsInAnyMin = 61;

	} // namespace MChronoNs
} // namespace MbeddedNinja

#endif	// #ifndef MCHRONO_TIME_CONSTANTS_H

// EOF
