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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/geom/Angle.o \
	${OBJECTDIR}/geom/CVector2D.o \
	${OBJECTDIR}/geom/Circle.o \
	${OBJECTDIR}/geom/CompoundObject.o \
	${OBJECTDIR}/geom/Ellipse.o \
	${OBJECTDIR}/geom/GeometricRelation.o \
	${OBJECTDIR}/geom/Line.o \
	${OBJECTDIR}/geom/Parser.o \
	${OBJECTDIR}/geom/Ring.o \
	${OBJECTDIR}/geom/Segment.o \
	${OBJECTDIR}/geom/SemiCircle.o \
	${OBJECTDIR}/geom/TestPhantom.o \
	${OBJECTDIR}/geom/io/svg/SvgDocument.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/report/ReportHelper.o \
	${OBJECTDIR}/report/chart/SvgChart.o \
	${OBJECTDIR}/rude/AbstractData.o \
	${OBJECTDIR}/rude/AbstractOrganiser.o \
	${OBJECTDIR}/rude/AbstractParser.o \
	${OBJECTDIR}/rude/AbstractWriter.o \
	${OBJECTDIR}/rude/Base64Encoder.o \
	${OBJECTDIR}/rude/Comment.o \
	${OBJECTDIR}/rude/ConfigImpl.o \
	${OBJECTDIR}/rude/DataLine.o \
	${OBJECTDIR}/rude/File.o \
	${OBJECTDIR}/rude/KeyValue.o \
	${OBJECTDIR}/rude/ParserJuly2004.o \
	${OBJECTDIR}/rude/RealOrganiser.o \
	${OBJECTDIR}/rude/Section.o \
	${OBJECTDIR}/rude/WhiteSpace.o \
	${OBJECTDIR}/rude/Writer.o \
	${OBJECTDIR}/rude/config.o \
	${OBJECTDIR}/simulation/Simulation.o \
	${OBJECTDIR}/sources/FanSource.o \
	${OBJECTDIR}/sources/SourceBase.o \
	${OBJECTDIR}/util/NumericComparator.o \
	${OBJECTDIR}/util/StringUtils.o \
	${OBJECTDIR}/util/SvgFile.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atten.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atten.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atten ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/geom/Angle.o: geom/Angle.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Angle.o geom/Angle.cpp

${OBJECTDIR}/geom/CVector2D.o: geom/CVector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/CVector2D.o geom/CVector2D.cpp

${OBJECTDIR}/geom/Circle.o: geom/Circle.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Circle.o geom/Circle.cpp

${OBJECTDIR}/geom/CompoundObject.o: geom/CompoundObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/CompoundObject.o geom/CompoundObject.cpp

${OBJECTDIR}/geom/Ellipse.o: geom/Ellipse.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Ellipse.o geom/Ellipse.cpp

${OBJECTDIR}/geom/GeometricRelation.o: geom/GeometricRelation.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/GeometricRelation.o geom/GeometricRelation.cpp

${OBJECTDIR}/geom/Line.o: geom/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Line.o geom/Line.cpp

${OBJECTDIR}/geom/Parser.o: geom/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Parser.o geom/Parser.cpp

${OBJECTDIR}/geom/Ring.o: geom/Ring.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Ring.o geom/Ring.cpp

${OBJECTDIR}/geom/Segment.o: geom/Segment.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/Segment.o geom/Segment.cpp

${OBJECTDIR}/geom/SemiCircle.o: geom/SemiCircle.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/SemiCircle.o geom/SemiCircle.cpp

${OBJECTDIR}/geom/TestPhantom.o: geom/TestPhantom.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/TestPhantom.o geom/TestPhantom.cpp

${OBJECTDIR}/geom/io/svg/SvgDocument.o: geom/io/svg/SvgDocument.cpp 
	${MKDIR} -p ${OBJECTDIR}/geom/io/svg
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geom/io/svg/SvgDocument.o geom/io/svg/SvgDocument.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/report/ReportHelper.o: report/ReportHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/report
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/report/ReportHelper.o report/ReportHelper.cpp

${OBJECTDIR}/report/chart/SvgChart.o: report/chart/SvgChart.cpp 
	${MKDIR} -p ${OBJECTDIR}/report/chart
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/report/chart/SvgChart.o report/chart/SvgChart.cpp

${OBJECTDIR}/rude/AbstractData.o: rude/AbstractData.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/AbstractData.o rude/AbstractData.cpp

${OBJECTDIR}/rude/AbstractOrganiser.o: rude/AbstractOrganiser.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/AbstractOrganiser.o rude/AbstractOrganiser.cpp

${OBJECTDIR}/rude/AbstractParser.o: rude/AbstractParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/AbstractParser.o rude/AbstractParser.cpp

${OBJECTDIR}/rude/AbstractWriter.o: rude/AbstractWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/AbstractWriter.o rude/AbstractWriter.cpp

${OBJECTDIR}/rude/Base64Encoder.o: rude/Base64Encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/Base64Encoder.o rude/Base64Encoder.cpp

${OBJECTDIR}/rude/Comment.o: rude/Comment.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/Comment.o rude/Comment.cpp

${OBJECTDIR}/rude/ConfigImpl.o: rude/ConfigImpl.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/ConfigImpl.o rude/ConfigImpl.cpp

${OBJECTDIR}/rude/DataLine.o: rude/DataLine.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/DataLine.o rude/DataLine.cpp

${OBJECTDIR}/rude/File.o: rude/File.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/File.o rude/File.cpp

${OBJECTDIR}/rude/KeyValue.o: rude/KeyValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/KeyValue.o rude/KeyValue.cpp

${OBJECTDIR}/rude/ParserJuly2004.o: rude/ParserJuly2004.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/ParserJuly2004.o rude/ParserJuly2004.cpp

${OBJECTDIR}/rude/RealOrganiser.o: rude/RealOrganiser.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/RealOrganiser.o rude/RealOrganiser.cpp

${OBJECTDIR}/rude/Section.o: rude/Section.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/Section.o rude/Section.cpp

${OBJECTDIR}/rude/WhiteSpace.o: rude/WhiteSpace.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/WhiteSpace.o rude/WhiteSpace.cpp

${OBJECTDIR}/rude/Writer.o: rude/Writer.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/Writer.o rude/Writer.cpp

${OBJECTDIR}/rude/config.o: rude/config.cpp 
	${MKDIR} -p ${OBJECTDIR}/rude
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rude/config.o rude/config.cpp

${OBJECTDIR}/simulation/Simulation.o: simulation/Simulation.cpp 
	${MKDIR} -p ${OBJECTDIR}/simulation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simulation/Simulation.o simulation/Simulation.cpp

${OBJECTDIR}/sources/FanSource.o: sources/FanSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/FanSource.o sources/FanSource.cpp

${OBJECTDIR}/sources/SourceBase.o: sources/SourceBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/SourceBase.o sources/SourceBase.cpp

${OBJECTDIR}/util/NumericComparator.o: util/NumericComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}/util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/util/NumericComparator.o util/NumericComparator.cpp

${OBJECTDIR}/util/StringUtils.o: util/StringUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/util/StringUtils.o util/StringUtils.cpp

${OBJECTDIR}/util/SvgFile.o: util/SvgFile.cpp 
	${MKDIR} -p ${OBJECTDIR}/util
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/util/SvgFile.o util/SvgFile.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atten.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
