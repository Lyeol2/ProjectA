# ProjectA CMakeList.txt

cmake_minimum_required(VERSION 3.20)
# 프로젝트 이름 및 버전
PROJECT ( "ProjectA" )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
SET ( OUTPUT_ELF "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")

# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Debug )
SET ( CMAKE_VERBOSE_MAKEFILE true )
 
set(CMAKE_CXX_STANDARD 20)



# 빌드할 Example Code 번호
SET (EXAMPLE_NAME Example_0)

# include 경로 전역 지정
include_directories(${CMAKE_SOURCE_DIR}/include)

# 하위 폴더 추가
add_subdirectory(source)
add_subdirectory(example)
