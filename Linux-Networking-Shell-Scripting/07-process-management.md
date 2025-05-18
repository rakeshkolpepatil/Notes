# Process Management in Linux

## Introduction to Process Management
- A `process` is an `instance of a running program`. 

- Linux provides multiple utilities **to monitor, manage, and control processes** effectively. 
- Each process has a unique **Process ID (PID)** and belongs to a parent process.

## Index of Commands Covered

### Viewing Processes
- `ps aux` – View all running processes

- `ps -ef` - Also, used to view all running processes 
  - Name of the process is nothing but name of the binary used in the command that is specified in `CMD` column.
  
    ```bash
    UID    PID   PPID   C   STIME  TTY    TIME       CMD
    root     1      0   0   13:17  pts/0  00:00:00   /bin/bash
    root    16      0   0   13:48  pts/1  00:00:00   //bin//bash
    root   196     16   0   14:48  pts/1  00:00:00   ps -ef
    ```

#### `ps aux` Vs `ps -ef`
-
  | Feature	                 | ps aux	                      |   ps -ef                     |
  | ---------------------    | ------	                      | -----------------------------|
  | **Syntax Style**	       | BSD	                        | System V (SysV)              |
  | **Shows All Processes**  | Yes	                        | Yes                          |
  | **User Info Column**	   | USER (username)	            | UID (user ID number)         |
  | **Output Format**	       | User-oriented, more detailed |	Concise, full-format listing |
  | **Typical Columns**	     | USER, PID, %CPU, %MEM, VSZ, RSS, TTY, STAT, START, TIME, COMMAND |	UID, PID, PPID, C, STIME, TTY, TIME, CMD |
  | **Option Meanings**	     | a: all users <br> u: user format <br> x: without controlling terminal |	-e: all processes <br> -f: full format |
  | **Historical Origin**	   | BSD Unix	                    | System V Unix                       |
  | **Process Coverage**	   | All processes, including those without a terminal |	All processes |

- `ps -u username` – View processes for a specific user
  ```bash
  ps -u root      # Use UID's value from the output of 'ps -ef' command as 'username'
  ps -u Rakesh
  ```

- `ps -C processname` – Show a process by name

  ```bash
  ps -C bash,ps
  ps -C ps
  ps -C bash
  ```

  - Note:
    - The `-C` option matches the `executable name only`, not the full path or command line.
    - If you use the wrong name (e.g., **/bin/bash** **instead of bash**), **you will get no output**

- `pgrep processname` – Find a process by name and return its PID
  
  ```bash
  pgrep -l bash       # List the 'PID' and 'PName' for 'bash' process.
  pgrep -u root ps    # Find 'ps' processes owned by 'root' user.
  ```

- `pidof processname` – Find the PID of a running program
  
  ```bash
  pidof bash          
  pidof ps            #
  ```

## Difference Between BSD Unix and System V Unix
- BSD (Berkeley Software Distribution) Unix and System V Unix were the two major branches of the original Unix operating system, each with distinct technical features, philosophies, and historical development. Their rivalry and differences shaped the evolution of modern Unix-like systems, including Linux.

### Historical Background
- **System V Unix** was developed by AT&T and became the commercial standard for Unix, widely adopted by enterprise vendors like HP, IBM, and Sun Microsystems (which later merged System V with BSD to create Solaris).

- **BSD Unix** originated at the University of California, Berkeley, and was popular in academic, research, and networking environments. It was also known for introducing many influential features and tools.

### Key Technical Differences
| Aspect	            | System V Unix	                              | BSD Unix                     |
| ------------------- | ------------------------------------------  | ---------------------------- |
| Init System	        | Uses `/etc/init.d/` scripts (SysV init)	      | Uses `/etc/rc.conf`, `/etc/rc.*` scripts|
| Networking	        | Initially used STREAMS for networking	      | Introduced TCP/IP stack and sockets API |
| Terminal Handling	  | `termio` interface	                          | BSD `tty` interface            |
| File System	        | System V File System (S5FS), later UFS	    | Fast File System (FFS/UFS)   |
| Process Control	    | System V style IPC (message queues, semaphores, shared memory)	| Also supports System V IPC, but originally used different mechanisms |
| Commands/Utilities	| Some commands differ in options and behavior	| BSD introduced tools like `csh`, `vi`, more |
| Shutdown/Startup	  | `init`, `telinit`, `shutdown` commands, but less automated fsck	| Automated `fsck`, `shutdown`, `halt`, `reboot` commands |
| Licensing	          | Proprietary (AT&T)	                        | Initially proprietary, later open source |

