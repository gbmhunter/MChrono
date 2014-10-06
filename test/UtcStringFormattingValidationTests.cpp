//!
//! @file 			UtcStringFormattingValidationTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-26
//! @last-modified 	2014-10-07
//! @brief 			Makes sure that the Validate() method on a UTC string works o.k.
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

	MTEST_GROUP(UtcStringFormattingValidationTests)
	{

		MTEST(UtcValidTest)
		{
			// Make sure valid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("2014-09-26 15:22:33"), true);
		}

		MTEST(UtcValidCrazyHighYearTest)
		{
			// Make sure valid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("9999-09-26 15:22:33"), true);
		}

		MTEST(UtcInvalidTest1)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("2014 09-26 15:22:33"), false);
		}

		MTEST(UtcInvalidTest2)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("2014-09-2615:22:33"), false);
		}

		MTEST(UtcInvalidTest3)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("26-09-2014 15:22:33"), false);
		}

		MTEST(UtcInvalidTest4)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("2014-09-26 15:22:33 "), false);
		}

		MTEST(UtcInvalidTest5)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString(""), false);
		}

		MTEST(UtcInvalidTest6)
		{
			// Make sure invalid UTC string is recognised correctly
			CHECK_EQUAL(Utc::ValidateString("abc"), false);
		}

		MTEST(UtcInvalidTest7)
		{
			// Make sure invalid UTC string is recognised correctly
			// (not allowed forward slashes, have to be hyphens)
			CHECK_EQUAL(Utc::ValidateString("2014/09/26 15:22:33"), false);
		}

	} // MTEST_GROUP(UtcStringFormattingValidationTests)

} // namespace MChronoTestsNs
