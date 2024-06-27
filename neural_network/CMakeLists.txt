cmake_minimum_required ( VERSION 3.5 )

project ( "neural_network" )

set ( SOURCE_FILES main.cpp matrix.cpp )
add_executable ( ${PROJECT_NAME} ${SOURCE_FILES} )