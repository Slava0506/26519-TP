cmake_minimum_required(VERSION 3.12)
project(transporteUrbano)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(lib/googletest-master/googlemock/include)
include_directories(lib/googletest-master/googlemock/include/gmock)
include_directories(lib/googletest-master/googlemock/include/gmock/internal)
include_directories(lib/googletest-master/googlemock/include/gmock/internal/custom)
include_directories(lib/googletest-master/googlemock/test)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googletest/include/gtest)
include_directories(lib/googletest-master/googletest/include/gtest/internal)
include_directories(lib/googletest-master/googletest/include/gtest/internal/custom)
include_directories(lib/googletest-master/googletest/samples)
include_directories(lib/googletest-master/googletest/src)
include_directories(lib/googletest-master/googletest/test)
include_directories(lib/googletest-master/googletest/xcode/Samples/FrameworkSample)

add_executable(transporteUrbano
        lib/googletest-master/googlemock/include/gmock/internal/custom/gmock-generated-actions.h
        lib/googletest-master/googlemock/include/gmock/internal/custom/gmock-matchers.h
        lib/googletest-master/googlemock/include/gmock/internal/custom/gmock-port.h
        lib/googletest-master/googlemock/include/gmock/internal/gmock-generated-internal-utils.h
        lib/googletest-master/googlemock/include/gmock/internal/gmock-internal-utils.h
        lib/googletest-master/googlemock/include/gmock/internal/gmock-port.h
        lib/googletest-master/googlemock/include/gmock/gmock-actions.h
        lib/googletest-master/googlemock/include/gmock/gmock-cardinalities.h
        lib/googletest-master/googlemock/include/gmock/gmock-generated-actions.h
        lib/googletest-master/googlemock/include/gmock/gmock-generated-function-mockers.h
        lib/googletest-master/googlemock/include/gmock/gmock-generated-matchers.h
        lib/googletest-master/googlemock/include/gmock/gmock-generated-nice-strict.h
        lib/googletest-master/googlemock/include/gmock/gmock-matchers.h
        lib/googletest-master/googlemock/include/gmock/gmock-more-actions.h
        lib/googletest-master/googlemock/include/gmock/gmock-more-matchers.h
        lib/googletest-master/googlemock/include/gmock/gmock-spec-builders.h
        lib/googletest-master/googlemock/include/gmock/gmock.h
        lib/googletest-master/googlemock/src/gmock-all.cc
        lib/googletest-master/googlemock/src/gmock-cardinalities.cc
        lib/googletest-master/googlemock/src/gmock-internal-utils.cc
        lib/googletest-master/googlemock/src/gmock-matchers.cc
        lib/googletest-master/googlemock/src/gmock-spec-builders.cc
        lib/googletest-master/googlemock/src/gmock.cc
        lib/googletest-master/googlemock/src/gmock_main.cc
        lib/googletest-master/googlemock/test/gmock-actions_test.cc
        lib/googletest-master/googlemock/test/gmock-cardinalities_test.cc
        lib/googletest-master/googlemock/test/gmock-generated-actions_test.cc
        lib/googletest-master/googlemock/test/gmock-generated-function-mockers_test.cc
        lib/googletest-master/googlemock/test/gmock-generated-internal-utils_test.cc
        lib/googletest-master/googlemock/test/gmock-generated-matchers_test.cc
        lib/googletest-master/googlemock/test/gmock-internal-utils_test.cc
        lib/googletest-master/googlemock/test/gmock-matchers_test.cc
        lib/googletest-master/googlemock/test/gmock-more-actions_test.cc
        lib/googletest-master/googlemock/test/gmock-nice-strict_test.cc
        lib/googletest-master/googlemock/test/gmock-port_test.cc
        lib/googletest-master/googlemock/test/gmock-spec-builders_test.cc
        lib/googletest-master/googlemock/test/gmock_all_test.cc
        lib/googletest-master/googlemock/test/gmock_ex_test.cc
        lib/googletest-master/googlemock/test/gmock_leak_test_.cc
        lib/googletest-master/googlemock/test/gmock_link2_test.cc
        lib/googletest-master/googlemock/test/gmock_link_test.cc
        lib/googletest-master/googlemock/test/gmock_link_test.h
        lib/googletest-master/googlemock/test/gmock_output_test_.cc
        lib/googletest-master/googlemock/test/gmock_stress_test.cc
        lib/googletest-master/googlemock/test/gmock_test.cc
        lib/googletest-master/googletest/codegear/gtest_all.cc
        lib/googletest-master/googletest/codegear/gtest_link.cc
        lib/googletest-master/googletest/include/gtest/internal/custom/gtest-port.h
        lib/googletest-master/googletest/include/gtest/internal/custom/gtest-printers.h
        lib/googletest-master/googletest/include/gtest/internal/custom/gtest.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-death-test-internal.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-filepath.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-internal.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-linked_ptr.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-param-util-generated.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-param-util.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-port-arch.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-port.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-string.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-tuple.h
        lib/googletest-master/googletest/include/gtest/internal/gtest-type-util.h
        lib/googletest-master/googletest/include/gtest/gtest-death-test.h
        lib/googletest-master/googletest/include/gtest/gtest-message.h
        lib/googletest-master/googletest/include/gtest/gtest-param-test.h
        lib/googletest-master/googletest/include/gtest/gtest-printers.h
        lib/googletest-master/googletest/include/gtest/gtest-spi.h
        lib/googletest-master/googletest/include/gtest/gtest-test-part.h
        lib/googletest-master/googletest/include/gtest/gtest-typed-test.h
        lib/googletest-master/googletest/include/gtest/gtest.h
        lib/googletest-master/googletest/include/gtest/gtest_pred_impl.h
        lib/googletest-master/googletest/include/gtest/gtest_prod.h
        lib/googletest-master/googletest/samples/prime_tables.h
        lib/googletest-master/googletest/samples/sample1.cc
        lib/googletest-master/googletest/samples/sample1.h
        lib/googletest-master/googletest/samples/sample10_unittest.cc
        lib/googletest-master/googletest/samples/sample1_unittest.cc
        lib/googletest-master/googletest/samples/sample2.cc
        lib/googletest-master/googletest/samples/sample2.h
        lib/googletest-master/googletest/samples/sample2_unittest.cc
        lib/googletest-master/googletest/samples/sample3-inl.h
        lib/googletest-master/googletest/samples/sample3_unittest.cc
        lib/googletest-master/googletest/samples/sample4.cc
        lib/googletest-master/googletest/samples/sample4.h
        lib/googletest-master/googletest/samples/sample4_unittest.cc
        lib/googletest-master/googletest/samples/sample5_unittest.cc
        lib/googletest-master/googletest/samples/sample6_unittest.cc
        lib/googletest-master/googletest/samples/sample7_unittest.cc
        lib/googletest-master/googletest/samples/sample8_unittest.cc
        lib/googletest-master/googletest/samples/sample9_unittest.cc
        lib/googletest-master/googletest/src/gtest-all.cc
        lib/googletest-master/googletest/src/gtest-death-test.cc
        lib/googletest-master/googletest/src/gtest-filepath.cc
        lib/googletest-master/googletest/src/gtest-internal-inl.h
        lib/googletest-master/googletest/src/gtest-port.cc
        lib/googletest-master/googletest/src/gtest-printers.cc
        lib/googletest-master/googletest/src/gtest-test-part.cc
        lib/googletest-master/googletest/src/gtest-typed-test.cc
        lib/googletest-master/googletest/src/gtest.cc
        lib/googletest-master/googletest/src/gtest_main.cc
        lib/googletest-master/googletest/test/gtest-death-test_ex_test.cc
        lib/googletest-master/googletest/test/gtest-death-test_test.cc
        lib/googletest-master/googletest/test/gtest-filepath_test.cc
        lib/googletest-master/googletest/test/gtest-linked_ptr_test.cc
        lib/googletest-master/googletest/test/gtest-listener_test.cc
        lib/googletest-master/googletest/test/gtest-message_test.cc
        lib/googletest-master/googletest/test/gtest-options_test.cc
        lib/googletest-master/googletest/test/gtest-param-test2_test.cc
        lib/googletest-master/googletest/test/gtest-param-test_test.cc
        lib/googletest-master/googletest/test/gtest-param-test_test.h
        lib/googletest-master/googletest/test/gtest-port_test.cc
        lib/googletest-master/googletest/test/gtest-printers_test.cc
        lib/googletest-master/googletest/test/gtest-test-part_test.cc
        lib/googletest-master/googletest/test/gtest-tuple_test.cc
        lib/googletest-master/googletest/test/gtest-typed-test2_test.cc
        lib/googletest-master/googletest/test/gtest-typed-test_test.cc
        lib/googletest-master/googletest/test/gtest-typed-test_test.h
        lib/googletest-master/googletest/test/gtest-unittest-api_test.cc
        lib/googletest-master/googletest/test/gtest_all_test.cc
        lib/googletest-master/googletest/test/gtest_break_on_failure_unittest_.cc
        lib/googletest-master/googletest/test/gtest_catch_exceptions_test_.cc
        lib/googletest-master/googletest/test/gtest_color_test_.cc
        lib/googletest-master/googletest/test/gtest_env_var_test_.cc
        lib/googletest-master/googletest/test/gtest_environment_test.cc
        lib/googletest-master/googletest/test/gtest_filter_unittest_.cc
        lib/googletest-master/googletest/test/gtest_help_test_.cc
        lib/googletest-master/googletest/test/gtest_list_tests_unittest_.cc
        lib/googletest-master/googletest/test/gtest_main_unittest.cc
        lib/googletest-master/googletest/test/gtest_no_test_unittest.cc
        lib/googletest-master/googletest/test/gtest_output_test_.cc
        lib/googletest-master/googletest/test/gtest_pred_impl_unittest.cc
        lib/googletest-master/googletest/test/gtest_premature_exit_test.cc
        lib/googletest-master/googletest/test/gtest_prod_test.cc
        lib/googletest-master/googletest/test/gtest_repeat_test.cc
        lib/googletest-master/googletest/test/gtest_shuffle_test_.cc
        lib/googletest-master/googletest/test/gtest_sole_header_test.cc
        lib/googletest-master/googletest/test/gtest_stress_test.cc
        lib/googletest-master/googletest/test/gtest_throw_on_failure_ex_test.cc
        lib/googletest-master/googletest/test/gtest_throw_on_failure_test_.cc
        lib/googletest-master/googletest/test/gtest_uninitialized_test_.cc
        lib/googletest-master/googletest/test/gtest_unittest.cc
        lib/googletest-master/googletest/test/gtest_xml_outfile1_test_.cc
        lib/googletest-master/googletest/test/gtest_xml_outfile2_test_.cc
        lib/googletest-master/googletest/test/gtest_xml_output_unittest_.cc
        lib/googletest-master/googletest/test/production.cc
        lib/googletest-master/googletest/test/production.h
        lib/googletest-master/googletest/xcode/Samples/FrameworkSample/widget.cc
        lib/googletest-master/googletest/xcode/Samples/FrameworkSample/widget.h
        lib/googletest-master/googletest/xcode/Samples/FrameworkSample/widget_test.cc
        tests/aPalabraTEST.cpp
        tests/cantidadDeSaltosTEST.cpp
        tests/completarHuecosTEST.cpp
        tests/construirGrillaTEST.cpp
        tests/distanciaAuxTEST.cpp
        tests/distanciaTotalTEST.cpp
        tests/excesoDeVelocidadTEST.cpp
        tests/flotaTEST.cpp
        tests/recorridoNoCubiertoTEST.cpp
        tests/tiempoTotalTEST.cpp
        auxiliares.cpp
        auxiliares.h
        definiciones.h
        ejemplos.h
        main.cpp
        solucion.cpp
        solucion.h)
