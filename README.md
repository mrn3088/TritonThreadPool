# TritonThreadPool


A simple and efficient ThreadPool implementation for modern C++. 

## Introduction
Hi, Welcome to TritonThreadPool! 🚀

TritonThreadPool is a cross-platform, high-performance C++11 (and above) thread pool implementation without any third-party dependencies. Inspired by content from the book "C++ Concurrency in Action (2nd Edition)" and some outstanding implementations on GitHub, this project has undergone extensive modifications, expansions, and optimizations. As a result, it offers significant enhancements in terms of functionality, performance, and user-friendliness. The essence of TritonThreadPool is to provide a mechanism that efficiently manages and dispatches tasks across multiple threads. By utilizing a thread pool, it minimizes the number of threads being created and destroyed, optimizing system resources and boosting performance.

## Features

- **Easy-to-use API**: Simplify multi-threading with an intuitive interface.
- **Dynamic Allocation**: Automatically manages the number of worker threads.
- **Task Queue**: Efficiently schedules tasks for execution.

## Getting Started

### Prerequisites

- A modern C++ compiler (e.g., GCC, Clang).
- Preferably C++17, minimum C++11.
- CMake for building the project (optional).

### Building the Project

```bash
$ git clone https://github.com/mrn3088/TritonThreadPool.git
$ cd CThreadPool
$ cmake . -Bbuild
$ cd build
$ make -j8
```

### Usage

Here's a basic example of how to use the ThreadPool:

```cpp
#include "src/TThreadPool.hpp"

using namespace mrn;

float add_by_5(float i) {
    return i + 5.0f;
}

int main() {
    UThreadPool tp;
    int i = 6, j = 3;
    auto r1 = tp.commit([i, j] { return i - j; });
    std::future<float> r2 = tp.commit(std::bind(add_by_5, 8.5f));

    std::cout << r1.get() << std::endl;
    std::cout << r2.get() << std::endl;
    return 0;
}
```

## Roadmap
- [x] Basic types.
- [ ] Data structures for Thread Pool.
- [ ] Task queue.
- [ ] Task prioritization.
- [ ] Graceful shutdown feature.
- [ ] Extendable with custom task executors.

## Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
