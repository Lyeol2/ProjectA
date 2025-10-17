# example/Example_0/CMakeList.txt

project("Example_0")
# main.cpp를 이용해 최종 실행 파일 빌드
add_executable(Example_0 main.cpp)

# 엔진과 게임 모듈을 링크
target_link_libraries(Example_0 PRIVATE Application Entity)