### Modern Relevance
- Today, the distinction between `BSD` and `System V` is less pronounced due to standardization `(POSIX)` and the blending of features. 
- Linux, for example, is a `System V-style Unix` but **incorporates many BSD innovations**

### Managing Processes
- `kill PID` 
  - Terminate a process by PID
  - Kills a single process precisely.
  
    ```bash
    # Syntax
    pkill [options] process_name    
    
    # Sends a signal (default is SIGTERM), requesting the process to terminate gracefully.  
    kill 234                   
    
    # If the process ignores graceful termination, stronger signals like SIGKILL (-9) can be used for force termination
    kill -9 234  
     
    # Sends signal number 3 (which corresponds to SIGQUIT) to the process with PID 123 
    # SIGQUIT (signal 3): This signal tells the process to quit and typically causes the process to terminate and produce a core dump, which can be used for debugging.

    kill -3 123              
    ```
  - `kill -3 21` will instruct the process with PID 21 to terminate and, if configured, generate a core dump for debugging purposes.

- `pkill processname` 
  - Terminate a process/processes by `name`
  - It sends the signal to all processes matching the given name, making it easier to `kill multiple processes` without looking up their `PIDs` first. 

- `kill -9 PID` – Force kill a process
- `pkill -9 processname` – Kill all instances of a process

- `kill -STOP PID` 
  - Stop a running process
  - The command `kill -STOP pid` sends the `SIGSTOP` signal to the process with the specified `PID`. 
  - This signal pauses (stops) the process’s execution without terminating it.
  - `SIGSTOP (signal 19)` stops (pauses) the process immediately.
  - The process `cannot ignore` or catch this signal; it is **always honored by the kernel**.
  - The process remains in a stopped state and does not consume CPU resources.

- `kill -CONT PID` 
  - Resume a stopped/paused process by sending it the `SIGCONT (signal 18)` signal.
  

- `renice -n 10 -p PID` 
  - Used to change the **scheduling priority (nice value)** of a running process with the specified **PID**.
  - Lower priority of a process
  - `-n 10` : Sets the new nice value to 10. 
  - In Linux, nice values range from `-20 (highest priority)` to `19 (lowest priority)`. 
  - A higher nice value means lower priority, so the process will get less CPU time compared to others with a lower nice value.
  - This is useful if a process is consuming too many resources and you want to ensure other processes get more CPU time.
  
- `renice -n -5 -p PID` 
  - Increase priority of a process **(requires root permission)**

### Background & Foreground Processes
- `command &` 
  - Run a command in the background
  - Appends an ampersand `(&)` to a command to execute it as a background job, allowing you to continue using the terminal for other tasks.
  
- `jobs` 
  - List background jobs
  - Displays all current background and stopped jobs in the current shell session
  
- `fg %jobnumber` 
  - Bring a job to the foreground
  - Brings the specified background job (by job number, e.g., `%1`) to the foreground so you can interact with it.
  - You can also use `fg` **without a job number to bring the most recent job to the foreground**.

- `Ctrl + Z` 
  - Suspend a running process
  - **Suspends the current foreground process and puts it into a stopped state (not running) in the background**.
  - The job can be resumed later with `bg` or `fg`.

- `bg %jobnumber` 
  - **Resume a suspended process in the background**
  - Resumes a stopped job (by job number, e.g., %1) and continues its execution in the background.
  - If you omit the job number, bg resumes the most recently stopped job.

#### Notes 

- To suppress output from a background job, redirect output : `command > /dev/null 2>&1 &.`

- Use `kill %jobnumber` or `kill PID` to terminate background jobs.
- Job numbers are listed by jobs and referenced with a `%` (e.g., `%1`).

## Monitoring System Processes
- `top` 
  - Interactive process viewer
  - Shows a **real-time**, **dynamic view of running processes and system resource usage** (**CPU**, **memory**, etc.). 
  - You can interact with the display (e.g., press **k to kill a process**, **r to renice**, **c to toggle full command line**, **q to quit**)

