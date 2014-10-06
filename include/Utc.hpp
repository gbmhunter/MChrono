//!
//! @file				Utc.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-26
//! @last-modified		2014-10-07
//! @brief				Declaration of the UTC object used for time keeping.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MCHRONO_UTC_H
#define MCHRONO_UTC_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MChronoNs
	{
		class Utc;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <cstdlib>		// strtoul()
#include <cctype>		// isdigit()

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"
#include "MString/api/MStringApi.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MChronoNs
	{
		
		//! @brief		The Utc class encapsulated a UC time object and associated methods for manipulating the UTC time.
		class Utc
		{
			public:

			//! @brief		The length of a valid UTC string (excluding the terminating null character).
			//! @details	Used in ValidateString().
			static constexpr uint8_t lengthOfValidUtcString = 19;

			//! @brief		Converts a UTC time in string format to the current UTC object.
			//! @details	Raises an assert if the utcString is not a valid UTC time. This can be checked prior to calling this function with ValidateString().
			void FromString(const char * utcString);

			//! @brief		Validates a UTC time encoded in a string.
			//! @details	String must be in the UTC form "2014-09-19 04:34:56", with no extra characters (including white-space characters) on either side.
			//! @returns	True if string is a valid UTC time, otherwise false.
			static bool ValidateString(const char * utcString);

			uint16_t year;
			uint8_t month;
			uint8_t day;
			uint8_t hour;
			uint8_t minute;
			uint8_t second;

		};

		//! @brief		This is the definition of the Unix time Epoch as a UTC object.
		constexpr Utc epoch =
		{
				1970,
				1,
				1,
				0,
				0,
				0
		};

	} // namespace MChronoNs
} // namespace MbeddedNinja

#endif	// #ifndef MCHRONO_MCHRONO_H

// EOF
