![Screenshot 2025-04-11 131613](https://github.com/user-attachments/assets/8b177329-1da0-468f-9084-4ee9a26cf50b)
# STM32 ADC with DMA – Read Multiple Sensors (LDR + LM35)

This is a complete STM32 Blue Pill project that demonstrates how to read multiple analog sensors using the ADC in **DMA mode**, and display the results on an **LCD16x2 display**. The sensors used in this project are:

- **LM35** temperature sensor
- **LDR** (Light Dependent Resistor)

The project also includes a custom **LCD16x2 library** for interfacing with the Blue Pill using GPIO.

---

## 🔧 Features

- Multi-channel ADC configuration using **STM32CubeMX**
- **DMA** support for efficient ADC data transfer
- Read **LM35** and **LDR** sensor data
- Display results on **LCD16x2** using 4-bit mode
- **Breadboard-friendly** setup
- Clean and readable **HAL-based code**

---

## 📷 Project Demo

Watch the full project tutorial and demonstration on **Sly Fox Electronics YouTube Channel**:  
👉 [Watch Video](https://youtube.com/@SlyFoxElectronics)

---

## 🧰 Hardware Required

| Component         | Quantity |
|------------------|----------|
| STM32 Blue Pill   | 1        |
| LM35 Temperature Sensor | 1  |
| LDR + 10k Resistor       | 1  |
| LCD 16x2 Display         | 1  |
| Breadboard + Jumper Wires | 1  |
| USB to Serial Programmer | 1  |

---

📽️ YouTube Channel
🔔 Subscribe to Sly Fox Electronics for more STM32 and electronics tutorials!

## 📁 Folder Structure

```bash
├── Core/
│   ├── Inc/
│   └── Src/
├── Drivers/
├── LCD16x2_Library/
├── .ioc (CubeMX config)
├── README.md



