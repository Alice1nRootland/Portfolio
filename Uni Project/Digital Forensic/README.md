# Forensic Incident Analysis: Case G05

## Overview
This repository contains the forensic analysis of a suspicious network packet capture (`Data05.pcap`) and the corresponding malicious artifact extracted during the investigation. The analysis successfully reconstructed the infection lifecycle, from delivery via a weaponized document to the establishment of an obfuscated C2 tunnel.

## Investigation Methodology
The investigation followed a rigorous Incident Response (IR) workflow:
1. **Network Profiling:** Baseline identification and traffic anomaly detection using `tshark`.
2. **Delivery Vector Analysis:** Tracking the initial point of compromise via HTTP request logs.
3. **Artifact Extraction:** Carving the weaponized file from the stream for offline inspection.
4. **Static Malware Analysis:** VBA macro inspection to understand the execution trigger.
5. **Threat Attribution:** Verification of the payload against global threat intelligence (VirusTotal).

## Tools Used
* **Network Analysis:** `tshark`, `capinfos`, `tcpflow`
* **Malware Analysis:** `olevba` (oletools)
* **Intelligence:** `VirusTotal`, `sha256sum`, `ent` (entropy analysis)

## Key Findings

### 1. Delivery Vector
The host `172.16.3.133` downloaded a malicious MS Word document (`Companies-Invoice-0970945`) from `entisrael.com`.

### 2. Execution Trigger
Static analysis identified a malicious `autoopen` macro. Upon opening, the document utilized `Interaction.Shell` to execute obscured commands, triggering the infection process.

### 3. C2 Infrastructure
The malware established a persistent WebSocket tunnel (HTTP 101 Switching Protocols) to `cimedaorb.pw` (195.69.187.56).
* **Entropy Analysis:** An entropy score of **4.97 bits/byte** confirmed the data stream was obfuscated/compressed, indicating an attempt to bypass traditional signature-based detection.

### 4. Attribution
The artifact (SHA256: `c8212610730cc6902883eee501e0ba8a2b043b880f7ab374df4a5c585d88ac8b`) was attributed to the **Emotet** trojan family by 47/58 security vendors.

## Evidence Gallery

<img width="1068" height="751" alt="image" src="https://github.com/user-attachments/assets/9c0b9e89-992a-49b0-bf0a-ed422ae8775f" />

- **Figure 1:** Network Traffic Baseline

  <img width="976" height="272" alt="image" src="https://github.com/user-attachments/assets/534672db-7093-43da-8b8a-e1066b9f1653" />

- **Figure 2:** HTTP Delivery URI

  <img width="1119" height="656" alt="image" src="https://github.com/user-attachments/assets/7885e105-37c9-4e16-9cf7-8be60033807c" />

- **Figure 3:** Macro Analysis (olevba)
  
  <img width="577" height="220" alt="image" src="https://github.com/user-attachments/assets/b4c8a66a-8dcb-43d0-816a-dab3d206561f" />

- **Figure 4:** C2 WebSocket Upgrade (tshark)
  
<img width="1371" height="816" alt="image" src="https://github.com/user-attachments/assets/a73e571e-8770-4462-a679-776864da4274" />
  
- **Figure 5:** VirusTotal Detection Summary

---
*Created as part of UTeM*
