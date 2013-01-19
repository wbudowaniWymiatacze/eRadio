#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Audio/src/CAudioOut.o \
	${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o \
	${OBJECTDIR}/TcpIp/src/CTcpServer.o \
	${OBJECTDIR}/Http/src/CHttpClient.o \
	${OBJECTDIR}/Audio/src/CAudioHw.o \
	${OBJECTDIR}/DataReceiver/src/CDataReceiver.o \
	${OBJECTDIR}/TcpIp/src/CTcpClient.o \
	${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o \
	${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-logg

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -Wl,-Map=eRadio.map -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Audio/src/CAudioOut.o: Audio/src/CAudioOut.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioOut.o Audio/src/CAudioOut.cpp

${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o: RadioProtocols/File/src/CFileStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/File/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o RadioProtocols/File/src/CFileStrategy.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o: RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/Shoutcast/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp

${OBJECTDIR}/TcpIp/src/CTcpServer.o: TcpIp/src/CTcpServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpServer.o TcpIp/src/CTcpServer.cpp

${OBJECTDIR}/Http/src/CHttpClient.o: Http/src/CHttpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Http/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/Http/src/CHttpClient.o Http/src/CHttpClient.cpp

${OBJECTDIR}/Audio/src/CAudioHw.o: Audio/src/CAudioHw.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHw.o Audio/src/CAudioHw.cpp

${OBJECTDIR}/DataReceiver/src/CDataReceiver.o: DataReceiver/src/CDataReceiver.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataReceiver/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataReceiver/src/CDataReceiver.o DataReceiver/src/CDataReceiver.cpp

${OBJECTDIR}/TcpIp/src/CTcpClient.o: TcpIp/src/CTcpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpClient.o TcpIp/src/CTcpClient.cpp

${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o: RadioProtocols/File/src/COggContainer.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/File/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o RadioProtocols/File/src/COggContainer.cpp

${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o: Audio/src/CAudioHwNotConfigured.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o Audio/src/CAudioHwNotConfigured.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/UnitTests/Interface/SCircBufferTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/UnitTests/Interface/SharedArrayTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/UnitTests/Interface/SharedPtrTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/UnitTests/Interface/SCircBufferTest.o: UnitTests/Interface/SCircBufferTest.cpp 
	${MKDIR} -p ${TESTDIR}/UnitTests/Interface
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I. -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${TESTDIR}/UnitTests/Interface/SCircBufferTest.o UnitTests/Interface/SCircBufferTest.cpp


${TESTDIR}/UnitTests/Interface/SharedArrayTest.o: UnitTests/Interface/SharedArrayTest.cpp 
	${MKDIR} -p ${TESTDIR}/UnitTests/Interface
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I. -I. -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${TESTDIR}/UnitTests/Interface/SharedArrayTest.o UnitTests/Interface/SharedArrayTest.cpp


${TESTDIR}/UnitTests/Interface/SharedPtrTest.o: UnitTests/Interface/SharedPtrTest.cpp 
	${MKDIR} -p ${TESTDIR}/UnitTests/Interface
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I. -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -MMD -MP -MF $@.d -o ${TESTDIR}/UnitTests/Interface/SharedPtrTest.o UnitTests/Interface/SharedPtrTest.cpp


${OBJECTDIR}/Audio/src/CAudioOut_nomain.o: ${OBJECTDIR}/Audio/src/CAudioOut.o Audio/src/CAudioOut.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Audio/src/CAudioOut.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioOut_nomain.o Audio/src/CAudioOut.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Audio/src/CAudioOut.o ${OBJECTDIR}/Audio/src/CAudioOut_nomain.o;\
	fi

${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy_nomain.o: ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o RadioProtocols/File/src/CFileStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/File/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy_nomain.o RadioProtocols/File/src/CFileStrategy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy.o ${OBJECTDIR}/RadioProtocols/File/src/CFileStrategy_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy_nomain.o: ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/Shoutcast/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy_nomain.o RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy_nomain.o;\
	fi

${OBJECTDIR}/TcpIp/src/CTcpServer_nomain.o: ${OBJECTDIR}/TcpIp/src/CTcpServer.o TcpIp/src/CTcpServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TcpIp/src/CTcpServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpServer_nomain.o TcpIp/src/CTcpServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TcpIp/src/CTcpServer.o ${OBJECTDIR}/TcpIp/src/CTcpServer_nomain.o;\
	fi

${OBJECTDIR}/Http/src/CHttpClient_nomain.o: ${OBJECTDIR}/Http/src/CHttpClient.o Http/src/CHttpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Http/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Http/src/CHttpClient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Http/src/CHttpClient_nomain.o Http/src/CHttpClient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Http/src/CHttpClient.o ${OBJECTDIR}/Http/src/CHttpClient_nomain.o;\
	fi

${OBJECTDIR}/Audio/src/CAudioHw_nomain.o: ${OBJECTDIR}/Audio/src/CAudioHw.o Audio/src/CAudioHw.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Audio/src/CAudioHw.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHw_nomain.o Audio/src/CAudioHw.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Audio/src/CAudioHw.o ${OBJECTDIR}/Audio/src/CAudioHw_nomain.o;\
	fi

${OBJECTDIR}/DataReceiver/src/CDataReceiver_nomain.o: ${OBJECTDIR}/DataReceiver/src/CDataReceiver.o DataReceiver/src/CDataReceiver.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataReceiver/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataReceiver/src/CDataReceiver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataReceiver/src/CDataReceiver_nomain.o DataReceiver/src/CDataReceiver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataReceiver/src/CDataReceiver.o ${OBJECTDIR}/DataReceiver/src/CDataReceiver_nomain.o;\
	fi

${OBJECTDIR}/TcpIp/src/CTcpClient_nomain.o: ${OBJECTDIR}/TcpIp/src/CTcpClient.o TcpIp/src/CTcpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TcpIp/src/CTcpClient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpClient_nomain.o TcpIp/src/CTcpClient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TcpIp/src/CTcpClient.o ${OBJECTDIR}/TcpIp/src/CTcpClient_nomain.o;\
	fi

${OBJECTDIR}/RadioProtocols/File/src/COggContainer_nomain.o: ${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o RadioProtocols/File/src/COggContainer.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/File/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/File/src/COggContainer_nomain.o RadioProtocols/File/src/COggContainer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RadioProtocols/File/src/COggContainer.o ${OBJECTDIR}/RadioProtocols/File/src/COggContainer_nomain.o;\
	fi

${OBJECTDIR}/Audio/src/CAudioHwNotConfigured_nomain.o: ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o Audio/src/CAudioHwNotConfigured.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -IDataReceiver/inc -IInterface -IRadioProtocols/File/inc -I../../programmingResources/boost_1_48_0/dist/bin/smart_ptrs -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured_nomain.o Audio/src/CAudioHwNotConfigured.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
