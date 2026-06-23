# [cite_start]Portfolio: Network Security Infrastructure and Design (BAXZ2413) [cite: 6]

This repository contains practical assignments and projects for the BAXZ2413 module, focusing on the deployment, configuration, and analysis of network defenses, centralized logging, and active threat monitoring.

---

## 🛡️ Part 1: Layer 7 WAF Implementation (ByteBandit Shield)

ByteBandit Shield is a cybersecurity project focusing on the deployment and configuration of a Web Application Firewall (WAF). It demonstrates how to protect a vulnerable e-commerce application from Reflected Cross-Site Scripting (XSS) and SQL Injection (SQLi) using a containerized "Defense-in-Depth" architecture.

### Architecture & Topology
The system is built on a modern containerized stack, simulating a real-world enterprise gateway:
* **Vulnerable Target:** A custom PHP-based "Tech Store" (Apache) running on Port 8080.
* **Security Gateway:** Nginx Proxy Manager (NPM) acting as a Reverse Proxy and Layer 7 WAF on Port 80.
* **Encrypted Perimeter:** Cloudflare Tunnel providing a secure public entry point without opening local firewall ports.

### Features & Security Hardening
While standard WAFs offer basic protection, this project implements Manual Regex Filtering to mitigate advanced bypasses such as URL encoding and case-sensitivity variations.

#### Custom Nginx Security Rules
These rules were implemented in the Advanced configuration of the Nginx Proxy Host:

` ` `nginx
# 1. Block XSS keywords in the Search Query ($args)
if ($args ~* "(script|alert|onerror|onload|eval|javascript)") {
    return 403;
}

# 2. Block HTML tags (< >) in the Search Query (Plain & Encoded)
if ($args ~* "(<|%3C|%3E|>)") {
    return 403;
}

# 3. Block SQL Injection keywords
if ($args ~* "(union|select|insert|update|delete|drop|benchmark)") {
    return 403;
}
` ` `

---

## 🗼 Part 2: Centralized Security Watchtower Infrastructure

[cite_start]This group project implements a centralized security infrastructure designed to monitor network activities, centralize authentication, and detect threats across a multi-platform enterprise environment[cite: 1071]. 

[cite_start]**Team Members:** Faez Bin Nazari, Ayishah Amira Binti Mohd Zamri, Wan Norazmeera Binti Wan Jaferi, Nur Najihah Tasnim Binti Mohamad Fairos, Ain Nurin Binti Mohd Zahidie, Nur Aina Syukrina Binti Ruslan, Livekha A/P K Nagasundram, Siti Norbaiyah Binti An Sary, and Nur Batrisya Amira Binti Mohd Ridzuan[cite: 11].

### Architecture & Topology
[cite_start]The Watchtower infrastructure establishes a secure, encrypted WireGuard tunnel over a Tailscale overlay mesh network[cite: 451]. [cite_start]This allows centralized monitoring across different physical networks without requiring complex port-forwarding rules on the host hypervisor[cite: 452].

* [cite_start]**Identity & Access Management:** A Windows Server 2019 running Active Directory Domain Services (AD DS) for centralized user management[cite: 47, 113].
* [cite_start]**Monitored Endpoints:** An Ubuntu Linux client integrated into the AD domain via SSSD, allowing users to authenticate directly with their domain credentials[cite: 48].
* [cite_start]**Intrusion Detection System (IDS):** Suricata deployed on the Ubuntu endpoint to inspect incoming/outgoing traffic and generate alerts for suspicious behaviors[cite: 851].
* [cite_start]**SIEM Platform:** Wazuh Manager deployed on Rocky Linux 9 to collect, correlate, and visualize logs from the AD server, Ubuntu host, and IDS alerts[cite: 416, 896].

### Attack Simulation & Detection
To evaluate the effectiveness of the Watchtower, active attacks were simulated and logged:
* [cite_start]**Network Reconnaissance:** Continuous ICMP echo requests (ping) targeting the infrastructure were successfully detected and flagged by the Suricata IDS[cite: 815, 851].
* [cite_start]**SSH Brute-Force:** Hydra was utilized to brute-force SSH credentials, with Wazuh capturing high-fidelity event logs of the failed authentication attempts[cite: 508, 753]. 
* [cite_start]**SMB Brute-Force:** CrackMapExec was executed against the AD domain account through the SMB service[cite: 641]. [cite_start]The SIEM triggered Rule ID 60204 ("Multiple Windows logon failures"), mapped directly to MITRE ATT&CK T1110 (Credential Access: Brute Force)[cite: 787, 790, 791]. 

### Key Outcomes
[cite_start]The integration successfully demonstrated a layered defense strategy, aggregating host-based anomalies and mapping network telemetry directly to PCI DSS regulatory compliance criteria, such as log review standard 10.6.1[cite: 891, 1042].
