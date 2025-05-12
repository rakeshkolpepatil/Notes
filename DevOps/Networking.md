# Networking Concepts
[Video Link](https://youtu.be/PhTn8RkF0F4?list=PLdpzxOOAlwvIBIRWcReRV-m2kgIW6V6gr)

## IP address

### 1. **Definition & Purpose**
- An **IP address** (Internet Protocol address) is a unique identifier assigned to each device connected to a network using the Internet Protocol.
- It enables devices to locate and communicate with each other across local networks and the internet.
- Functions:
  - **Identification:** Uniquely identifies a device on a network.
  - **Location Addressing:** Helps in routing packets to the correct destination.

---

### 2. **Versions of IP Address**

#### **IPv4 (Internet Protocol version 4)**
- **Format:** 32 bits, divided into four 8-bit octets (e.g., `192.168.10.5`).
- **Address Range:** ` 0.0.0.0 ` to ` 255.255.255.255 ` (~4.3 billion unique addresses).
- **Representation:** Dotted-decimal notation.
- **Exhaustion:** Due to the rapid growth of the internet, IPv4 addresses are nearly exhausted.

#### **IPv6 (Internet Protocol version 6)**
- **Format:** 128 bits, divided into eight 16-bit blocks (e.g., `2001` `:` `0db8` `:` `85a3` `:` `0000` `:` `0000` `:` `8a2e` `:` `0370` `:` `7334`).
- **Address Range:** Vastly larger (`about 3.4 × 10³⁸ addresses`).
- **Representation:** Hexadecimal numbers separated by colons.
- **Features:** Built-in security (`IPSec`), simplified header, `no need for NAT`, supports auto-configuration.

---

### 3. **Structure of IP Address**

#### **Network and Host Portions**
- An IP address is divided into:
  - **Network ID:** Identifies the network segment.
  - **Host ID:** Identifies the specific device within that network.
- The division is determined by the **subnet mask** (e.g., 255.255.255.0).

#### **Classes (IPv4)**
- **Class A:**  `1.0.0.0` - `126.255.255.255` (large networks)
- **Class B:**  `128.0.0.0` – `191.255.255.255` (medium-sized networks)
- **Class C:**  `192.0.0.0` – `223.255.255.255` (small networks)
- **Class D:**  `224.0.0.0` – `239.255.255.255` (multicast)
- **Class E:**  `240.0.0.0` – `255.255.255.255` (reserved for research)

  | Class	| Leading Bits (MSB) | Binary Pattern (First Octet)	| Address Range             |  Use Case             |
  |------	| ------------------ | ---------------------------- |-------------------------- | --------------------- |
  | A     | 0	                 | `0xxxxxxx`	                  |`0.0.0.0` – `127.255.255.255`  | Large Networks        |
  | B     | 10	               | `10xxxxxx`	                  |`128.0.0.0` – `191.255.255.255`| Medium-sized Networks |
  | C     | 110	               | `110xxxxx`	                  |`192.0.0.0` – `223.255.255.255`| small Networks        |
  | D     | 1110	             | `1110xxxx`	                  |`224.0.0.0` – `239.255.255.255`| multicast             |
  | E     | 1111	             | `1111xxxx`	                  |`240.0.0.0` – `255.255.255.255`| reserved for research |

- The address `127.0.0.0` to `127.255.255.255` is reserved for **loopback and diagnostic purposes**, not for general network use.  
- `127.0.0.1` is the standard loopback address used for localhost, while `127.0.0.0` is the network address for the loopback range and not used directly for loopback communication.    

#### `0.0.0.0`
- **Placeholder/Unassigned Address** : When a device has not yet been assigned a valid IP address (such as during system startup or before receiving a DHCP lease), it may use `0.0.0.0` as its source address to indicate "no address assigned".

- **Default Route** : In routing tables, `0.0.0.0` is used to represent the default route, meaning "any address not otherwise specified".

- **Listen on All Interfaces** : When configuring servers or network services, binding to `0.0.0.0` means the service will accept connections on all available IPv4 addresses of the host machine.

- **Unreachable/Invalid Target** : It can also indicate an invalid, unknown, or non-applicable target address

<br>

## 4. **Types of IP Addresses**

#### **Public IP Address**
- Routable on the global internet.
- Assigned by ISPs or network administrators.
- Must be unique across the entire internet.

#### **Private IP Address**
- Used within private networks (LANs).
- Not routable on the public internet.
- Common ranges (as per RFC 1918):
  - `10.0.0.0` – `10.255.255.255`
  - `172.16.0.0` – `172.31.255.255`
  - `192.168.0.0` – `192.168.255.255`

#### **Static vs. Dynamic IP Address**
- **Static IP:** Manually configured, does not change. Useful for servers, network devices.
- **Dynamic IP:** Assigned by DHCP server, can change over time. Common for client devices.

<br>

## 5. **Addressing Methods**

### **`Unicast`**
- One-to-one communication.
- A packet is sent from one source to one specific destination.

### **`Broadcast (IPv4 only)`**
- One-to-all communication within a network segment.
- Broadcast address (e.g., `255.255.255.255`) sends data to all devices in the subnet.

### **`Multicast`**
- One-to-many communication for a group of interested receivers.

- Multicast addresses: `224.0.0.0` to `239.255.255.255` (IPv4).
- Efficient for streaming media, conferencing.
- Multicast is a network communication method where data is sent from one source to multiple receivers simultaneously, but only to those who have expressed interest in receiving the data. - This is more efficient than broadcasting (which sends to all devices) and unicasting (which sends individual copies to each receiver).

#### Class D IP Address Range:

- The Class D IP address range is `224.0.0.0` to `239.255.255.255`.

- These addresses are not assigned to individual devices, but to multicast groups. 
- Devices interested in receiving specific multicast traffic "join" the relevant group address.

#### How Multicast Works:

- The sender transmits data to a multicast group address (in the Class D range).

- Only devices that have joined this multicast group receive the data; others do not, reducing unnecessary network traffic.

- The source IP address in multicast packets is always **a unicast address (the sender)**, while the destination IP address is a **multicast (Class D) address**.

- Routers replicate and forward multicast packets only to network segments with interested receivers, optimizing bandwidth use.

#### Applications:

- Commonly used for streaming media (audio/video), real-time data feeds (e.g., stock market updates), online conferencing, and IPTV.

#### Technical Details:

- The first four bits of a Class D address are always `'1110'`, ensuring the address falls within the multicast range.

- There is **no subnet mask associated with Class D addresses**; they are used solely as group identifiers for multicast traffic.

- Hosts must "join" a multicast group (using protocols like IGMP) to receive traffic sent to a particular Class D address.

### **`Anycast (mainly IPv6)`**
- One-to-nearest communication.
- Same address assigned to multiple devices; data is routed to the closest one.
- Used in DNS, CDN networks.

<br>

## 6. **Subnetting and CIDR**

### **Subnetting**
- Divides a large network into smaller, manageable sub-networks (subnets).
- Improves network performance and security.
- Achieved by manipulating the subnet mask (e.g., 255.255.255.0).

### **CIDR (Classless Inter-Domain Routing)**
- Replaces class-based addressing.
- Uses variable-length subnet masking (VLSM).
- Notation: IP address/Prefix length (e.g., 192.168.1.0/24).
  - **/24** means first 24 bits are the network part.


### **Subnetting**
#### Definition:
- Subnetting is the **process of dividing a larger IP network into smaller, more manageable subnetworks** (**subnets**).
- Each subnet operates as a distinct network segment, allowing better organization, security, and efficient use of IP address space.

#### How Subnetting Works:
- An IP address consists of two parts: **the network ID** **(identifies the network segment)** and **the host ID** **(identifies the device within that segment)**.
- Subnetting borrows bits from the host portion to create additional network segments within the original network.
- A subnet mask is used to distinguish the network and host portions. 
- For example, a subnet mask of `255.255.255.0` (binary: `11111111.11111111.11111111.00000000`) means the first 24 bits are the network part, and the last 8 bits are for hosts.

#### Benefits of Subnetting:
- Reduces network congestion by limiting broadcast domains.
- Enhances security by isolating network segments.
- Simplifies management and troubleshooting.
- Allows efficient IP address utilization by tailoring subnet sizes to specific needs.

#### Example:
- Given a network 192.168.1.0/24 (255.255.255.0), subnetting with a mask of 255.255.255.192 (/26) creates four subnets, each with 64 addresses.

### **CIDR (Classless Inter-Domain Routing)**
#### Definition:
- CIDR is a method for allocating IP addresses and routing that replaces the rigid classful addressing system.
- Introduced in 1993, CIDR allows for **variable-length subnet masking (VLSM)**, enabling more flexible and efficient use of IP address space.

#### CIDR Notation:
- CIDR uses a slash (`"/"`) notation to specify the network prefix length, e.g., `192.168.0.0/24`.
- The number after the slash indicates how many bits are used for the network portion.
- The remaining bits are used for host addresses.

#### Example: 
- `10.0.0.0/16` means the first 16 bits are the network prefix, leaving 16 bits for hosts.

#### How CIDR Works:
- Instead of being limited to fixed class boundaries (A, B, C), CIDR allows the network prefix to be any length, enabling custom-sized subnets and efficient address allocation.
- CIDR enables route aggregation (supernetting), reducing the size of routing tables and improving routing efficiency.

#### Benefits of CIDR:
- **Reduces IP address wastage** : Allocates only as many addresses as needed.
- **Improves routing efficiency** : Aggregates multiple networks into a single routing table entry (route summarization).
- **Supports hierarchical network design** : Facilitates scalable and flexible network architecture.

#### Example of CIDR Subnetting:
- A network `10.0.0.0/24` can be split into two subnets:
  - `10.0.0.0/25` (addresses `10.0.0.0` – `10.0.0.127`)
  - `10.0.0.128/25` (addresses `10.0.0.128` – `10.0.0.255`)

- Each subnet has 128 addresses, and the division is not restricted by traditional class boundaries.

### Key Differences: Subnetting vs. CIDR
-
  | **Feature**	        | **Subnetting (Traditional)**	     | **CIDR (Classless)**                  |
  | ------------------- | ---------------------------------- | ------------------------------------- |
  | Based On	          | Fixed class boundaries (A, B, C)	 | Variable-length subnet masking (VLSM) |
  | Notation	          | Subnet mask (e.g., `255.255.255.0`)| Slash notation (e.g., `/24`)          |
  | Flexibility	        | Limited                            | Highly flexible                       |
  | Address Efficiency  | May waste addresses	               | Minimizes address wastage             |
  | Routing	            | Larger routing tables	             | Enables route aggregation             |


## 7. **IP Address Management**

- **IANA (Internet Assigned Numbers Authority):** Manages global IP address allocation.
- **RIRs (Regional Internet Registries):** Allocate blocks to ISPs and organizations (e.g., ARIN, RIPE, APNIC).


## 8. **How IP Addresses Work in Communication**

- When a device wants to communicate, it uses the destination device’s IP address to send packets.
- Routers use IP addresses to determine the best path for data delivery.
- Each packet contains:
  - **Source IP address**
  - **Destination IP address**


## 9. **Key Points and Best Practices**

- Every device on a network must have a unique IP address.
- IP addresses are essential for routing and communication.
- Use private IPs for internal networks; public IPs for internet-facing devices.
- Subnetting helps in efficient IP address utilization and network security.
- IPv6 adoption is increasing due to IPv4 exhaustion.


## 10. **Additional Concepts**

#### **NAT (Network Address Translation)**
- Allows multiple devices on a private network to share a single public IP address.
- Commonly used in home and office networks.

#### **Loopback Address**
- `127.0.0.1` (IPv4) or `::1` (IPv6).
- Used to test network software without physically transmitting packets.

#### **APIPA (Automatic Private IP Addressing)**
- When DHCP fails, Windows assigns an address in 169.254.0.0/16 range.


## OSI Reference Model: Layers and Protocols
- **The OSI (Open Systems Interconnection) reference model** is a conceptual framework **developed by the International Organization for Standardization (ISO)** to standardize the functions of a communication system into seven abstraction layers. 
- This model **helps in understanding and designing interoperable network protocols and devices**.

### The 7 Layers of the OSI Model
- | Layer	|   Name	     | Function	                                                               | Example Protocols    |
  | ------|------------- | ----------------------------------------------------------------------- | -------------------- |
  |   7	  | Application	 | User interface and network services for applications	                   | HTTP, FTP, SMTP, DNS |
  |   6	  | Presentation | Data translation, encryption/decryption, and compression	               | SSL/TLS, JPEG, ASCII |
  |   5	  | Session	     | Establishes, manages, and terminates sessions (connections)	           | NetBIOS, RPC, PPTP   |
  |   4	  | Transport	   | Reliable data transfer, error recovery, and flow control	               | TCP, UDP             |
  |   3	  | Network	     | Logical addressing, routing, and forwarding	                           | IP, ICMP, IGMP       |
  |   2	  | Data Link	   | Physical addressing, error detection/correction, and frame delimitation | Ethernet, PPP, ARP   |
  |   1	  | Physical	   | Transmission of raw bits over a physical medium	                       | Ethernet (physical), USB |

### Layer-by-Layer Explanation with Protocols
#### 1. Physical Layer (Layer 1)
- **Function**: Transmits raw bit streams (0s and 1s) over the physical medium (cables, radio, etc.). Defines hardware standards, voltages, pin layouts.

- **Examples**: Ethernet cables, fiber optics, USB, Bluetooth.

#### 2. Data Link Layer (Layer 2)
- **Function**: Packages raw bits from the physical layer into frames, provides node-to-node data transfer, error detection, and flow control.
- **Examples**: Ethernet, PPP, ARP, HDLC, Frame Relay.

#### 3. Network Layer (Layer 3)
- **Function** : Handles routing, logical addressing (IP addresses), and forwarding packets between networks. Decides the best path for data.
- **Examples** : IP (Internet Protocol), ICMP, IGMP, IPsec.

#### 4. Transport Layer (Layer 4)
- **Function** : Ensures reliable data transfer between hosts, provides segmentation, error recovery, and flow control.
- **Examples** : TCP (Transmission Control Protocol), UDP (User Datagram Protocol).

#### 5. Session Layer (Layer 5)
- **Function** : Manages sessions (connections) between applications, establishes, maintains, and terminates connections, synchronization.
- **Examples** : NetBIOS, RPC, PPTP.

#### 6. Presentation Layer (Layer 6)
- **Function** : Translates data between the application and network, handles data encryption/decryption and compression.
- **Examples** : SSL/TLS, JPEG, GIF, ASCII, EBCDIC.

#### 7. Application Layer (Layer 7)
- **Function** : Provides network services directly to end-user applications, such as web browsers and email clients.
- **Examples** : HTTP, FTP, SMTP, DNS, POP3, IMAP.

#### Key Points
- Each layer serves the layer above and is served by the layer below, ensuring modularity and interoperability.
- Protocols are standardized rules and formats that operate at each layer to enable communication between devices and systems.
- The OSI model is primarily used for teaching, troubleshooting, and conceptualizing networking, while real-world networks often use the TCP/IP model, which maps roughly onto the OSI layers.
