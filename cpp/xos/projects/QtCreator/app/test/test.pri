########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: test.pri
#
# Author: $author$
#   Date: 8/2/2017
########################################################################

test_TARGET = test

test_INCLUDEPATH += \
$${patrona_INCLUDEPATH} \

test_DEFINES += \
$${patrona_DEFINES} \

########################################################################
# nadir
test_HEADERS += \
$${NADIR_SRC}/xos/base/std/String.hpp \
$${NADIR_SRC}/xos/base/String.hpp \
$${NADIR_SRC}/xos/base/std/StringBase.hpp \
$${NADIR_SRC}/xos/base/StringBase.hpp \
$${NADIR_SRC}/xos/base/CharsBase.hpp \
$${NADIR_SRC}/xos/base/Base.hpp \
$${NADIR_SRC}/xos/console/IO.hpp \
$${NADIR_SRC}/xos/console/Main.hpp \
$${NADIR_SRC}/xos/console/Main_main.hpp \

test_SOURCES += \
$${NADIR_SRC}/xos/base/String.cpp \
$${NADIR_SRC}/xos/base/StringBase.cpp \
$${NADIR_SRC}/xos/base/CharsBase.cpp \
$${NADIR_SRC}/xos/base/Base.cpp \
$${NADIR_SRC}/xos/console/IO.cpp \
$${NADIR_SRC}/xos/console/Main_main.cpp \

_test_SOURCES += \
$${NADIR_SRC}/xos/console/Main.cpp \

########################################################################
# patrona
test_HEADERS += \
$${PATRONA_SRC}/xos/base/Attached.hpp \
$${PATRONA_SRC}/xos/app/console/hello/Main.hpp \
$${PATRONA_SRC}/xos/app/console/hello/MainOpt.hpp \
$${PATRONA_SRC}/patrona/app/console/hello/Main.hpp \
$${PATRONA_SRC}/patrona/app/console/hello/MainOpt.hpp \

test_SOURCES += \
$${PATRONA_SRC}/xos/base/Attached.cpp \
$${PATRONA_SRC}/xos/app/console/hello/Main.cpp \
$${PATRONA_SRC}/xos/app/console/hello/MainOpt.cpp \

########################################################################
test_LIBS += \
$${patrona_LIBS} \
