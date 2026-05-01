# Insane Ping Pong

A high-performance Pong clone built using **C++** and **SFML**.
The game features dynamic difficulty, responsive scaling to your screen, and a clean modular architecture.

---

## Features

* Modular object-oriented design
* Increasing ball velocity over time (dynamic difficulty)
* Responsive scaling to match desktop resolution
* Score tracking with large watermark-style display
* Smooth paddle controls and collision handling

---

## Controls

| Action    | Key   |
| --------- | ----- |
| Move Up   | W / ↑ |
| Move Down | S / ↓ |
| Exit Game | Esc   |

---

## Requirements

Make sure you have the following installed:

* C++ compiler (g++)
* SFML development libraries

### Install on Fedora

```bash
git clone https://github.com/Chirag-R-Karanth/Insane_PingPong.git
cd Insane_PingPong
```

```bash
sudo dnf install SFML-devel gcc-c++
```

---

## Build Instructions

### Compile

```bash
make
```

### Run

```bash
./pong
```

### Clean Build Files

```bash
make clean
```

---

## Project Structure

* `main.cpp` — Entry point and main game loop
* `Ball.hpp` — Ball movement, collision, and reset logic
* `Paddle.hpp` — Player input and boundary constraints
* `ScoreBoard.hpp` — Score tracking and rendering
* `Makefile` — Build automation
* `.gitignore` — Ignores binaries and system files

---

##  Notes

* The game automatically adapts to your screen resolution
* Ball speed increases over time to make gameplay progressively harder
* Designed with separation of concerns for easy extension and maintenance

---

## Future Improvements(No promises)

* Sound effects and background music
* AI-controlled opponent
* Menu system and pause functionality
* Power-ups and gameplay variations

---
