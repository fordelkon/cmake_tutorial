.PHONY: lib, pybind, clean, format, all

all: lib


lib:
	cmake -B build
	cmake --build build

format:
	python3 -m black .
	clang-format -i src/*.cc src/*.cu

clean:
	rm -rf build needle/backend_ndarray/ndarray_backend*.so
