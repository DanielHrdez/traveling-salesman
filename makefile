make:
	g++ --std=c++17 src/**/*.cc -o bin/tsp.exe
	bin/tsp.exe data -t $(seconds)

run-test:
	g++ --std=c++17 -o bin/test.exe test/main.test.cc src/**/*.cc
	bin/test.exe