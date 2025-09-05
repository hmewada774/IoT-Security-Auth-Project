#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <random>

// Elliptic Curve parameters (Simplified Example: y^2 = x^3 + ax + b)
struct ECCPoint {
    int x, y;
};

const int a = 2, b = 3; // Curve parameters
const int prime = 23;   // Prime field (small prime for simplicity)

// Function to perform modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Generate a pseudo-random private key
int generatePrivateKey() {
    return rand() % (prime - 1) + 1;
}

// Perform ECC key exchange (simplified)
ECCPoint eccMultiply(int privateKey, ECCPoint generator) {
    ECCPoint result = {0, 0};
    for (int i = 0; i < privateKey; i++) {
        result.x = (result.x + generator.x) % prime;
        result.y = (result.y + generator.y) % prime;
    }
    return result;
}

// Generate a Time-based One-Time Password (TOTP)
int generateTOTP(int secret, int timeStep = 30) {
    time_t currentTime = time(nullptr);
    return (secret ^ (currentTime / timeStep)) % 1000000; // 6-digit TOTP
}

// Polynomial-based authentication function
int polynomialAuth(int x, const std::vector<int>& coefficients) {
    int result = 0;
    for (size_t i = 0; i < coefficients.size(); i++) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

int main() {
    srand(time(nullptr));

    std::cout << "IoT Device Registration System\n";
    
    // Device Registration
    int deviceSecret;
    std::cout << "Enter a unique device secret key (integer): ";
    std::cin >> deviceSecret;

    // ECC Key Generation
    ECCPoint generator = {5, 1}; // Simplified ECC base point
    int privateKey = generatePrivateKey();
    ECCPoint publicKey = eccMultiply(privateKey, generator);

    std::cout << "Device registered with public key: (" << publicKey.x << ", " << publicKey.y << ")\n";

    // Device Authentication
    std::cout << "\nDevice Authentication\n";
    int inputSecret;
    std::cout << "Enter device secret key to authenticate: ";
    std::cin >> inputSecret;

    if (inputSecret == deviceSecret) {
        int totp = generateTOTP(deviceSecret);
        std::vector<int> coefficients = {5, 3, 2};
        int polynomialResult = polynomialAuth(totp, coefficients);
        
        std::cout << "Generated TOTP: " << totp << "\n";
        std::cout << "Polynomial Authentication Result: " << polynomialResult << "\n";

        // Simulating ECC authentication
        int userPrivateKey = generatePrivateKey();
        ECCPoint userPublicKey = eccMultiply(userPrivateKey, generator);

        std::cout << "User authenticated successfully with ECC public key: ("
                  << userPublicKey.x << ", " << userPublicKey.y << ")\n";
    } else {
        std::cout << "Authentication Failed! Invalid secret key.\n";
    }
    return 0;
}