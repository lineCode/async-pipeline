project(taller-tp-4)

add_executable(example
	DummyProcess.cpp
	Main.cpp)

target_link_libraries(example pipeline)