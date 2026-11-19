target_sources(raytracer_tests PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/test_helpers.cpp
    ${CMAKE_CURRENT_LIST_DIR}/math/test_vector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/colour/test_colour.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ray/test_ray.cpp
    ${CMAKE_CURRENT_LIST_DIR}/geometry/test_sphere.cpp
    ${CMAKE_CURRENT_LIST_DIR}/render/test_camera.cpp
    ${CMAKE_CURRENT_LIST_DIR}/render/test_trace.cpp
    ${CMAKE_CURRENT_LIST_DIR}/image/test_image.cpp
)

target_include_directories(raytracer_tests PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)
