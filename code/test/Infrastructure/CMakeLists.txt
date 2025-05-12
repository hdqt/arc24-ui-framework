add_executable(ServiceProviderTest ServiceProviderTest.cpp)
target_link_libraries(ServiceProviderTest PRIVATE lib${PROJECT_NAME}-gmock)
