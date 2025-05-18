# File Permissions Management in Linux
- File permissions are a core feature of Linux, integrated into the operating system by default and requiring no additional installation.
- File permissions work closely with user and group management.

- Permissions are represented as `read (r)`, `write (w)`, and `execute (x)` for each user class (`owner`, `group`, `others`). 
- By default, Linux configures File permissions on each file and folder.
- These default permissions can be viewed using commands like `ls -l` and modified with commands such as `chmod (Change Mode)`, `chown (Change Owner)`, and `chgrp (Change Group)`


## Introduction to File Permissions

- `Linux file permissions` determine who can read, write, or execute files and directories. 
- To access a file a user should also have the appropriate permissions for the `folder/directory` of that file.
- The `directory` permissions take **priority over** the `file` permissions. So, even if you have file access permissions but if you do not have directory permissions, you can not access that file. 

  ```bash
  # -rw-r--r-- 1 root root     222 Apr 26 19:54 resolv.conf

  # -, ---, ---, ---           Fist `char` denotes whether it is file/directory, then 3 sets of 3 chars each 
  #                            denote read,write,execute permissions for user, group and others resp.
  ```

- Each file and directory has `three` levels of permission:
  - **Owner (User)** :- The creator of the file.
  - **Group** :- Other Users belonging to the group that the User is part of.
  - **Others** :- All other users on the system.


- Permissions are represented as:
  - **Read (`r` or `4`)** – View file contents.
  - **Write (`w` or `2`)** – Modify file contents.
  - **Execute (`x` or `1`)** – Run scripts or programs.

- To check file permissions, use:
  ```bash
  ls -l filename
  ```

- Output example:
  ```bash
  -rwxr--r-- 1 user group 1234 Mar 28 10:00 myfile.sh
  ```

## Changing Permissions with `chmod`
### Using Symbolic Mode
- Modify permissions using symbols:
  - Add (`+`), remove (`-`), or set (`=`) permissions.

- Examples:
  ```bash
  chmod u+x filename            # Add execute for user
  chmod g-w filename            # Remove write for group
  chmod o=r filename            # Set read-only for others
  chmod u=rwx,g=rx,o= filename  # Set full access for user, read/execute for group, and no access for others
  ```

### Using Numeric (Octal) Mode
- Each permission has a value:
  - Read (`4`), Write (`2`), Execute (`1`).

- Examples:
  ```bash
  chmod 755 filename  # User (rwx), Group (r-x), Others (r-x)
  chmod 644 filename  # User (rw-), Group (r--), Others (r--)
  chmod 700 filename  # User (rwx), No access for others
  ```

## Changing Ownership with `chown`
- Modify file owner and group:

  ```bash
  chown newuser filename             # Change owner
  chown newuser:newgroup filename    # Change owner and group
  chown :newgroup filename           # Change only group
  ```

- Recursively change ownership:

  ```bash
  chown -R newuser:newgroup directory/
  ```

## Changing Group Ownership with `chgrp`

  ```bash
  chgrp newgroup filename       # Change group
  chgrp -R newgroup directory/  # Change group recursively
  ```

## Special Permissions
### SetUID (`s` on user execute bit)
- Allows users to run a file with the file owner's permissions.
- When the `SetUID` bit is set on an executable file, anyone who runs that file will execute it with the privileges of the file's owner, rather than with the privileges of the user who launched it.
- For example, if a file is owned by **root** and **has the SetUID bit set**, any user running that program will **temporarily gain root privileges** for the duration of that program's execution

  ```bash
  chmod u+s filename
  ```
- Example: `/usr/bin/passwd` allows users to change their passwords.

#### How is it displayed?
- In a long listing (`ls -l`), an executable file with `SetUID` will show an `s` in the `user (owner)` execute position, e.g.:
- If the file is not executable but `SetUID` is set, an uppercase `S` will appear instead of `x`.

  ```text
  -rwsr-xr-x 1 root root 12345 Apr 27 12:00 filename
  ```


### SetGID (`s` on group execute bit)
- When the `SetGID` bit is set on an executable file, any user executing that file will have the process run with the group privileges of the file’s group owner, rather than the user's current group.
- This is similar to the `SetUID` bit, but it applies to `group permissions` instead of `user permissions`.
- For example, if a **file is owned by group crontab** and has the **SetGID** bit set, running that file executes it with the **crontab group’s permissions**.
- This allows controlled privilege escalation for group-level access, useful for tasks requiring group-specific rights.

- **Files**: Users run the file with the group's permissions.
- **Directories**: Files created inside inherit the group.
  
  ```bash
  chmod g+s filename      # Set on file
  chmod g+s directory/    # Set on directory
  ```

