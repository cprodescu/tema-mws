#
# Copyright (C) 2010-2013 KWARC Group <kwarc.info>
#
# This file is part of MathWebSearch.
#
# MathWebSearch is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MathWebSearch is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with MathWebSearch.  If not, see <http://www.gnu.org/licenses/>.
#
# MWS Modules
ADD_SUBDIRECTORY( daemon )              # mwsdaemon
ADD_SUBDIRECTORY( dbc )                 # mwsdbc
ADD_SUBDIRECTORY( index )               # mwsindex
ADD_SUBDIRECTORY( query )               # mwsquery
ADD_SUBDIRECTORY( types )               # mwstypes
ADD_SUBDIRECTORY( xmlparser )           # mwsxmlparser

# Main MWS executable
ADD_EXECUTABLE(mwsd mwsd.cpp)
TARGET_LINK_LIBRARIES(mwsd
        mwsdaemon
        commonutils
)

# Output executables at the root of build tree
SET_PROPERTY( TARGET mwsd
        PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
