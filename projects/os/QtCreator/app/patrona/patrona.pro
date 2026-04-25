########################################################################
# Copyright (c) 1988-2024 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: patrona.pro
#
# Author: $author$
#   Date: 2/27/2024
#
# os specific QtCreator project .pro file for medusade framework patrona executable patrona
########################################################################
# Depends: rostra;nadir;fila;crono
#
# Debug: patrona/build/os/QtCreator/Debug/bin/patrona
# Release: patrona/build/os/QtCreator/Release/bin/patrona
# Profile: patrona/build/os/QtCreator/Profile/bin/patrona
#
include(../../../../../build/QtCreator/patrona.pri)
include(../../../../QtCreator/patrona.pri)
include(../../patrona.pri)
include(../../../../QtCreator/app/patrona/patrona.pri)

TARGET = $${patrona_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${patrona_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${patrona_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${patrona_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${patrona_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${patrona_exe_HEADERS} \
$${patrona_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${patrona_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${patrona_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${patrona_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################
