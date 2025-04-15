# STM32 ADC with DMA: Read Multiple Sensors (LDR & LM35) 🌟

![STM32 ADC](https://img.shields.io/badge/STM32_ADC-LM35_LDR_DMA-brightgreen)  
[![Releases](https://img.shields.io/badge/Releases-Check%20Here-blue)](https://github.com/bhavishy2311/STM32-ADC-with-DMA-Read-Multiple-Sensors-LDR-LM35-/releases)

## Overview

Welcome to the STM32 ADC with DMA repository! This project demonstrates how to read multiple sensors using the STM32 microcontroller, specifically the STM32F103C8T6. It leverages the Analog-to-Digital Converter (ADC) and Direct Memory Access (DMA) to efficiently read data from an LM35 temperature sensor and an LDR (Light Dependent Resistor).

## Features

- **Efficient Sensor Reading**: Use DMA to read multiple sensors without CPU intervention.
- **Temperature Measurement**: Read temperature data from the LM35 sensor.
- **Light Measurement**: Measure light intensity using the LDR.
- **Easy Integration**: Simple setup with STM32CubeIDE and CubeMX.
- **Open Source**: Feel free to contribute or modify as needed.

## Table of Contents

1. [Getting Started](#getting-started)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Setup Instructions](#setup-instructions)
5. [Code Structure](#code-structure)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [License](#license)
9. [Contact](#contact)

## Getting Started

To get started, you can check the [Releases section](https://github.com/bhavishy2311/STM32-ADC-with-DMA-Read-Multiple-Sensors-LDR-LM35-/releases) for the latest version of the project. Download the necessary files and execute them to set up your environment.

## Hardware Requirements

To work with this project, you will need the following hardware components:

- **STM32F103C8T6**: This is the microcontroller used in this project.
- **LM35 Temperature Sensor**: This sensor provides an analog voltage output proportional to the temperature.
- **LDR (Light Dependent Resistor)**: This sensor changes resistance based on light intensity.
- **Breadboard and Jumper Wires**: For making connections.
- **Power Supply**: Ensure you have a stable power supply for the microcontroller.

## Software Requirements

The following software tools are required to work with this project:

- **STM32CubeIDE**: This is the Integrated Development Environment for STM32.
- **STM32CubeMX**: Use this tool to configure the microcontroller settings.
- **C Compiler**: A standard C compiler compatible with STM32.

## Setup Instructions

1. **Clone the Repository**: Start by cloning the repository to your local machine.

   ```bash
   git clone https://github.com/bhavishy2311/STM32-ADC-with-DMA-Read-Multiple-Sensors-LDR-LM35-.git
   ```

2. **Open STM32CubeIDE**: Launch the STM32CubeIDE and import the project.

3. **Configure the Project**:
   - Open STM32CubeMX within the IDE.
   - Set up the ADC channels for the LM35 and LDR.
   - Enable DMA for the ADC to allow for seamless data transfer.

4. **Build the Project**: Compile the code and upload it to your STM32F103C8T6.

5. **Connect the Sensors**: Make sure to connect the LM35 and LDR to the correct ADC pins on the microcontroller.

6. **Run the Code**: After uploading, run the code to start reading sensor values.

## Code Structure

The project is organized into several key directories:

- **/Inc**: Contains header files for the project.
- **/Src**: Contains the main source files.
- **/Drivers**: Includes drivers for peripherals.
- **/Middlewares**: Contains any middleware libraries used.

### Main Files

- **main.c**: The entry point of the application.
- **adc.c**: Contains functions to handle ADC initialization and reading.
- **dma.c**: Manages DMA configuration and data transfer.
- **sensor.c**: Functions specific to reading LM35 and LDR values.

## Usage

Once the setup is complete, the microcontroller will continuously read values from the LM35 and LDR. You can modify the code to process these values as needed. For example, you can display the temperature on an LCD or send the data over UART.

### Example Code Snippet

Here’s a brief example of how to read the temperature from the LM35:

```c
float read_temperature() {
    // Start ADC conversion
    HAL_ADC_Start(&hadc1);
    // Wait for conversion to complete
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    // Read the ADC value
    uint32_t adc_value = HAL_ADC_GetValue(&hadc1);
    // Convert ADC value to temperature
    float temperature = (adc_value * 3.3 / 4095) * 100; // Assuming a 3.3V reference
    return temperature;
}
```

## Contributing

Contributions are welcome! If you want to add features or fix bugs, feel free to fork the repository and submit a pull request. Please ensure your code follows the project's style guidelines.

## License

This project is licensed under the MIT License. You are free to use, modify, and distribute this code as long as you include the original license.

## Contact

For any questions or suggestions, feel free to reach out to the repository owner. You can also check the [Releases section](https://github.com/bhavishy2311/STM32-ADC-with-DMA-Read-Multiple-Sensors-LDR-LM35-/releases) for updates and new features.

---

Thank you for checking out this project! We hope it helps you in your journey with STM32 and sensor integration. Happy coding!