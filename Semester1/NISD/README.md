# Assigment: Layer 7 WAF Implementation

**ByteBandit Shield** is a cybersecurity project focusing on the deployment and configuration of a Web Application Firewall (WAF). It demonstrates how to protect a vulnerable e-commerce application from **Reflected Cross-Site Scripting (XSS)** and **SQL Injection (SQLi)** using a containerized "Defense-in-Depth" architecture.

---

## Architecture & Topology

The system is built on a modern containerized stack, simulating a real-world enterprise gateway:

1.  **Vulnerable Target:** A custom PHP-based "Tech Store" (Apache) running on Port `8080`.
2.  **Security Gateway:** Nginx Proxy Manager (NPM) acting as a Reverse Proxy and Layer 7 WAF on Port `80`.
3.  **Encrypted Perimeter:** Cloudflare Tunnel providing a secure public entry point without opening local firewall ports.

---

##  Features & Security Hardening

While standard WAFs offer basic protection, this project implements **Manual Regex Filtering** to mitigate advanced bypasses such as URL encoding and case-sensitivity variations.

### **Custom Nginx Security Rules**
These rules were implemented in the **Advanced** configuration of the Nginx Proxy Host:

```nginx
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
