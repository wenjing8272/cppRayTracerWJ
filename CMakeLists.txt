# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.10)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("cppRayTracerWJ")

# 包含子项目。
add_subdirectory ("cppRayTracerWJ")

# 
target_compile_definitions(${PROJECT_NAME} PRIVATE 
	STB_IMAGE_WRITE_IMPLEMENTATION
)
# 
target_include_directories(cppRayTracerWJ PRIVATE thirdParty/stb)