- `htop` 
  - User-friendly process viewer (requires installation)
  - An enhanced, user-friendly alternative to top with color output, easier navigation, and more interactive features. 
  - Not installed by default on all systems
  
- `nice -n 10 command` 
  - Run a command with a specific priority
  - Starts a command with a "nice" value of 10, which means lower CPU scheduling priority (range: -20 = highest priority, 19 = lowest).

- `renice -n -5 -p PID` 
  - Change priority of an existing process
  - Changes the nice value of the process with the specified PID to -5, increasing its scheduling priority (**requires root privileges for negative values**)

## Daemon Process Management

- Listing Services 

  ```bash
  # Shows all service units currently loaded in the system manager (active, inactive, running, exited, failed)
  systemctl list-units --type=service    

  # Lists service unit files that are enabled to start on boot.
  systemctl list-unit-files --type=service --state=enabled

  # List all currently running services
  systemctl list-units --type=service --state=running

  # List active services (running or exited)
  systemctl list-units --type=service --state=active

  # List running and failed services
  systemctl list-units --type=service --state=running,failed

  # Starts the specified service for the current session without enabling it at boot.
  systemctl start service-name.service

  # Stops the specified service gracefully by sending SIGTERM to the main process; if it does not stop, SIGKILL is sent
  systemctl stop service-name.service

  # Creates symbolic links to ensure the service starts on system boot based on the [Install] section of the service unit.
  systemctl enable service-name.service

  # Disable a service from starting at boot
  systemctl disable service-name.service

  # Restart a service
  systemctl restart service-name.service

  # Reload service configuration without stopping
  systemctl reload service-name.service

  # Check the status of a service
  systemctl status service-name.service
 
  # Check if a service is enabled at boot  
  systemctl is-enabled service-name.service

  # Check if a service is currently active (running)
  systemctl is-active service-name.service

  ```
### Notes on Service Files and Signals
- A service unit file typically resides in `/etc/systemd/system/` or `/usr/lib/systemd/system/`.

- The `[Service]` section defines how the service `starts (ExecStart)`, `stops (ExecStop)`, and which signal to use for `termination (KillSignal)`.

- If `ExecStop` is not defined, `systemd` sends `SIGTERM` by default and escalates to `SIGKILL` if the service does not stop timely.

- For services that fork or spawn child processes, `systemd` manages the entire control group (cgroup) to stop all related processes.


## List all system daemons

- `systemctl start service-name` – Start a daemon/service

- `systemctl stop service-name` – Stop a daemon/service
- `systemctl enable service-name` – Enable a service at startup

## Viewing Process Details

### Using `ps`

- Show processes for a specific user:
  ```bash
  ps -u username
  ```

- Show a process by name:
  ```bash
  ps -C processname
  ```

### Using `pgrep`
- Find a process by name and return its PID:
  
  ```bash
  pgrep processname
  ```

### Using `pidof`
- Find the PID of a running program:
  
  ```bash
  pidof processname
  ```

## Managing Processes
### Killing Processes

- To terminate a process by PID:
  ```bash
  kill PID
  ```

- To terminate using process name:
  ```bash
  pkill processname
  ```

- Force kill a process:
  ```bash
  kill -9 PID
  ```

- Kill all instances of a process:
  ```bash
  pkill -9 processname
  ```

### Stopping & Resuming Processes
- Stop a running process:
  ```bash
  kill -STOP PID
  ```

- Resume a stopped process:
  ```bash
  kill -CONT PID
  ```

### Changing Process Priority
- View process priorities:
  ```bash
  top                       # Look at the NI column
  ```

- Change priority of a running process:
  ```bash
  renice -n 10 -p PID       # Lower priority (positive values)
  renice -n -5 -p PID       # Higher priority (negative values, root required)
  ```

### Running Processes in the Background
- Run a command in the background:
  
  ```bash
  command &
  ```

- List background jobs:
  
  ```bash
  jobs
  ```

- Bring a job to the foreground:
  
  ```bash
  fg %jobnumber
  ```

- Send a running process to the background:
  
  ```bash
  Ctrl + Z         # Suspend process
  bg %jobnumber    # Resume in background
  ```

