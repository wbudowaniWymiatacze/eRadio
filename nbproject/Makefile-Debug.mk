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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o \
	${OBJECTDIR}/TcpIp/src/CTcpServer.o \
	${OBJECTDIR}/Http/src/CHttpClient.o \
	${OBJECTDIR}/Audio/src/CAudioHw.o \
	${OBJECTDIR}/LinuxImpl/RadioProtocol/File/src/CFileStrategy.o \
	${OBJECTDIR}/DataReceiver/src/CDataReceiver.o \
	${OBJECTDIR}/TcpIp/src/CTcpClient.o \
	${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Audio/src/CAudioOut.o: Audio/src/CAudioOut.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioOut.o Audio/src/CAudioOut.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o: RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/RadioProtocols/Shoutcast/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioProtocols/Shoutcast/src/CShoutcastStrategy.o RadioProtocols/Shoutcast/src/CShoutcastStrategy.cpp

${OBJECTDIR}/TcpIp/src/CTcpServer.o: TcpIp/src/CTcpServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpServer.o TcpIp/src/CTcpServer.cpp

${OBJECTDIR}/Http/src/CHttpClient.o: Http/src/CHttpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Http/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/Http/src/CHttpClient.o Http/src/CHttpClient.cpp

${OBJECTDIR}/Audio/src/CAudioHw.o: Audio/src/CAudioHw.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHw.o Audio/src/CAudioHw.cpp

${OBJECTDIR}/LinuxImpl/RadioProtocol/File/src/CFileStrategy.o: LinuxImpl/RadioProtocol/File/src/CFileStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/LinuxImpl/RadioProtocol/File/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/LinuxImpl/RadioProtocol/File/src/CFileStrategy.o LinuxImpl/RadioProtocol/File/src/CFileStrategy.cpp

${OBJECTDIR}/DataReceiver/src/CDataReceiver.o: DataReceiver/src/CDataReceiver.cpp 
	${MKDIR} -p ${OBJECTDIR}/DataReceiver/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataReceiver/src/CDataReceiver.o DataReceiver/src/CDataReceiver.cpp

${OBJECTDIR}/TcpIp/src/CTcpClient.o: TcpIp/src/CTcpClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/TcpIp/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/TcpIp/src/CTcpClient.o TcpIp/src/CTcpClient.cpp

${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o: Audio/src/CAudioHwNotConfigured.cpp 
	${MKDIR} -p ${OBJECTDIR}/Audio/src
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -IInterface/globalDefs -ITcpIp/inc -IRadioProtocols/inc -IHttp/inc -IRadioProtocols/Shoutcast/inc -IAudio/inc -ILinuxImpl/RadioProtocol/File/inc -ILinuxImpl/TcpIp/inc -IDataReceiver/inc -IInterface -MMD -MP -MF $@.d -o ${OBJECTDIR}/Audio/src/CAudioHwNotConfigured.o Audio/src/CAudioHwNotConfigured.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eradio

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
