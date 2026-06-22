# curs3d 

A real-time 3D rendering engine that displays 3D models directly in your terminal using braille Unicode characters for sub-character pixel precision.

![demo](res/cow_demo.gif)

## Features

- **Terminal-based 3D Rendering**: Uses ncurses and braille characters (⠀⠁⠂⠃...) to achieve 8 dots per character resolution
- **Full 3D Graphics Pipeline**:
  - OBJ model loading
  - Vertex and fragment shaders
  - Rasterization with barycentric coordinates
  - Lighting calculations
- **Real-time Interaction**: Rotate, scale, and manipulate 3D models in real-time
- **Multi-threaded Architecture**: Separate render and draw threads with double-buffering for smooth animation
- **Complete 3D Math Library**: 4x4 matrix operations, vector math, and transformation utilities
- **Cross-platform**: Builds on macOS and Linux

## Project Structure

```
src/
├── math/          # 3D mathematics (matrices, vectors)
├── model/         # Model loading (OBJ format)
├── ctrl/          # Graphics pipeline (shaders, rasterization, rendering)
└── main.c         # Entry point
```

## Building

### Prerequisites
- GCC compiler
- ncurses library (libncursesw on Linux, libncurses on macOS)
- GNU Make

### macOS
```bash
make debug    # Build with debug symbols
make run      # Clean, build, and run
```

### Linux
```bash
make debug    # Build with debug symbols
make run      # Clean, build, and run
```

## Running

```bash
./test
```

The program will render a 3D model in your terminal with real-time animation and interaction capabilities.

## Commands

- `make` or `make test` - Build the project
- `make debug` - Build with debug symbols (-g flag)
- `make run` - Clean, rebuild, and run
- `make clean` - Remove build artifacts and executable

## Technical Highlights

- **Braille Rendering**: Each character represents 8 pixels in a 2×4 grid, enabling high-resolution terminal graphics
- **Shader System**: Custom vertex and fragment shaders for flexible rendering
- **Double Buffering**: Prevents flickering during animation
- **Thread-safe Design**: Separate threads for rendering computation and screen drawing
- **Platform Abstraction**: Conditional compilation for macOS and Linux specific features
