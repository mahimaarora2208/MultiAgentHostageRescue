# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_MultiAngentHostageRescue_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED MultiAngentHostageRescue_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(MultiAngentHostageRescue_FOUND FALSE)
  elseif(NOT MultiAngentHostageRescue_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(MultiAngentHostageRescue_FOUND FALSE)
  endif()
  return()
endif()
set(_MultiAngentHostageRescue_CONFIG_INCLUDED TRUE)

# output package information
if(NOT MultiAngentHostageRescue_FIND_QUIETLY)
  message(STATUS "Found MultiAngentHostageRescue: 0.0.0 (${MultiAngentHostageRescue_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'MultiAngentHostageRescue' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${MultiAngentHostageRescue_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(MultiAngentHostageRescue_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${MultiAngentHostageRescue_DIR}/${_extra}")
endforeach()
