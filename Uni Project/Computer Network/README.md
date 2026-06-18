# Network Intrusion Detection System (IDS) Implementation using Snort

## 📌 Project Overview
This project demonstrates the deployment and configuration of **Snort IDS** (Intrusion Detection System) within a controlled virtualized environment. The objective was to simulate a "Red Team vs. Blue Team" scenario, where specific network attacks were launched from a Kali Linux machine and detected in real-time by a custom-configured Ubuntu Snort sensor.

## 🛠️ Technologies Used
- **IDS Engine:** Snort 2.9 (NIDS Mode)
- **Operating Systems:** Ubuntu 24.04 LTS (Defender), Kali Linux 2024 (Attacker)
- **Virtualization:** VMware Workstation (NAT Network Configuration)
- **Tools & Scripts:** Nmap, Hydra, Nikto, Python (Custom C2 Scripts), Netcat

## 🏗️ Network Topology
The lab consists of a private NAT network (`192.168.158.0/24`) isolating the attack traffic from the physical host.

| Role | Hostname | IP Address | Function |
| :--- | :--- | :--- | :--- |
| **Attacker** | Kali-VM | `192.168.158.128` | Generates malicious traffic (Scans, Brute Force, Exploits) |
| **Defender** | Ubuntu-VM | `192.168.158.129` | Hosts Snort IDS and monitors interface `ens33` |

## 🛡️ Custom Rules Implemented
I developed custom signature-based rules to detect specific attack vectors. These were configured in `/etc/snort/rules/local.rules`.

```bash
# 1. ICMP Ping Sweep Detection
alert icmp any any -> $HOME_NET any (msg:"ICMP PING DETECTED"; sid:1000001; rev:1;)

# 2. Nmap TCP Stealth Scan
alert tcp any any -> $HOME_NET any (flags: S; msg:"[!!] NMAP PORT SCAN DETECTED [!!]"; sid:1000002; rev:1;)

# 3. SSH Brute Force Detection (Hydra)
alert tcp any any -> $HOME_NET 22 (msg:"POTENTIAL SSH BRUTE FORCE ATTACK"; flags:S; flow:stateless; sid:1000004; rev:1;)

# 4. Malware C2 Beacon (Reverse Shell)
alert tcp any any -> any 6666 (msg:"[!!] MALWARE C2 BEACON DETECTED [!!]"; flags:S; sid:1000007; rev:2;)
