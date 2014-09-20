//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-19
//! @last-modified 	2014-09-20
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

namespace MChronoTestsNs
{

	MTEST(BasicTest)
	{
		UtcTime myUtcTime;
		myUtcTime.year = 2014;
		myUtcTime.month = 6;
		myUtcTime.day = 12;
		myUtcTime.hour = 15;
		myUtcTime.minute = 6;
		myUtcTime.second = 56;

		uint64_t unixTime = MChrono::UtcToUnix(myUtcTime);

		// Make sure conversion to UNIX time is correct
		CHECK_EQUAL(unixTime, 1402585616);

	}


} // namespace MChronoTestsNs
