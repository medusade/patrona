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
#   Date: 3/23/2018, 12/26/2020
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
XOS_DEFAULT_LOG_ERROR \

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
$${PATRONA_SRC}/patrona/base/Acquired.hpp \
$${PATRONA_SRC}/patrona/base/Array.hpp \
$${PATRONA_SRC}/patrona/base/Attached.hpp \
$${PATRONA_SRC}/patrona/base/Base.hpp \
$${PATRONA_SRC}/patrona/base/Chars.hpp \
$${PATRONA_SRC}/patrona/base/Created.hpp \
$${PATRONA_SRC}/patrona/base/Joined.hpp \
$${PATRONA_SRC}/patrona/base/Locked.hpp \
$${PATRONA_SRC}/patrona/base/Opened.hpp \
$${PATRONA_SRC}/patrona/base/Sleep.hpp \
$${PATRONA_SRC}/patrona/base/String.hpp \
$${PATRONA_SRC}/patrona/base/Waited.hpp \
\
$${PATRONA_SRC}/patrona/io/apple/osx/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/io/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/io/crt/file/Mode.hpp \
$${PATRONA_SRC}/patrona/io/crt/file/Reader.hpp \
$${PATRONA_SRC}/patrona/io/crt/file/Stream.hpp \
$${PATRONA_SRC}/patrona/io/crt/file/Writer.hpp \
$${PATRONA_SRC}/patrona/io/crt/Stream.hpp \
$${PATRONA_SRC}/patrona/io/Logger.hpp \
$${PATRONA_SRC}/patrona/io/microsoft/windows/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/io/os/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/io/os/Os.hpp \
$${PATRONA_SRC}/patrona/io/posix/crt/file/Attached.hpp \
$${PATRONA_SRC}/patrona/io/Reader.hpp \
$${PATRONA_SRC}/patrona/io/Stream.hpp \
$${PATRONA_SRC}/patrona/io/Writer.hpp \
$${PATRONA_SRC}/patrona/io/Writers.hpp \
\
$${PATRONA_SRC}/patrona/console/Argv.hpp \
$${PATRONA_SRC}/patrona/console/getopt/Main.hpp \
$${PATRONA_SRC}/patrona/console/getopt/MainOpt.hpp \
$${PATRONA_SRC}/patrona/console/IO.hpp \
$${PATRONA_SRC}/patrona/console/Main.hpp \
\
$${PATRONA_SRC}/patrona/lib/Version.hpp \
$${PATRONA_SRC}/patrona/lib/patrona/Version.hpp \

# libpatrona SOURCES
#
libpatrona_SOURCES += \
$${PATRONA_SRC}/patrona/base/Acquired.cpp \
$${PATRONA_SRC}/patrona/base/Array.cpp \
$${PATRONA_SRC}/patrona/base/Attached.cpp \
$${PATRONA_SRC}/patrona/base/Base.cpp \
$${PATRONA_SRC}/patrona/base/Chars.cpp \
$${PATRONA_SRC}/patrona/base/Created.cpp \
$${PATRONA_SRC}/patrona/base/Joined.cpp \
$${PATRONA_SRC}/patrona/base/Locked.cpp \
$${PATRONA_SRC}/patrona/base/Opened.cpp \
$${PATRONA_SRC}/patrona/base/Sleep.cpp \
$${PATRONA_SRC}/patrona/base/String.cpp \
$${PATRONA_SRC}/patrona/base/Waited.cpp \
\
$${PATRONA_SRC}/patrona/io/crt/file/Mode.cpp \
$${PATRONA_SRC}/patrona/io/crt/file/Reader.cpp \
$${PATRONA_SRC}/patrona/io/crt/file/Stream.cpp \
$${PATRONA_SRC}/patrona/io/crt/file/Writer.cpp \
$${PATRONA_SRC}/patrona/io/Writers.cpp \
$${PATRONA_SRC}/patrona/io/Logger.cpp \
\
$${PATRONA_SRC}/patrona/console/Argv.cpp \
$${PATRONA_SRC}/patrona/console/getopt/Main.cpp \
$${PATRONA_SRC}/patrona/console/getopt/MainOpt.cpp \
$${PATRONA_SRC}/patrona/console/IO.cpp \
\
$${PATRONA_SRC}/patrona/lib/patrona/Version.cpp \

########################################################################
