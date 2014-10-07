//!
//! @file 			LeapYearTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-26
//! @last-modified 	2014-10-08
//! @brief 			Contains tests to make sure leap years are handled correctly in time conversions.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MChronoApi.hpp"

using namespace MbeddedNinja;
using namespace MChronoNs;

namespace MChronoTestsNs
{

	MTEST_GROUP(LeapYearTests)
	{
		MTEST(LeapYearTest1)
		{
			Utc myUtcTime;

			// This encompasses both the year 2000 (which is a leap year)
			// and the year 2100 (which isn't a leap year).
			myUtcTime.year = 2106;
			myUtcTime.month = 1;
			myUtcTime.day = 1;
			myUtcTime.hour = 0;
			myUtcTime.minute = 0;
			myUtcTime.second = 0;

			int64_t unixTime = MChrono::UtcToUnix(&myUtcTime);

			// Make sure conversion to UNIX time is correct

			CHECK_EQUAL(unixTime, 4291747200);

		}
	}

} // namespace MChronoTestsNs
