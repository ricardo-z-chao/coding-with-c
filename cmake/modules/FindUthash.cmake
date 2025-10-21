# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
FindUthash
-------

Finds the Uthash library.

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``Uthash_FOUND``
  True if the system has the Uthash library.
``Uthash_INCLUDE_DIRS``
  Include directories needed to use Uthash.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``Uthash_INCLUDE_DIR``
  The directory containing ``uthash.h``.

#]=======================================================================]

find_path(
  Uthash_INCLUDE_DIR
  NAMES uthash.h
  PATHS ${CMAKE_BINARY_DIR}/_deps
  PATH_SUFFIXES uthash-src/src
  NO_DEFAULT_PATH)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Uthash REQUIRED_VARS Uthash_INCLUDE_DIR)

if(Uthash_FOUND)
  set(Uthash_INCLUDE_DIRS ${Uthash_INCLUDE_DIR})
  if(NOT TARGET Uthash)
    add_library(Uthash INTERFACE IMPORTED)
    target_include_directories(Uthash INTERFACE "${Uthash_INCLUDE_DIRS}")
  endif()
endif()
