bin_PROGRAMS = webTest
# <binary_name>_LDADD is used to pass extra parameters at link time, such as
# libraries that need to be linked in.
webTest_LDADD = -lcurl


# <binary_name>_LDFLAGS is used to pass extra parameters at compilation time,
# such as the paths to libraries that are needed that are not in the default
# paths.
# If the user supplies a directory where libpcap is installed, the contents
# of the variable setup in configire.in will be substituted below so the
# library file will be found.
webTest_LDFLAGS =
# <binary_name>_SOURCES takes a space delimited list of the source code files
# that need to be compiled/linked to build the binary.
AM_CXXFLAGS = -std=c++17
webTest_SOURCES = main.cpp response.cpp get.cpp
AM_CPPFLAGS = -I../include