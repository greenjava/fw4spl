fwLoadProperties()

find_package(CAMP QUIET REQUIRED)
if(NOT ANDROID)
    find_package(Boost QUIET COMPONENTS log log_setup filesystem REQUIRED)
endif()

fwForwardInclude(
    ${CAMP_INCLUDE_DIR}
)

if(NOT ANDROID)
    fwLink(
        ${CAMP_LIBRARIES}
        ${Boost_LOG_LIBRARY}
        ${Boost_LOG_SETUP_LIBRARY}
    )
else()
    fwLink(
        ${CAMP_LIBRARIES}
        log
    )
endif()

target_compile_definitions(${FWPROJECT_NAME} PRIVATE "-DCAMP_COMPILATION")
