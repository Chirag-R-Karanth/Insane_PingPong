# Insane_PingPong
This is a basic ping pong written in cpp(because of my masochism) with a clock,score and variable increasing velocity

# Modular Pong (SFML)

A high-performance, modular Pong game built with **C++** and **SFML**. This version features a responsive design that automatically scales to your desktop resolution, a large watermark-style scorecard, and a clean object-oriented architecture.

## 🚀 Features
*   **Modular Architecture**: Logic is separated into distinct classes for better maintainability.
*   **Responsive Scaling**: Automatically detects your Fedora desktop resolution and scales gameplay objects accordingly.
*   **Delta-Time Physics**: Frame-independent movement ensures the game runs at the same speed regardless of monitor refresh rates.
*   **Linux Optimized**: Font paths are pre-configured for standard Fedora directories (`/usr/share/fonts/`).

## 🛠️ Requirements

To build this project on Fedora, you need the SFML development libraries and a C++ compiler. Install them using the following command:
```bash
sudo dnf install SFML-devel gcc-c++
