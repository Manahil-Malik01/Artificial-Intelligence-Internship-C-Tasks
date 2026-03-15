from scapy.all import *

def process_packet(packet):
    if packet.haslayer(IP):
        ip_layer = packet.getlayer(IP)
        print(f"[!] New Packet: {ip_layer.src} -> {ip_layer.dst} | Protocol: {ip_layer.proto}")
        
        # Agar HTTP data hai to wo bhi dikhaye (Unencrypted traffic)
        if packet.haslayer(Raw):
            payload = packet.getlayer(Raw).load
            print(f"[*] Data: {payload.decode('utf-8', errors='ignore')}")

print("--- Kali Network Sniffer Start Ho Raha Hai ---")
# 'iface' mein apna interface likhein, usually 'eth0' ya 'wlan0'
sniff(iface="eth0", store=False, prn=process_packet)
