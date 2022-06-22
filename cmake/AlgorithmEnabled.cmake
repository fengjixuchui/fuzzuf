function(algorithm_enabled ret algs name )
  list( FIND algs "${name}" alg_index )
  if( NOT "${alg_index}" EQUAL "-1" )
    set( ${ret} TRUE PARENT_SCOPE )
  else()
    set( ${ret} FALSE PARENT_SCOPE )
  endif()
endfunction()

function(algorithm_depends_on ret alg library )
  execute_process(
    COMMAND ${CMAKE_SOURCE_DIR}/check/depend.sh ${CMAKE_SOURCE_DIR}/algorithms/${alg} ${library}
    RESULT_VARIABLE has_dependency
  )
  if( "${has_dependency}" EQUAL "0" )
    set( ${ret} TRUE PARENT_SCOPE )
  else()
    set( ${ret} FALSE PARENT_SCOPE )
  endif()
endfunction()

function(algoriths_depend_on ret algs library )
  foreach( alg ${algs} )
    algorithm_depends_on( has_dependency ${alg} ${library} )
    if( has_dependency )
      set( ${ret} TRUE PARENT_SCOPE )
      return()
    endif()
  endforeach()
  set( ${ret} FALSE PARENT_SCOPE )
endfunction()

function(afl_common_is_required ret algs )
  algoriths_depend_on( has_dependency "${algs}" fuzzuf_core_afl_common )
  if( has_dependency )
    set( ${ret} TRUE PARENT_SCOPE )
  else()
    algorithm_enabled( has_python_binding "${algs}" python )
    if( has_python_binding )
      set( ${ret} TRUE PARENT_SCOPE )
    else()
      set( ${ret} FALSE PARENT_SCOPE )
    endif()
  endif()
endfunction()
function(libfuzzer_common_is_required ret algs )
  algoriths_depend_on( has_dependency "${algs}" fuzzuf_core_libfuzzer_common )
  if( has_dependency )
    set( ${ret} TRUE PARENT_SCOPE )
  else()
    set( ${ret} FALSE PARENT_SCOPE )
  endif()
endfunction()

