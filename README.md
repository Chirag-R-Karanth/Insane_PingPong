# Insane_PingPong
This is a basic ping pong written in cpp(because of my masochism) with a clock,score and variable increasing velocity<br>
<br>
A high-performance, modular Pong game built with **C++** and **SFML**. This version features a responsive design that automatically scales to your desktop resolution, a large watermark-style scorecard, and a clean object-oriented architecture.

## 🚀 Features
*   **Modular Architecture**: Logic is separated into distinct classes for better maintainability.

## 🛠️ Requirements

To build this project on Fedora, you need the SFML development libraries and a C++ compiler. Install them using the following command:
```bash
sudo dnf install SFML-devel gcc-c++
```

To Compile the GameIn your project directory,<br>
run:```bash
  make
  ```
Run the GameExecute the generated binary:
```Bash
./pong```
Clean Build FilesTo remove the compiled binary and start fresh:```Bashmake clean``` 
###Project Structuremain.cpp — 
* The entry point and main game loop.
* Ball.hpp — Logic for ball movement, bouncing, and resets.
* Paddle.hpp — Logic for player movement and screen clamping.
* ScoreBoard.hpp — Handles score tracking and watermark text rendering.
* Makefile — Automation for compiling on Fedora.
* .gitignore — Prevents binaries and system junk from being tracked by Git.
