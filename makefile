make:
	g++ --std=c++20 src/**/*.cc -o bin/tsp.exe
	bin/tsp.exe data

run-test:
	g++ -o bin/test.exe test/main.test.cc src/**/*.cc
	bin/test.exe