
add_library(pipeline
	AsyncPipeline.cpp
	AsyncPipelineThread.cpp
	Mutex.cpp
	Pipeline.cpp
	Process.cpp
	ProcessQueue.cpp
	Thread.cpp)

target_link_libraries(pipeline pthread)
