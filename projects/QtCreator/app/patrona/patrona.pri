########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: patrona.pri
#
# Author: $author$
#   Date: 3/23/2018
#
# QtCreator .pri file for patrona executable patrona
########################################################################

########################################################################
# patrona

# patrona_exe TARGET
#
patrona_exe_TARGET = patrona

# patrona_exe INCLUDEPATH
#
patrona_exe_INCLUDEPATH += \
$${patrona_INCLUDEPATH} \

# patrona_exe DEFINES
#
patrona_exe_DEFINES += \
$${patrona_DEFINES} \
USE_NADIR_LOGGER \

########################################################################
# patrona_exe OBJECTIVE_HEADERS
#
#patrona_exe_OBJECTIVE_HEADERS += \
#$${PATRONA_SRC}/patrona/base/Base.hh \

# patrona_exe OBJECTIVE_SOURCES
#
#patrona_exe_OBJECTIVE_SOURCES += \
#$${PATRONA_SRC}/patrona/base/Base.mm \

########################################################################
# patrona_exe HEADERS
#
patrona_exe_HEADERS += \
$${PATRONA_SRC}/patrona/cpp/xos/console/Main_main.hpp \

# patrona_exe SOURCES
#
patrona_exe_SOURCES += \
$${PATRONA_SRC}/patrona/cpp/xos/console/Main_main.cpp \

########################################################################
# patrona_exe FRAMEWORKS
#
patrona_exe_FRAMEWORKS += \
$${patrona_FRAMEWORKS} \

# patrona_exe LIBS
#
patrona_exe_LIBS += \
$${patrona_LIBS} \


