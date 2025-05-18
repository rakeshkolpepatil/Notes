# Networking Commands

## **`1. ping google.com`** 

-  Checks connectivity to a remote server.

- It is a network utility used for testing the reachability of a host (such as a server, device, or website) on an IP network and diagnosing connectivity issues. 

- It works by sending `ICMP (Internet Control Message Protocol) Echo Request packets` to a specified destination and waits for `Echo Reply packets` in return.
- 
  | Option |  Description                                       |
  |------- |  ------------------------------------------------  |
  |  -c	   |  Sets the number of packets to send                |
  |  -i	   |  Changes the interval between sending packets      |
  |  -a	   |  Plays a sound when the destination responds       |
  |  -q	   |  Outputs only a summary after completion           |
  |  -v	   |  Enables verbose output                            |
  |  -4/-6 |  Forces use of IPv4 or IPv6                        |
  |  -s	   |  Sets the packet size                              |
  |  -W/-w |  Sets timeout for each packet/session              |
  |  -f	   |  Floods the target with packets (for stress tests) |

### Example Usage

```bash
# 1. Check connectivity to a website:
ping google.com

# 2. Send a specific number of packets (e.g., 4):
ping -c 4 192.168.1.1

# 3. Check if a local device is reachable:
ping localhost
```

### Use Cases
- Troubleshooting network connectivity issues
- Measuring network latency and packet loss
- Checking if a server or device is online
- Diagnosing DNS resolution problems


## **`2. ifconfig`** 
- Displays network interfaces (deprecated, use `ip`).

## **`3. ip a`** 
- Shows IP addresses of network interfaces.

## **`4. netstat -tulnp`** 
- Displays open network connections.

## **`5. curl https://example.com`** 
- Fetches a webpage's content.
- Used in Linux to transfer data to or from a server using various protocols such as `HTTP`, `HTTPS`, `FTP`, and more. 
- It is widely used for **downloading files**, **testing APIs**, and **interacting with web servers directly from the terminal**.
- Handles cookies, authentication, proxies, and custom headers.

  | Option | Description	                           |  Example                                           |
  |--------| -------------------------------------   |----------------------------------------------------|
  |  `-O`	 | Save the file with its original name	   |  `curl -O https://example.com/file.zip`            |
  |  `-o`	 | Save output to file with specified name |  `curl -o myfile.zip https://example.com/file.zip` |
  |  `-d`	 | Send data in a POST request	           |  `curl -d "key=value" https://example.com/api`     |
  |  `-X`	 | Specify HTTP method (GET, POST, etc)	   |  `curl -X POST https://example.com/api`            |
  |  `-u`	 | Provide username and password	         |  `curl -u user:pass https://example.com`           |
  |  `-I`	 | Fetch only HTTP headers	               |  `curl -I https://example.com`                     |
  |  `-L`	 | Follow redirects	                       |  `curl -L https://example.com`                     |
  |  `-H`	 | Add custom headers	                     |  `curl -H "Authorization: Bearer token" https://example.com`|
  |  `-s`	 | Silent mode (no progress/output)	       |  `curl -s https://example.com`                     |
  |  `-v`	 | Verbose output (debugging)	             |  `curl -v https://example.com`                     |
  |  `-k`	 | Allow insecure SSL connections	         |  `curl -k https://example.com`                     |

### Examples 
  
  ```bash
  curl https://www.example.com                  # HTTP GET request
  curl -O https://www.example.com/file.zip      # Downloads the file and saves it with its original name
  
  # Sends data to the server using POST
  curl -X POST -d "param1=value1&param2=value2" https://www.example.com/api
 
  # Include HTTP Headers in Output - Displays both the response headers and body
  curl -i https://www.example.com

  # Add Custom HTTP Header - Useful for API authentication
  curl -H "Authorization: Bearer <token>" https://www.example.com/api

  ```

## **`6. wget https://example.com/file.zip`** 
- Downloads a file from the internet and stores it locally for future use.
- `Wget` is used to download files from the internet using HTTP, HTTPS, and FTP protocols. 
- It is especially useful for downloading files **non-interactively**, **allowing processes to continue even if you are not logged in** or **if the connection is interrupted**.

