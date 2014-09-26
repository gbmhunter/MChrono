=======
MChrono
=======

---------------------------------------------------------------------------------------------
A microcontroller friendly C++ timekeeping module.
---------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MChrono.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MChrono

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-09-19
- Last Modified: 2014-09-26
- Version: v1.3.0.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

A microcontroller friendly C++ timekeeping module.

Features:

- Embedded (microcontroller) support
- Unit tests
- Doxygen-style well-documented API.
- Portability
	

Dependencies
============

The following table lists all of MChrono's dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<stdint.h>             Standard C library.  Fixed-width integers such as uint8_t, uint32_t, e.t.c
<cstdlib>              Standard C library.  Converting from strings to integers (strtoul()).
<cctype>               Standard C library.  Checking whether a particular ASCII character is a digit (isdigit()).
<cstring>              Standard C library.  Finding the length of strings (strlen()).
MString                External repo        For clear and safe decoding of UTC strings into a UTC object.
MUnitTest              External repo        Unit test framework. NOTE: Not required for normal use, only for running unit tests!
====================== ==================== ======================================================================

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== ===================================================================================================
Version   Date       Comment
========= ========== ===================================================================================================
v1.3.0.0  2014-09-26 Wrapped all MChrono objects in the MChrono namespace, closes #5. Moved classes in 'MChrono.hpp' into their own files, closes #6. Added C standard library dependencies to the README. Added 'MChrono::IsLeapYear()' method, closes #7. Added ability to decode UTC string into a UTC object, closes #4.
v1.2.0.0  2014-09-26 Made logic aware of the divisible by 100/400 leap year rule (in where 2100 will not be a leap year, 2400 will e.t.c), and added appropriate unit tests, closes #3.
v1.1.0.0  2014-09-20 Added 'UtcTime' object and 'MChrono::UtcToUnix()' method with one unit test, closes #1, closes #2.
v1.0.0.0  2014-09-19 Initial commit. No actual code added to repo yet, just skeleton files.
========= ========== ===================================================================================================