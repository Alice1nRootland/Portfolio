# 🛡️ Portfolio: Network Security Infrastructure and Design (BAXZ2413)

This repository contains practical assignments and projects for the **BAXZ2413 - Network Security Infrastructure and Design** module, focusing on the deployment, configuration, and analysis of network defenses, centralized logging, and active threat monitoring.

---

# 🛡️ Part 1: Layer 7 WAF Implementation (ByteBandit Shield)

ByteBandit Shield is a cybersecurity project that demonstrates the deployment and configuration of a **Web Application Firewall (WAF)** to protect a vulnerable web application from common web-based attacks such as **Cross-Site Scripting (XSS)** and **SQL Injection (SQLi)**.

## Architecture & Topology

The environment follows a defense-in-depth architecture:

* **Vulnerable Target:** Custom PHP-based "Tech Store" web application running on Apache (Port 8080)
* **Security Gateway:** Nginx Proxy Manager (NPM) acting as a Reverse Proxy and Layer 7 WAF (Port 80)
* **Secure Public Access:** Cloudflare Tunnel providing encrypted external access without exposing local firewall ports

## Security Features

To improve detection beyond standard WAF protections, custom Nginx regex filtering was implemented to mitigate bypass techniques such as:

* URL encoding attacks
* Case sensitivity evasion
* Obfuscated payloads

### Custom Nginx Security Rules

```nginx
# Block common XSS keywords
if ($args ~* "(script|alert|onerror|onload|eval|javascript)") {
    return 403;
}

# Block HTML tags (plain and URL encoded)
if ($args ~* "(<|%3C|%3E|>)") {
    return 403;
}

# Block common SQL injection keywords
if ($args ~* "(union|select|insert|update|delete|drop|benchmark)") {
    return 403;
}
```

## Security Outcomes

* Successfully blocked reflected XSS payloads
* Prevented common SQL injection attempts
* Demonstrated layered web application protection using reverse proxy filtering
* Validated custom rule effectiveness against basic bypass techniques

---

# 🗼 Part 2: Centralized Security Watchtower Infrastructure

This group project implements a centralized security monitoring infrastructure designed to collect logs, centralize authentication, and detect threats across a multi-platform enterprise environment.

## Team Members

* Faez Bin Nazari
* Ayishah Amira Binti Mohd Zamri
* Wan Norazmeera Binti Wan Jaferi
* Nur Najihah Tasnim Binti Mohamad Fairos
* Ain Nurin Binti Mohd Zahidie
* Nur Aina Syukrina Binti Ruslan
* Livekha A/P K Nagasundram
* Siti Norbaiyah Binti An Sary
* Nur Batrisya Amira Binti Mohd Ridzuan

## Architecture & Topology

The Watchtower infrastructure establishes a secure monitoring environment using a combination of WireGuard and Tailscale.

### Components

#### Identity & Access Management

* Windows Server 2019
* Active Directory Domain Services (AD DS)
* Centralized user and authentication management

#### Monitored Endpoints

* Ubuntu Linux Client
* Domain-integrated using SSSD
* Active Directory authentication support

#### Intrusion Detection System (IDS)

* Suricata IDS
* Real-time traffic inspection
* Network threat detection and alert generation

#### Security Information and Event Management (SIEM)

* Wazuh Manager on Rocky Linux 9
* Centralized log collection
* Event correlation and visualization
* Threat detection and compliance monitoring

## Network Connectivity

```text
Internet
    │
    ▼
Tailscale Overlay Network
    │
    ▼
WireGuard Tunnel
    │
    ├── Windows Server 2019 (AD DS)
    ├── Ubuntu Client (SSSD)
    └── Rocky Linux 9 (Wazuh SIEM)
```

## Attack Simulation & Detection

### 1. Network Reconnaissance

**Technique:** Continuous ICMP Echo Requests (Ping Sweep)

**Detection:**

* Suricata successfully generated alerts
* Suspicious network reconnaissance activity identified

### 2. SSH Brute-Force Attack

**Tool Used:** Hydra

**Detection:**

* Multiple failed login attempts recorded
* Wazuh generated authentication-related alerts
* Centralized logging enabled attack visibility

### 3. SMB Brute-Force Attack

**Tool Used:** CrackMapExec

**Detection:**

* Windows authentication failures collected by Wazuh
* Triggered Rule ID 60204
* Mapped to MITRE ATT&CK T1110 (Brute Force)

## Key Outcomes

### Security Benefits

* Centralized log aggregation across multiple platforms
* Real-time threat monitoring and alerting
* Unified authentication infrastructure
* Improved visibility into network and host-based attacks

### Compliance Mapping

The solution demonstrates alignment with security monitoring requirements, including:

* PCI DSS Requirement 10 (Logging and Monitoring)
* PCI DSS 10.6.1 (Log Review)
* MITRE ATT&CK Framework Mapping

### Technologies Used

* Windows Server 2019
* Active Directory Domain Services (AD DS)
* Ubuntu Linux
* SSSD
* Suricata IDS
* Wazuh SIEM
* WireGuard
* Tailscale
* Hydra
* CrackMapExec

---

# 🎯 Learning Outcomes

Through these projects, the following cybersecurity concepts were demonstrated:

* Web Application Firewall Deployment
* Reverse Proxy Security
* Intrusion Detection Systems
* SIEM Architecture
* Centralized Authentication
* Active Directory Administration
* Threat Detection & Monitoring
* Network Security Infrastructure Design
* MITRE ATT&CK Mapping
* Security Compliance Monitoring