## Monitoring System Processes
### Using `top`
- Interactive process viewer:
  - Press `k` and enter a PID to kill a process.
  - Press `r` to renice a process.
  - Press `q` to quit.

### Using `htop`
- A user-friendly alternative to `top`:
  ```bash
  htop
  ```
- Allows mouse-based interaction for process management.

### Using `nice` & `renice`
- Run a command with a specific priority:
  ```bash
  nice -n 10 command
  ```

- Change the priority of an existing process:
  ```bash
  renice -n -5 -p PID
  ```

## Daemon Processes
- Daemon processes run in the background without user intervention.
  
  ```bash
  # List all system daemons:
  systemctl list-units --type=service
  
  # Start a daemon:
  systemctl start service-name
  
  # Stop a daemon:
  systemctl stop service-name
  
  # Enable a service at startup:
  systemctl enable service-name
  ```

## `trap` command 
- **Allows scripts to catch and handle signals or shell events such as script exit, errors, or user interrupts** (like pressing `Ctrl+C`). 
- This is especially useful for cleanup tasks, graceful shutdowns, and custom error handling.

### Basic Syntax
  ```bash
  trap 'commands' SIGNALS      # Whenever 'SIGNALS' signal is received run commands from 'commands'
  trap - SIGINT                # To stop trapping the signal.
  ```
- `'commands'` : The command(s) to execute when the specified signal(s) are received. If multiple commands, enclose in single or double quotes.
- `'SIGNALS'` : One or more signals to trap (e.g., **SIGINT**, **EXIT**, **ERR**).

### Common Use Cases
#### 1. Cleanup on Script Exit
- Automatically remove temporary files or perform cleanup when the script exits (normally or abnormally):

  ```bash
  tempfile=/tmp/tmpdata
  trap "rm -f $tempfile" EXIT
  ```
- Now, whenever the script exits, it deletes the temporary file.

#### 2. Handling User Interrupt `(Ctrl+C)`
- Prevent abrupt termination or perform custom actions when the user presses `Ctrl+C` (sends `SIGINT`):

  ```bash
  trap 'echo "SIGINT received. Exiting gracefully." ; exit 1' SIGINT
  ```
- This prints a message and exits when SIGINT is caught.

#### 3. Handling Errors
- Run a command when any command in the script fails (exits with non-zero status):

  ```bash
  trap 'echo "Error occurred on line $LINENO"' ERR
  ```
- This prints the line number where the error occurred.

#### 4. Handling Multiple Signals
- You can trap multiple signals at once:

  ```bash
  trap 'cleanup' SIGINT SIGTERM
  ```
- This will run the cleanup function when either `SIGINT` or `SIGTERM` is received.

#### 5. Ignoring Signals
- To ignore a signal (e.g., ignore `Ctrl+C`):

  ```bash
  trap '' SIGINT
  ```
- This disables the default action for `SIGINT` (`Ctrl+C`).

#### 6. Resetting Traps
- To reset a trap to its default behavior:

  ```bash
  trap SIGINT
  ```
- This restores the default action for SIGINT.

### Advanced Examples
- Custom cleanup function:

  ```bash
  cleanup() {
    rm -f "$tempfile"
    echo "Cleaned up."
  }
  trap cleanup EXIT
  ```

- Logging on exit:

  ```bash
  trap 'echo "$(date): Script exited" >> /var/log/myscript.log' EXIT
  ```

- Conditional trap actions:

  ```bash
  trap '[ "$$" != "$BASHPID" ] && echo "Background" || echo "Foreground"' SIGINT
  ```

### Summary Table
-
  | Signal/Event	|  Common Use	         |  Example Command                  |
  | --------------| ---------------------| --------------------------------- |
  | `EXIT`	      |  On script exit	     |  `trap 'cleanup' EXIT`            |
  | `SIGINT`	    |  `Ctrl+C` interrupt	 |  `trap 'echo Interrupted' SIGINT` |
  | `ERR`	        |  On error	           |  `trap 'echo Error' ERR`          |
  | `SIGTERM`	    |  Termination signal	 |  `trap 'cleanup' SIGTERM`         |

## Conclusion
Process management is crucial for system performance and stability. By using tools like `ps`, `top`, `htop`, `kill`, and `nice`, you can efficiently control and monitor Linux processes.
