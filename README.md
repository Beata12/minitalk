# Minitalk 42

## Project Description

Minitalk is a communication program that comunicate between a server and a client, allowing for message exchange by using UNIX signals. The primary goal of Minitalk is to facilitate efficient and rapid communication using only SIGUSR1 and SIGUSR2 signals, ensuring support for Unicode characters. This project is an exploration of low-level programming concepts, inter-process communication (IPC), and signal handling in Unix-like operating systems.

### How it Works

- **Server**: The server must be initiated first. Upon starting, it will display its PID (Process ID) on the console. The server is designed to continuously listen for incoming messages from clients and print the received strings to the console.

- **Client**: The client program requires two arguments for its operation: the server's PID and the string message to be sent to the server. Once executed, the client sends the specified string to the server using UNIX signals.


![image](https://github.com/Beata12/minitalk/assets/38575612/03ea59e9-13d5-4a70-808c-37d75103bd45)


### Features

- **Efficient Communication**: The server displays the received string from the client almost instantly. The program is optimized to ensure that the transmission and display of messages are executed swiftly.

- **Multi-client Support**: The server can handle strings from multiple clients sequentially without the need for a restart, enhancing its usability for continuous operation.

- **Signal-based Communication**: The entire communication process between the client and the server is conducted using only two UNIX signals: SIGUSR1 and SIGUSR2. This constraint challenges the conventional methods of IPC and demonstrates the versatility of signal handling.

- **Acknowledgment System**: After receiving a message, the server sends an acknowledgment signal back to the client, confirming the successful reception of the message.

- **Unicode Support**: Minitalk supports the transmission and display of Unicode characters, allowing for a wide range of symbols and languages to be communicated.

## Getting Started

### Prerequisites

- Unix-like operating system
- GCC or Clang compiler

### Installation

**1. Clone the repository to your local machine:**
git clone https://github.com/Beata12/minitalk.git

**2. Navigate to the project directory:**
cd minitalk

**3.Compile the server and client:**
make

**4. Usage**
**Start the server in one terminal window:**
./server
Note the printed PID of the server.

**In a new terminal window, send a message from the client to the server using the server's PID:**
./client <Server_PID> "Your message here"
