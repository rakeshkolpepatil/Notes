# User Management in Linux

## Introduction to User Management in Linux
- Linux is a multi-user operating system, meaning multiple users can operate on a system simultaneously. 
- Proper user management ensures security, controlled access, and system integrity. 
- `sudo su - `  Switch the user to the root user.

Key files involved in user management:
- `/etc/passwd` – Stores user account details.
- `/etc/shadow` – Stores encrypted user passwords.
- `/etc/group`  – Stores group information.
- `/etc/gshadow` – Stores secure group details.


## Creating Users in Linux
To create a new user in Linux, use:

### `useradd` Command (For most Linux distributions)
- This creates a user without a home directory.
  ```bash
  useradd username
  ```

- To create a user with a home directory:
  ```bash
  useradd -m username
  ```

- To specify a shell:
  ```bash
  useradd -s /bin/bash username
  ```

### `adduser` Command (For Debian-based systems)
- An `interactive command` that asks for a password and additional details.

  ```bash
  adduser username
  ```

## Managing User Passwords
- To set or change a user’s password:
  
  ```bash
  passwd username
  ```

### Enforcing Password Policies
- **Password expiration**: Set password expiry days
  
  ```bash
  chage -M 90 username
  ```

- **Lock a user account**
  ```bash
  passwd -l username
  ```
- **Unlock a user account**
  ```bash
  passwd -u username
  ```

## Modifying Users
Modify an existing user with `usermod`:
- Change the username:
  ```bash
  usermod -l new_username old_username
  ```
- Change the home directory:
  ```bash
  usermod -d /new/home/directory -m username
  ```
- Change the default shell:
  ```bash
  usermod -s /bin/zsh username
  ```

## Deleting Users
- To remove a user but keep their home directory:
  
  ```bash
  userdel username
  ```

- To remove a user and their home directory:
  
  ```bash
  userdel -r username
  ```

## Working with Groups
- Groups help in managing the large number of users having similar permission requirements.
- The groups are stored in the `/etc/group` file.

### Creating Groups
```bash
groupadd groupname                 # Creates a group named 'groupname '
```

### Adding Users to Groups
```bash
usermod -aG groupname username     # Adds the user 'username' to the group 'groupname' 
```

### Viewing Group Memberships 
```bash
groups username                    # 
```

### Changing Primary Group
```bash
usermod -g new_primary_group username
```

## Sudo Access and Privilege Escalation
### Adding a User to Sudo Group

- On Debian-based systems:
  ```bash
  usermod -aG sudo username
  ```

- On RHEL-based systems:
  ```bash
  usermod -aG wheel username
  ```

### Granting Specific Commands with Sudo
- Edit the sudoers file:

  ```bash
  visudo
  ```

- Then add:
  ```bash
  username ALL=(ALL) NOPASSWD: /path/to/command
  ```

### Logging in into a Linux machine for a user 
- The `SSH daemon (sshd)` is the process that enables secure remote connections to a Linux machine. 

- It is not enabled by default on all distributions, but when running, it listens for incoming `SSH connections` and allows users to access the system remotely.

- `SSH clients` are programs that initiate secure, remote connections to other machines running an `SSH server (daemon)`. 

- They enable users to access, manage, and transfer files to remote systems over an encrypted channel. 

- The `SSH client` runs on the local machine and connects to the remote machine where the SSH server (`usually sshd`) is running, allowing secure command execution and file transfer.

  ```bash
  Git Bash - SSH Client for windows 
  Terminal - !term2 for mac
  ```

- To enable password login for SSH, set `PasswordAuthentication yes` in your SSH server configuration (which may be `/etc/ssh/sshd_config.d/60-clouding-settings.conf` on your system), then restart the SSH service

- Also, make sure that other settings (like `PermitRootLogin` if logging in as root, or user restrictions) are not preventing password authentication.

  ```bash
  # Step 1
  vim /etc/ssh/sshd_config.d/60-clouding-settings.conf
  
  # Step 2
  PasswordAuthentication Yes
  
  # Step 3
  sudo systemctl restart ssh
  ```