# Understanding the Folder Structure

### Explanation of System Directories
- `ubuntu@hostname:~/`   
  - `ubuntu` is the name of the user.
  - `hostname` is the name of the system.
  - `~/` is the home directory of the user named `ubuntu` and is shortcut for `/home/ubuntu` directory.
  - `/root` - This is home directory of root user 
  - `/home/$user` - Home directories of all other users.

- `PATH` variable stores the list of paths that need to be searched for the commands that are issued in the shell. 

### **Symbolic Links (Less Significant)**
| Directory | Description |
|-----------|-------------|
| `/sbin -> /usr/sbin` | System binaries for administrative commands (linked to `/usr/sbin`). Access is usually restricted to root users or admin users |
| `/bin -> /usr/bin` | Essential user binaries (linked to `/usr/bin`). Usually accessible to all users. Contains most standard Shell Commands |
| `/lib -> /usr/lib` | Shared libraries and kernel modules (linked to `/usr/lib`). |

### **Important System Directories**
| Directory | Description                                                              |
|-----------|--------------------------------------------------------------------------|
| `/boot`   | Stores files needed for booting the system (not relevant in containers). |
| `/usr`    | Contains most user-installed applications and libraries.                 |
| `/var`    | Stores logs, caches, and temporary files that change frequently.         |
| `/etc`    | Stores system configuration files. Similar to `C:/` folder in windows    |

- `/etc/passwd`   
  - Using `passwd` you can change password of any user.
- `/etc/hosts`  
  - Acts as local DNS cache file.
- `/etc/os-release`
  - This file contains all the information details of Linux environment OS.


### **User & Application-Specific Directories**
| Directory | Description                                                           |
|-----------|-----------------------------------------------------------------------|
| `/home`   | Default location for user home directories.                           |
| `/opt`    | Used for installing optional third-party software.                    |
| `/srv`    | Holds data for services like web servers (rarely used in containers). |
| `/root`   | Home directory for the root user. For other users home directory is at `/home/$User` |

### **Temporary & Volatile Directories**
| Directory | Description                                             |
|-----------|---------------------------------------------------------|
| `/tmp`    | Temporary files (cleared on reboot or as per custom criteria). |
| `/run`    | Holds runtime data for processes.                       |
| `/proc`   | Virtual filesystem for process and system information.  |
| `/sys`    | Virtual filesystem for hardware and kernel information. |
| `/dev`    | Contains device files (e.g., `/dev/null`, `/dev/sda`).  |

### **Mount Points**
| Directory | Description                                                     |
|-----------|-----------------------------------------------------------------|
| `/mnt`    | Temporary mount point for external filesystems.                 |
| `/media`  | Mount point for removable media (USB, CDs).                     |
| `/data`   | Likely your **mounted volume** from Windows (`C:/ubuntu-data`).  To store data that you want to share with other members of your organization|