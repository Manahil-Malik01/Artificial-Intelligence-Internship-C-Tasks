🕵️‍♂️ Python Network Sniffer: Scapy Packet Analysis
A lightweight network monitoring tool built with Scapy. This script captures real-time IP traffic and extracts raw data payloads from unencrypted packets, demonstrating how data flows across a network interface.

[!CAUTION]

ETHICAL USE ONLY: This tool is intended for educational purposes and authorized security testing. Sniffing network traffic on networks you do not own or have explicit permission to monitor is illegal.

📌 Project Overview
This project uses the Scapy library to put a network interface into a listening state. It intercepts packets, decodes the Internet Protocol (IP) layer to show source and destination addresses, and attempts to display the raw payload (useful for analyzing unencrypted protocols like HTTP, FTP, or DNS).

🛠️ Key Features & Concepts
1. Packet Filtering & Layers
Network traffic is organized in "Layers" (OSI Model). This script demonstrates how to target specific layers:

haslayer(IP): Filters out non-IP traffic (like ARP) to focus on internet protocol data.

getlayer(Raw): Accesses the application layer data (the actual message or command being sent).

2. Real-time Sniffing
The sniff() function is the heart of the script:

iface: Specifies which hardware to listen on (e.g., eth0 for Ethernet, wlan0 for Wi-Fi).

prn: A "callback" function that executes for every single packet captured.

store=False: Prevents the script from keeping all packets in memory, allowing it to run for long periods without crashing the system.

3. Data Decoding
Since network data travels as bytes, the script uses .decode('utf-8', errors='ignore') to convert raw binary data into human-readable text while skipping characters that cannot be decoded.

📂 Project Structure
sniffer.py: The main script containing the packet processing logic and the sniffer configuration.

🚀 How to Run
Install Scapy:

Bash
pip install scapy
Permissions:
Network sniffing requires root/administrative privileges. On Linux (Kali), run with sudo:

Bash
    sudo python3 sniffer.py
    ```
3.  **Configure Interface:**
    Ensure the `iface` parameter matches your active network interface (check using `ifconfig` or `ip a`).

## 💡 Technical Takeaways
*   **Network Visibility:** Understanding how source and destination IPs are visible in every packet.
*   **The Danger of Cleartext:** Seeing firsthand how "Raw" data (like passwords or form data) can be read if a website does not use HTTPS/TLS encryption.
*   **Callback Architecture:** Learning how to process a continuous stream of data efficiently using function pointers in Python.

---

**Built for Learning. Secure your code, secure the web.** 🌐
