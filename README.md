# Circular Buffer Driver (Ring Buffer)

## Project Overview
This project implements a **Circular Buffer (Ring Buffer)** data structure in C. It serves as a robust mechanism for handling asynchronous data streams, typical in UART communication, Audio processing, and IoT sensor hubs.

## âKey Features
* **Continuous Streaming:** Uses modulo arithmetic (`%`) to wrap buffer indices, allowing for infinite data writing within a fixed memory footprint.
* **Safety & Integrity:** Includes "Buffer Full" and "Buffer Empty" detection logic to prevent data overwrites (overflow) and invalid reads (underflow).
* **Pointer-Based Driver:** All functions utilize pointers for efficient memory access and state modification.
* **Burst Simulation:** Includes a test mode to simulate high-speed sensor data bursts to verify system stability under load.

## Tech Stack
* **Language:** C
* **Concepts:** Structs, Pointers, Modulo Arithmetic, Memory Management.

## ðHow to Run
1. Compile the code.
2. Run the executable.
3. Use the CLI menu:
   - **'W':** Simulate a single sensor write.
   - **'R':** Read/Transmit data to the cloud.
   - **'B':** Simulate a high-speed data burst.
