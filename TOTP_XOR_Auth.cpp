#include <iostream>
#include <ctime>

// Function to generate a Time-based One-Time Password (TOTP)
int generateTOTP(int secret, int timeStep = 30) {
    time_t currentTime = time(nullptr);
    return (secret ^ (currentTime / timeStep)) % 1000000; // 6-digit TOTP
}

// Function to perform XOR Encryption & Decryption
std::string xorEncryptDecrypt(std::string input, char key) {
    for (char &ch : input) {
        ch = ch ^ key;
    }
    return input;
}

int main() {
    int secretKey;
    std::cout << "Enter a secret key (any number): ";
    std::cin >> secretKey;

    // Generate & Display TOTP
    int totp = generateTOTP(secretKey);
    std::cout << "Generated TOTP (use this for authentication): " << totp << "\n";

    // User Authentication
    int userTOTP;
    std::cout << "Enter the TOTP for authentication: ";
    std::cin >> userTOTP;

    if (userTOTP == totp) {
        std::cout << "Authentication Successful!\n";
    } else {
        std::cout << "Authentication Failed! Wrong TOTP.\n";
        return 1; // Stop program if TOTP is incorrect
    }

    // Message Encryption
    std::string message;
    std::cout << "Enter a message to encrypt: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, message);

    char xorKey = 'X'; // Encryption key
    std::string encryptedMessage = xorEncryptDecrypt(message, xorKey);
    std::cout << "Encrypted Message: " << encryptedMessage << "\n";

    // Message Decryption
    std::string decryptedMessage = xorEncryptDecrypt(encryptedMessage, xorKey);
    std::cout << "Decrypted Message: " << decryptedMessage << "\n";

    return 0;
}
