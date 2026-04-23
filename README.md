# Fract-ol

A graphical program that generates and visualizes fractals in real time, developed as part of the 42 curriculum.  
The goal is to explore complex numbers, iterative functions, and interactive rendering.

---

## 🚀 Features

- Rendering of classic fractals:
  - Mandelbrot set
  - Julia set
- Real-time zoom and navigation
- Mouse-controlled zooming centered on cursor position
- Keyboard navigation (pan and reset view)
- Adjustable parameters for Julia set exploration
- Smooth color gradients based on iteration depth

---

## 🧠 What I learned

This project focuses on mathematical visualization and interactive graphics:

- Complex numbers and iterative functions
- Escape-time algorithm for fractal generation
- Mapping pixel coordinates to the complex plane
- Dynamic rendering optimization
- Event-driven programming (keyboard + mouse handling)
- Basic computer graphics pipeline using MiniLibX
- Color mapping techniques based on iteration counts

---

## ⚙️ How it works

Each pixel of the screen corresponds to a point in the complex plane:

1. Map pixel → complex number \( c \)
2. Iterate a function (e.g. \( z_{n+1} = z_n^2 + c \))
3. Determine how quickly the sequence diverges
4. Use iteration count to assign a color

This produces the characteristic fractal patterns.

---

## 🛠️ Tech stack

- Language: C  
- Graphics: MiniLibX  
- Mathematics: complex numbers, iterative dynamics  
- Environment: Linux  

---

## ▶️ Usage

make

./fractol mandelbrot
