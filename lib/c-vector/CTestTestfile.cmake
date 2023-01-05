# CMake generated Testfile for 
# Source directory: /home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500
# Build directory: /home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-c-vector "/home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500/test-c-vector")
set_tests_properties(test-c-vector PROPERTIES  FIXTURES_REQUIRED "test_fixture")
add_test(test_build "/usr/bin/cmake" "--build" "/home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500" "--config" "$<CONFIG>" "--target" "test-c-vector")
set_tests_properties(test_build PROPERTIES  FIXTURES_SETUP "test_fixture")
add_test(unit-tests "/home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500/unit-tests")
set_tests_properties(unit-tests PROPERTIES  FIXTURES_REQUIRED "test_fixture")
add_test(unit_test_build "/usr/bin/cmake" "--build" "/home/zr/c_c++/c-vector-f96d57b1fb52e50cb97e08b78f714e46b2d88500" "--config" "$<CONFIG>" "--target" "unit-tests")
set_tests_properties(unit_test_build PROPERTIES  FIXTURES_SETUP "test_fixture")
