//!
//! @file 			UtcStringDaysInMonthValidationTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-07
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

	MTEST_GROUP(UtcStringDaysInMonthValidationTests)
	{

		MTEST(UtcJanValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-01-31 15:22:33"), true);
		}

		MTEST(UtcJanInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-01-32 15:22:33"), false);
		}

		MTEST(UtcFebValidInNormalYearTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-28 15:22:33"), true);
		}

		MTEST(UtcFebInvalidInNormalYearTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-02-29 15:22:33"), false);
		}

		MTEST(UtcFebValidInLeapYearTest1)
		{
			// Feb has 29 days in 2012 (leap year)
			CHECK_EQUAL(Utc::ValidateString("2012-02-29 15:22:33"), true);
		}

		MTEST(UtcFebInvalidInLeapYearTest1)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2012-02-30 15:22:33"), false);
		}

		MTEST(UtcFebValidInLeapYearTest2)
		{
			// Feb has 28 days in 2100 (not a leap year)
			CHECK_EQUAL(Utc::ValidateString("2100-02-28 15:22:33"), true);
		}

		MTEST(UtcFebInvalidInLeapYearTest2)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2100-02-29 15:22:33"), false);
		}

		MTEST(UtcFebValidInLeapYearTest3)
		{
			// Feb has 29 days in 2400 (leap year)
			CHECK_EQUAL(Utc::ValidateString("2400-02-29 15:22:33"), true);
		}

		MTEST(UtcFebInvalidInLeapYearTest3)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2400-02-30 15:22:33"), false);
		}

		MTEST(UtcMarchValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-03-31 15:22:33"), true);
		}

		MTEST(UtcMarchInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-03-32 15:22:33"), false);
		}

		MTEST(UtcAprilValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-04-30 15:22:33"), true);
		}

		MTEST(UtcAprilInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-04-31 15:22:33"), false);
		}

		MTEST(UtcMayValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-05-31 15:22:33"), true);
		}

		MTEST(UtcMayInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-05-32 15:22:33"), false);
		}

		MTEST(UtcJuneValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-06-30 15:22:33"), true);
		}

		MTEST(UtcJuneInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-06-31 15:22:33"), false);
		}

		MTEST(UtcJulyValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-07-31 15:22:33"), true);
		}

		MTEST(UtcJulyInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-07-32 15:22:33"), false);
		}

		MTEST(UtcAugustValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-08-31 15:22:33"), true);
		}

		MTEST(UtcAugustInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-08-32 15:22:33"), false);
		}

		MTEST(UtcSeptemberValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-09-30 15:22:33"), true);
		}

		MTEST(UtcSeptemberInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-09-31 15:22:33"), false);
		}

		MTEST(UtcOctoberValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-10-31 15:22:33"), true);
		}

		MTEST(UtcOctoberInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-10-32 15:22:33"), false);
		}

		MTEST(UtcNovemberValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-11-30 15:22:33"), true);
		}

		MTEST(UtcNovemberInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-11-31 15:22:33"), false);
		}

		MTEST(UtcDecemberValidTest)
		{
			// This is within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-12-31 15:22:33"), true);
		}

		MTEST(UtcDecemberInvalidTest)
		{
			// This is not within the valid range
			CHECK_EQUAL(Utc::ValidateString("2014-12-32 15:22:33"), false);
		}

	} // MTEST_GROUP(UtcStringDaysInMonthValidationTests)

} // namespace MChronoTestsNs
