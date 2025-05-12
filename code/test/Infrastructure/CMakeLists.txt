add_executable(ServiceProviderTest ServiceProviderTest.cpp)
target_link_libraries(ServiceProviderTest PRIVATE gtest::gtest lib${PROJECT_NAME})
