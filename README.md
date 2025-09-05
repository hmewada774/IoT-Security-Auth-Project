# IoT Security Authentication Project

This repository contains two C++ programs that demonstrate **secure authentication mechanisms** using TOTP, XOR encryption, and simplified ECC-based key exchange for IoT devices.

## 📂 Files
- **TOTP_XOR_Auth.cpp**  
  Implements a simple **TOTP (Time-based One-Time Password) authentication** system with XOR encryption/decryption for secure message exchange.

- **IoT_ECC_Auth.cpp**  
  Demonstrates an **IoT device registration and authentication system** using:
  - Simplified **Elliptic Curve Cryptography (ECC)**
  - **Time-based One-Time Password (TOTP)**
  - **Polynomial-based authentication**

## 🚀 Features
- Time-based One-Time Password (TOTP) generation
- XOR-based encryption/decryption
- Device registration with ECC keys
- Polynomial-based additional authentication
- User/device authentication simulation

## ⚙️ Compilation & Execution
```bash
# Compile
g++ TOTP_XOR_Auth.cpp -o totp_auth
g++ IoT_ECC_Auth.cpp -o iot_auth

# Run
./totp_auth
./iot_auth
```

## 📌 Use Cases
- Learning project for **cryptography in C++**
- Demonstrates **IoT device authentication techniques**
- Can be extended for **real-world IoT security research**

## 🛡️ Disclaimer
This project is for **educational and research purposes only**.  
The ECC and authentication schemes here are **simplified** and **not suitable for production use**.
