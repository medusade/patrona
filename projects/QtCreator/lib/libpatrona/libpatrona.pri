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
#   File: libpatrona.pri
#
# Author: $author$
#   Date: 3/23/2018
#
# QtCreator .pri file for patrona library libpatrona
########################################################################

########################################################################
# libpatrona

# libpatrona TARGET
#
libpatrona_TARGET = patrona
libpatrona_TEMPLATE = lib
libpatrona_CONFIG += staticlib

# libpatrona INCLUDEPATH
#
libpatrona_INCLUDEPATH += \
$${patrona_INCLUDEPATH} \

# libpatrona DEFINES
#
libpatrona_DEFINES += \
$${patrona_DEFINES} \

########################################################################
# libpatrona OBJECTIVE_HEADERS
#
#libpatrona_OBJECTIVE_HEADERS += \
#$${PATRONA_SRC}/patrona/base/Base.hh \

# libpatrona OBJECTIVE_SOURCES
#
#libpatrona_OBJECTIVE_SOURCES += \
#$${PATRONA_SRC}/patrona/base/Base.mm \

########################################################################
# libpatrona HEADERS
#
libpatrona_HEADERS += \
$${PATRONA_SRC}/patrona/cpp/xos/base/Acquired.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Array.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Base.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Chars.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Created.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Joined.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Locked.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Opened.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Sleep.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/String.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Waited.hpp \
\
$${PATRONA_SRC}/patrona/cpp/xos/io/apple/osx/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Mode.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Reader.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Stream.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Writer.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/Stream.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/Logger.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/microsoft/windows/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/os/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/os/Os.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/posix/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/Reader.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/Stream.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/Writer.hpp \
\
$${PATRONA_SRC}/patrona/cpp/xos/console/Argv.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/Main.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/MainOpt.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/IO.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/Main.hpp \

# libpatrona SOURCES
#
libpatrona_SOURCES += \
$${PATRONA_SRC}/patrona/cpp/xos/base/Acquired.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Array.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Attached.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Base.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Chars.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Created.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Joined.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Locked.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Opened.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Sleep.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/String.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Waited.cpp \
\
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Mode.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Reader.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Stream.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/crt/file/Writer.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/io/Logger.cpp \
\
$${PATRONA_SRC}/patrona/cpp/xos/console/Argv.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/Main.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/MainOpt.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/IO.cpp \

########################################################################
