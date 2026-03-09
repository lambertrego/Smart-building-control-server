add_executable(UnitTests test_room.cpp)
target_link_libraries(UnitTests PRIVATE DomainLib gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)