//!
//! @file 			UtcStringRangeValidationTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-26
//! @last-modified 	2014-10-07
//! @brief 			Makes sure that the date ranges passed to Validate() method validate correctly.
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

	MTEST_GROUP(UtcStringRangeValidationTests)
	{

		MTEST(UtcRangeValidTest1)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-09-26 15:22:33"), true);
		}

		MTEST(HighestValidUtcTest2)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("9999-12-31 23:59:60"), true);
		}

		MTEST(LowestValidUtcTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("0000-01-01 00:00:00"), true);
		}

		MTEST(UtcMonthInValidTest1)
		{
			// Month is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-00-26 15:22:33"), false);
		}

		MTEST(UtcMonthInValidTest2)
		{
			// Month is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-13-26 15:22:33"), false);
		}

		MTEST(UtcDayInValidTest1)
		{
			// Day is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-00 15:22:33"), false);
		}

		MTEST(UtcDayInValidTest2)
		{
			// Day is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-32 15:22:33"), false);
		}

		MTEST(UtcHourInValidTest)
		{
			// Hour is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-12 24:22:33"), false);
		}

		MTEST(UtcMinuteInValidTest)
		{
			// Minute is not in valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-15 00:60:33"), false);
		}

		MTEST(UtcSecondValidTest)
		{
			// Second is in valid range, remember second can go to 60 to
			// allow for leap seconds
			CHECK_EQUAL(Utc::ValidateString("2014-02-08 02:03:60"), true);
		}

		MTEST(UtcSecondInValidTest)
		{
			// Second is not in valid range, remember second can go to 60 to
			// allow for leap seconds
			CHECK_EQUAL(Utc::ValidateString("2014-02-04 02:03:61"), false);
		}


	} // MTEST_GROUP(UtcStringRangeValidationTests)

} // namespace MChronoTestsNs
