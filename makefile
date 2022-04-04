make:
	g++ src/**/*.cc -o bin/tsp.exe
	bin/tsp.exe

run-test:
	g++ -o test/test.exe test/main.test.cc src/**/*.cc
	test/test.exe