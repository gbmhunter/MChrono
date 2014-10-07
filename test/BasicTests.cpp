//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-19
//! @last-modified 	2014-10-08
//! @brief 			Contains basic tests.
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

	MTEST_GROUP(BasicTests)
	{

		MTEST(BasicTest1)
		{
			Utc myUtcTime;
			myUtcTime.year = 2014;
			myUtcTime.month = 6;
			myUtcTime.day = 12;
			myUtcTime.hour = 15;
			myUtcTime.minute = 6;
			myUtcTime.second = 56;

			int64_t unixTime = MChrono::UtcToUnix(&myUtcTime);

			// Make sure conversion to UNIX time is correct
			CHECK_EQUAL(unixTime, 1402585616);

		}

		MTEST(BasicTest2)
		{
			Utc myUtcTime;
			myUtcTime.year = 2014;
			myUtcTime.month = 1;
			myUtcTime.day = 1;
			myUtcTime.hour = 0;
			myUtcTime.minute = 0;
			myUtcTime.second = 0;

			int64_t unixTime = MChrono::UtcToUnix(&myUtcTime);

			// Make sure conversion to UNIX time is correct
			CHECK_EQUAL(unixTime, 1388534400);

		}

		MTEST(BasicTest3)
		{
			Utc myUtcTime;
			myUtcTime.year = 2098;
			myUtcTime.month = 1;
			myUtcTime.day = 1;
			myUtcTime.hour = 0;
			myUtcTime.minute = 0;
			myUtcTime.second = 0;

			int64_t unixTime = MChrono::UtcToUnix(&myUtcTime);

			// Make sure conversion to UNIX time is correct
			CHECK_EQUAL(unixTime, 4039372800);

		}
	}

} // namespace MChronoTestsNs
