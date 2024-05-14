# Numerical Integration

This repository contains a xtensor-based C++ implementation of `Riemann` and `Trapezoidal` integration methods.

## Getting Started

To manage the dependencies, this project uses [pixi](https://pixi.sh/latest/). To install the dependencies using it, you can run:

```sh
pixi install
```

After installing the dependencies, you can run the project using the provided `run.sh` script:

```sh
./run.sh
```

## Methods available

**Riemann Integration**

The Riemann integration is implemented in `src/riemann.cpp` and `src/riemann.hpp`. This method approximates the integral of a function by summing up areas of rectangles under the curve.

**Trapezoidal Integration**

The Trapezoidal integration is implemented in `src/trapezoidal.cpp` and `src/trapezoidal.hpp`. This method approximates the integral by summing up areas of trapezoids under the curve, which typically provides a better approximation than the Riemann method.

## Contributing

We welcome contributions! If you have suggestions for improvements or bug fixes, please feel free to fork the repository and submit a pull request.

## License

`numerical-integration` is distributed under the MIT license. See LICENSE for more details.