## Sticky Bit (`t` on others execute bit)
### What Does the Sticky Bit Do?
- On Directories:
  - When the sticky bit is set on a directory, **only the file’s owner, the directory’s owner, or the root user can delete or rename files within that directory** - even if other users have write permissions on the directory.
  - Without the sticky bit, any user with write and execute permissions on a directory could delete or rename any file inside it, regardless of ownership.
  - This is crucial for shared directories like `/tmp`, where many users have write access but should not be able to delete or rename each other's files.

- On Files (historical/obsolete):
  - Originally, the sticky bit was used on executable files to tell the system to keep them in memory for faster reloading. 
  - This use is obsolete on modern Linux systems.

#### How Is the Sticky Bit Represented?
- In the output of ls -l, a directory with the sticky bit set will show a t in the "others" execute position:

  ```text
  drwxrwxrwt 9 root root 4096 Apr 27 16:00 /tmp
  ```
- Here, the t at the end indicates the sticky bit is set.

- Used on directories to allow only the owner to delete their files.

  ```bash
  chmod +t directory/        # Set the sticky bit
  chmod -t directory_name    # Remove the sticky bit
  ```

- Example: `/tmp` directory.

#### Summary Table
- 
  | Permission String | Meaning                               |
  | ----------------- | ------------------------------------- |
  | drwxrwxrwt        |	Sticky bit set on directory           |
  | drwxrwxrwx        |	No sticky bit; anyone can delete files|


## Default Permissions: `umask`

- `umask` defines default permissions for new files and directories.
- The `umask` (user file-creation mode mask) command in Linux defines the default permissions that are masked out (i.e., disabled) when new files and directories are created. 
- It controls the default access rights by subtracting its value from the system’s base permissions.

### How umask Works
- **Base permissions for new files**: 666 (read and write for user, group, others; no execute by default)
- **Base permissions for new directories**: 777 (read, write, execute for user, group, others)
- The umask value is subtracted from these defaults to determine the final permissions.

- Check current umask
  
  ```bash
  umask
  ```

- Set a new umask:
  
  ```bash
  umask 022         # Default: 755 for directories, 644 for files
  ```

## Conclusion
- Understanding file permissions is essential for system security and proper file management. 
- Using `chmod`, `chown`, and `chgrp`, you can control access to files and directories efficiently.

<br/>
<br/>

# Special File Attributes 
- Linux supports `special file attributes`, which provide **additional controls and metadata beyond standard file permissions**. 
- These attributes can restrict, enhance, or otherwise affect how files or directories are accessed and modified.

### Types of Special File Attributes
- Some commonly used special attributes include:

  | Attribute           |  Explanation                                                                                    |
  |-------------------- | ----------------------------------------------------------------------------------------------- |
  |**a (append only)**  | The file can only be opened in append mode for writing. Data can be added, but not removed or overwritten. This is useful for log files to prevent tampering. |
  |**i (immutable)**    | The file cannot be modified, deleted, renamed, or linked. Not even the root user can change the file unless the attribute is removed first.|
  |**c (compressed)**   | Data written to the file is automatically compressed by the kernel and uncompressed when read.|
  |**d (no dump)**      | The file is excluded from backups made with the dump utility.|

### Namespaces for Extended Attributes
- Linux also supports extended file attributes (`xattr`), which allow you to attach additional metadata to files. 
- These are organized into namespaces:

user: For user-defined attributes, accessible by regular users.
trusted, security, system: Used by the system or administrators for special purposes.

### Managing Special Attributes
- **List attributes**

  ```bash
  lsattr filename
  # --------------e------- hello.sh   
  # This command outputs a string of 22 characters, where each character represents a separate attribute.
  # A dash (-) means the attribute is not set.
  ```

- **Set or remove attributes**

  ```bash
  chattr +i filename   # Set immutable
  chattr -i filename   # Remove immutable
  chattr +a filename   # Set append only
  chattr -a filename   # Remove append only
  ```

- **Manage extended attributes**   
  - `chattr` linux command is used to change the file attributes.
  - `getfattr` and `setfattr` commands are used for getting and setting special attributes of a file. 
    
    ```bash
    getfattr -d filename                             # Display extended attributes
    setfattr -n user.comment -v "My note" filename   # Set an extended attribute
    ```

  - `getfattr` and `setfattr` commands are part of the `attr` package

    ```bash
    sudo apt-get update
    sudo apt-get install attr
    ```

### Use Cases and Considerations
- Setting `immutable` or `append` only can protect critical files (like system configs or logs) from accidental or malicious changes.
- Extended attributes are often used for storing additional metadata, security labels, or application-specific information.
- Not all file systems or backup tools support all attributes and extended attributes.