### Key Features
1. Supports `HTTP`, `HTTPS`, and `FTP` protocols.
2. Can resume interrupted downloads with the `-c` or `--continue` option.
3. Allows recursive downloads and mirroring of entire websites.
4. Works in the background and can be used in scripts and cron jobs.
5. Supports proxy, authentication, and custom headers.

### Common wget Options and Examples
  
  | Option/Example	          |  Description                                                          |
  | ------------------------- | ----------------------------------------------------------------------|
  | `wget [URL]`	             |  Download a file from the specified URL.                             |
  | `wget -c [URL]`	           |  Resume an interrupted download.                                     |
  | `wget -O [filename] [URL]` |  Save the downloaded file with a custom name.                        |
  | `wget -r [URL]`	           |  Download files recursively (e.g., entire directories or websites).  |
  | `wget --mirror [URL]`	     |  Mirror an entire website, including all necessary files.            |
  | `wget --ftp-user=USER --ftp-password=PASS ftp://...` | Download files via FTP with authentication. |
  | `wget -t [number] [URL]`	 |  Set the number of retries for a download.                           |
  | `wget -o [logfile] [URL]`	 |  Write output and errors to a log file.                              |
  | `wget --spider [URL]`	     |  Check if a file exists at the URL without downloading it.           |

### Advanced Usage
  
  ```bash
  # Download multiple files - List URLs in a file and use:
  wget -i [file_with_urls.txt]
  
  # Download using FTP:
  wget --ftp-user=USERNAME --ftp-password=PASSWORD ftp://example.com/file.tar.
  
  # Download a range of files:
  wget http://example.com/images/{1..50}.jpg.
  
  # Mirror a website for offline viewing:
  wget --mirror --convert-links --page-requisites --no-parent -P local_dir/ https://example.com.
  ```


## 🔐 `ssh-copy-id` vs `ssh-keygen`

| Tool          | Purpose                                                                  | Usage Example                               |
| ------------- | ------------------------------------------------------------------------ | ------------------------------------------- |
| `ssh-keygen`  | **Generates** a new SSH key pair (private + public keys).                | `ssh-keygen -t rsa -b 4096 -C "your_email"` |
| `ssh-copy-id` | **Copies** the public key to a remote server’s `~/.ssh/authorized_keys`. | `ssh-copy-id user@remote-host`              |

### ✅ **Use `ssh-keygen` When:**
- You need to **create** a new key pair on your local machine.
- You want to use SSH key-based authentication.
- Example steps:

    ```bash
    ssh-keygen -t rsa -b 4096 -C "me@example.com"
    # keys saved in ~/.ssh/id_rsa and ~/.ssh/id_rsa.pub
    ```

### ✅ **Use `ssh-copy-id` When:**
- You already have a public key (`~/.ssh/id_rsa.pub`) and want to **enable passwordless SSH login** to a remote server.
- It **appends** your public key to the remote user’s `authorized_keys` file inside `/home/user/.ssh/` safely.
- Example 1:

    ```bash
    ssh-copy-id user@remote-server
    # You will enter the remote password once; after that, SSH becomes passwordless.
    ```

- Example 2:
  
  ```
  # IdentityFile should be 'private key'
  ssh-copy-id -f "-o IdentityFile <PATH TO PEM FILE>" ubuntu@<INSTANCE-PUBLIC-IP>
  
  # OR 
  ssh-copy-id -f -o IdentityFile=~/.ssh/mykey user@hostname

  # OR = copy key for the AWS server for setting up passwordless server access. Generate 'AnsibleNode1.pem' file while creating EC2 instance. 
  ssh-copy-id -f -o IdentityFile=/mnt/c/Users/John/aws_server/AnsibleNode1.pem  ubuntu@172.90.91.150
  ```

  - `ssh-copy-id` : This is the command used to copy your public key to a remote machine.
  - `-f` : This flag forces the copying of keys, which can be useful if you have keys already set up and want to overwrite them.
  - `"-o IdentityFile <PATH TO PEM FILE>"` : This option specifies the identity file (private key) to use for the connection. The -o flag passes this option to the underlying ssh command.
  - `ubuntu@<INSTANCE-IP>` : This is the username (ubuntu) and the IP address of the remote server you want to access.

### 🔁 **Typical Workflow:**
1. Generate key with `ssh-keygen` (once per machine).
2. Copy key to server with `ssh-copy-id`.
