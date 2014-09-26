//!
//! @file 			StringToUtcTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-26
//! @last-modified 	2014-09-26
//! @brief 			Makes sure that conversions from string to a UTC object work o.k.
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

	MTEST_GROUP(StringToUtcTests)
	{

		MTEST(YearTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure year is correct
			CHECK_EQUAL(myUtcTime.year, 2014);
		}

		MTEST(MonthTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure month is correct
			CHECK_EQUAL(myUtcTime.month, 9);
		}

		MTEST(DayTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure month is correct
			CHECK_EQUAL(myUtcTime.day, 26);
		}

		MTEST(HourTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure month is correct
			CHECK_EQUAL(myUtcTime.hour, 15);
		}

		MTEST(MinuteTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure month is correct
			CHECK_EQUAL(myUtcTime.minute, 22);
		}

		MTEST(SecondTest)
		{
			Utc myUtcTime;
			myUtcTime.FromString("2014-09-26 15:22:33");

			// Make sure month is correct
			CHECK_EQUAL(myUtcTime.second, 33);
		}

	}

} // namespace MChronoTestsNs
