# Linux System Monitoring

## Introduction to System Monitoring
- Monitoring system resources is essential **to ensure optimal performance**, **detect issues**, and **troubleshoot problems in Linux**. 
- Various tools allow us to **monitor CPU**, **memory**, **disk usage**, **network activity**, and **running processes**.

## Index of Commands Covered

## CPU and Memory Monitoring
### `1. top` 
- Real-time system monitoring

### `2. htop` 
- Interactive process viewer (requires installation)

### `3. vmstat` 
- Report system performance statistics

#### Output Fields
- The output of vmstat is typically divided into several sections:
  
  - **Processes**   
    Number of running and blocked processes.
  
  - **Memory**  
    Free and used memory, buffers, and cache.
  
  - **Swap**  
    Swap in/out activity.
  - **I/O**  
    Blocks read/written per second.
  - **System**  
    Interrupts and context switches per second.
  - **CPU**  
    Percentage of CPU time spent in user, system, and idle modes.

#### Example Output
  ```text
  procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
   r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
   1  0      0  12345  67890  23456    0    0     0     1    2    3  2  1 97  0  0
  ```
  
  - **`r`**  : Processes waiting for run time
  - **`b`**  : Processes in uninterruptible sleep
  - **`swpd`**  : Amount of virtual memory used
  - **`free`**  : Idle memory
  - **`buff/cache`**  : Memory used as buffers/cache
  - **`si/so`**  : Swap in/out per second
  - **`bi/bo`**  : Blocks received/sent to block device
  - **`in/cs`**  : Interrupts/context switches per second
  - **`us/sy/id/wa/st`**  : Percentage of CPU time in user/system/idle/wait/steal modes

### `free -m` 
- Show memory usage

## Disk Monitoring
- `df -h` – Check disk space usage

- `du -sh /path` – Show disk usage of a specific directory
- `iostat` – Display CPU and disk I/O statistics

## Network Monitoring
- `ifconfig` – Show network interfaces (deprecated, use `ip a`)

- `ip a` – Show network interface details
- `netstat -tulnp` – Show active connections and listening ports
- `ss -tulnp` – Alternative to `netstat` for socket statistics
- `ping hostname` – Test network connectivity
- `traceroute hostname` – Show network path to a host
- `nslookup domain` – Get DNS resolution details

## Log Monitoring
- `tail -f /var/log/syslog` – Live monitoring of system logs

- `journalctl -f` – Live system logs for systemd-based distros
- `dmesg | tail` – View kernel logs

## CPU and Memory Monitoring
### Using `top`
- To view real-time CPU and memory usage:
  
  ```bash
  top
  ```
- Press `q` to quit.

### Using `htop`
- A user-friendly alternative:
  ```bash
  htop
  ```
- Use arrow keys to navigate and `F9` to kill processes.

### Using `vmstat`
- To check CPU, memory, and I/O stats:
  ```bash
  vmstat 1 5  # Update every 1 sec, show 5 updates
  ```

### Checking Memory Usage
- Shows free and used memory in megabytes.
- used for quickly checking memory and swap usage
- The `available` column is the best indicator of **how much memory is truly free** for new applications, as it considers reclaimable cache and buffers
  
  ```bash
  free -m
  ```
- Common options:
  - `-m` : Show output in megabytes.
  
  - `-g` : Show output in gigabytes.
  - `-h` : Show output in a human-readable format (e.g., MB, GB).
  - `-s <seconds>` : Continuously updates the output every specified number of seconds.
  - `-t` : Shows a total line for RAM + swap.

<br>
<br>

# Disk Monitoring
### Using `df`
- Check available disk space:
- A standard Linux utility used to report the amount of disk space used and available on mounted filesystems.
  
  ```bash
  # option displays sizes in KB, MB, or GB making output human readable 
  df -h     
  
  # Display specific file system
  df -h /path/to/directory

  # Lists only filesystems of type ext4 in human-readable format
  df -ht ext4
  
  # Show all filesystems, including pseudo, duplicate, and inaccessible filesystems.
  df -a 

  # Show inode usage instead of block usage.
  df -i 

  # Customize output columns
  df --output=source,size,used,avail 
  ```

### `df Vs free`
-
  | Aspect	         | df Command	                                               | free Command                         | 
  | ---------------- | -----------------------------------------------------     | ----------------------------------   | 
  | Purpose	         | Reports disk (filesystem) space usage and free space      |	Reports RAM (memory) and swap usage |
  | What it measures | Storage space on mounted filesystems (e.g., `/`, `/home`) |	System memory (RAM) and swap        |
  | Output columns	 | Filesystem, Size, Used, Avail, Use%, Mounted on	         | total, used, free, shared, buff/cache, available |
  | Typical use	     | Checking how much disk space is used/available            |	Checking how much memory is used/available |
  | Example usage	   | `df -h`	                                                 | `free -h`                            |


### Using `du`
- Find the size of a directory

