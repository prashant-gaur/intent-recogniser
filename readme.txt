About
=============
This is a command line tool which will guess the intention from the user input.

Design
============
UML design doc location
docs/

Build
=============
Execute below commands sequentially like below,

:: to build
mkdir build && cd build && cmake ..  && make

:: to clean build
make clean && make

Tests
===============
unit-tests source code location
tests/

How to ??
=============
Run application. Punch in the keywords for different intentions.
For example.
For finding weather -> include weather or conjugated city as keyword in your query
For calendar -> include time format like 12:00 am/06:00PM
For curious/fun facts -> include "facts/fact" keyword in query