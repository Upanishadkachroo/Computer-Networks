# Reliable Data Transfer Protocols Simulation

## Overview
This repository contains C implementations of various reliable data transfer protocols used in computer networks. These protocols simulate packet transmission, acknowledgment handling, and error control mechanism such as packet loss and retransmission.

## Implemented Protocols
### 1. **Go-Back-N (GBN) Protocol**
- Implements a sliding window protocol where lost packets cause retransmission of all subsequent packets.
- Uses random packet loss simulation to test the retransmission mechanism.
- Features:
  - Sender transmits packets in a window.
  - Lost packets trigger retransmission from the lost packet onward.
  - Simulates acknowledgment receipt and window sliding.

### 2. **Selective Repeat (SR) Protocol**
- Implements a sliding window protocol that retransmits only lost packets instead of resending all.
- Uses a separate acknowledgment mechanism for each packet.
- Features:
  - Individual retransmission for lost packets.
  - Acknowledgment tracking for each frame.
  - Simulated transmission and acknowledgment process.

### 3. **Stop-and-Wait Protocol**
- Implements a simple ARQ (Automatic Repeat reQuest) protocol.
- Sender waits for an acknowledgment before sending the next packet.
- Features:
  - Simulates packet loss and acknowledgment loss.
  - Retransmits packets when acknowledgments are lost.
  - Ensures reliable packet delivery before proceeding to the next packet.

## How to Compile and Run
### Compilation
Use the GCC compiler to compile the C programs.
```sh
gcc -o gbn gbn.c
gcc -o sr sr.c
gcc -o stop_wait stop_wait.c
```

### Running the Programs
Run the compiled executables with user input for parameters:
```sh
./gbn
./sr
./stop_wait
```

## Dependencies
- C compiler (GCC recommended)
- Standard C libraries (`stdio.h`, `stdlib.h`, `stdbool.h`, `time.h`, `unistd.h`)

## Example Usage
For the Stop-and-Wait protocol, enter:
```sh
Enter the number of packets to be sent: 5
Enter the probability of packet/ACK loss (scale: 0-1): 0.2
```
Output will simulate packet transmission and handling.

## Contributing
Feel free to fork the repository, make improvements, and submit pull requests!

## License
This project is open-source under the MIT License.