- Identifying which directories or files are consuming the most disk space.
- Cleaning up unnecessary large files to free up space.
- Common Options
  - `-h` : Show sizes in human-readable format (e.g., KB, MB, GB).
  
  - `-s` : Display only the total size for each specified argument, rather than listing every subdirectory.
  - `-a` : Include files as well as directories in the output.
  - `--max-depth=N ` : Limit output to directories up to N levels below the specified directory.
  - `--exclude=PATTERN ` : Exclude files or directories matching the pattern from the calculation.


  ```bash
  # Summarize total disk usage for a directory
  du -sh /var/log
  
  # Show disk usage for a directory and its subdirectories in human-readable format
  du -h /path/to/directory

  # List disk usage for all directories one level below the current directory
  du -h --max-depth=1 .

  # Sort directories by size
  du -h /path/to/directory | sort -h
  ```

### Using `iostat`
- provides detailed real-time Input/Output Statistics on CPU and disk I/O usage.
- Used to 
  - identify **disk I/O bottlenecks** and high wait times, 
  
  - monitor **CPU and disk usage trends**, 
  - **balance I/O load across disks** for better performance and 
  - **troubleshoot slow applications** or system responsiveness

- Check disk and CPU usage:

  ```bash
  iostat             # Displays a summary of CPU and device statistics since the last reboot.
  iostat -c          # Show only CPU utilization
  iostat -d          # Show only device (disk) utilization. 
  iostat -h          # Human-readable output.
  iostat -d /dev/sda # Statistics for a specific device
  iostat 2           # Continuous monitoring every 2 seconds
  iostat 2 5         # Report for a specific number of intervals
  ```
<br>
<br>

# Network Monitoring

## `ip (replacement of older 'ifconfig')` - Checking Network Interfaces
- Displays all network interfaces (physical and virtual) on the system along with their associated IP addresses and detailed configuration information
- Includes both `IPv4` and `IPv6` addresses, `interface states` (`up/down`), `MAC addresses`, and other relevant parameters

  ```bash
  ip a                     # Show IP addresses and interfaces
  ip -4 a                  # List only IPv4 addresses
  ip -6 a                  # List only IPv6 addresses
  ip addr show dev eth0    # See information for a specific interface 
  ```

## Viewing Open Ports and Connections
- Lists all `TCP (-t)` and `UDP (-u)` ports that are currently in the `listening state (-l)`, shows numerical addresses and `port numbers (-n)`, and displays the `PID/program name of the process using the port (-p)`.

  ```bash
  netstat -tulnp         # Show listening ports
  ss -tulnp              # Alternative to netstat ( faster/ more efficient)
  ```

## Testing Connectivity
### `ping`
- Checks if your system can reach Google’s servers and measures network latency.

- Sends ICMP Echo Request packets to google.com and waits for Echo Reply responses.
- If you receive replies, your internet connection is working.
- The output shows response times (latency), packet loss, and other network statistics.
- If you see "request timed out" or no replies, there may be a connectivity issue

  ```bash
  ping google.com        # Test internet connection - default, this sends continuous pings
  ping -c 4 google.com   # Send only 4 packets
  ```

### `traceroute`
- Shows the route your packets take through the network to reach Google, listing each hop (router) along the way.

- Sends packets with increasing Time-To-Live (TTL) values, revealing each router that handles the packet until it reaches the destination
- Shows IP addresses and response times for each hop, helping diagnose where delays or failures occur
- Useful for troubleshooting network routing issues and pinpointing where connectivity problems arise

  ```bash
  traceroute google.com  # Trace the path to Google
  ```

## Checking DNS Resolution
- The command `nslookup example.com` is used to query DNS servers for information about the domain `"example.com."`

- `nslookup example.com` provides the A record (IPv4 address) for the domain.

- `nslookup` can be used for other types of DNS records (e.g., MX, NS) by specifying options like `-type=mx` or `-type=ns`.
- Returns the `IP address(es)` associated with the domain, along with `details about the DNS server that provided the answer`.
- useful for troubleshooting DNS issues and verifying domain resolution

  ```bash
  nslookup example.com
  ```
<br>
<br>

# Log Monitoring

## Live Monitoring of System Logs

### `tail` 
- Continuously displays new lines added to the /var/log/syslog file as they arrive.

  ```bash
  tail -f /var/log/syslog        # Follow logs in real-time
  ```

### `journalctl`
- Streams new log entries from the systemd journal as they are generated, similar to `tail -f` but for journal-based logs

- Ideal for systems running `systemd`, as it captures logs from all services and the kernel, not just those written to text files.

- Provides real-time updates from the binary journal, allowing for advanced filtering, searching, and integration with systemd features

  ```bash
  journalctl -f                               # Systemd logs
  journalctl -u <service> -f                  # Filter by service
  journalctl -f -p err                        # Filter by priority: (shows only errors)
  journalctl --since="1 hour ago" -f          # Filter by time 
  journalctl -n 20 -f                         # Limit initial output: (show last 20 lines, then follow)
  ```

## Checking Kernel Logs
- The command `dmesg | tail` displays the most recent kernel messages from the Linux kernel ring buffer, which include information about `hardware initialization`, `driver loading`, `device connections/disconnections`, and other `kernel-level events`.

- Commonly used for `real-time troubleshooting` 
- For example, **to check for new hardware events**, **errors, or driver messages that have occurred most recently**, such as when plugging in a USB device or diagnosing hardware issues



```bash
dmesg | tail
```