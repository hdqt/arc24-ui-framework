set(TARGET_PUBLIC_SOURCES
    ./IDummy.hpp
    ./UIFramework/Infrastructure/ServiceProvider.hpp
)

if (BUILD_SHARED_LIBS)
    target_sources(${PROJECT_NAME} PRIVATE ${TARGET_PUBLIC_SOURCES})
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()

target_sources(lib${PROJECT_NAME} PRIVATE ${TARGET_PUBLIC_SOURCES})
target_include_directories(lib${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# if (BUILD_UNIT_TESTS)
#     target_include_directories(lib${PROJECT_NAME}-gmock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# endif()
