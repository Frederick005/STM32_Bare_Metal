# Embedded-Systems-Bare-Metal-Programming-Ground-Up-STM32-
Bare‑metal ARM Cortex‑M (STM32F4) firmware projects using CMSIS and direct register access (no HAL/LL). Focus: GPIO, SysTick, TIM/PWM, UART, SPI, I2C, ADC, DMA, NVIC. Skills: embedded C, datasheet navigation, memory maps/bit‑fields, GDB/OpenOCD, CMake/Make, Git, CI, bring‑up, interrupts, reliability.
UDEMY COURSE : https://www.udemy.com/course/embedded-systems-bare-metal-programming/?couponCode=MT251006G1

# Embedded Systems Bare‑Metal Programming (STM32, ARM Cortex‑M)

Short pitch for recruiters and hiring managers
- Hands‑on register‑level (bare‑metal) firmware for ARM Cortex‑M (STM32F4 Nucleo)
- Drivers built from datasheet/reference manual only (no HAL/LL), using CMSIS and direct register access
- Systematic bring‑up, debugging, and test practices across GPIO, TIM, SysTick, NVIC, UART, SPI, I2C, PWM, ADC, and DMA

## About
This repository tracks my projects and exercises from a bare‑metal embedded systems course focused on ARM Cortex‑M microcontrollers (STM32F4 Nucleo, Cortex‑M4). The emphasis is on learning‑by‑building: extracting requirements from the reference manual and datasheet, defining peripheral base addresses, mapping registers, and writing production‑style firmware in C without third‑party libraries.

Deliverables include register‑accurate drivers, minimal board support, and small applications that demonstrate correct peripheral configuration, timing, and reliability. All code favors clarity, traceability to documentation, and disciplined debugging.

## Skills at a glance (keywords)
- Bare‑metal embedded C, register‑level programming
- ARM Cortex‑M architecture, CMSIS
- STM32F4 Nucleo (Cortex‑M4), memory map, linker script basics
- Peripheral drivers: GPIO, SysTick, TIM (general purpose timers), PWM, NVIC/interrupts, UART, SPI, I2C, ADC, DMA
- Datasheet/reference manual navigation, address/bit‑field decoding
- Hardware–software integration, board bring‑up, clock/reset and RCC configuration
- Debugging: SWD, watchpoints/breakpoints, step‑through, register inspection
- Build and tooling: arm‑none‑eabi‑gcc, Make/CMake or STM32 IDE, OpenOCD, GDB
- Quality discipline: coding standards, assertions, simple test harnesses, incremental verification
