# Shell Scripting 
[Video](https://youtu.be/zsajhz2_50g?list=PLdpzxOOAlwvIBIRWcReRV-m2kgIW6V6gr)

- Shell Scripting is a dynamically typed scripting language.
- Shell scripting helps in automating repeated tasks on Linux.
- Shebang is the first line in shell script which tells computer which binary to use for executing the following shell commands.
  
- Different types of `Shebangs` 
 
  ```sh

  #!/bin/bash
  #!/bin/sh       # Usually '/bin/sh' gets directed to '/bin/bash' but sometimes might get directed to '/bin/dash'
                  # Prefer '/bin/bash' or '/bin/dash' over '/bin/sh'

  #!/bin/dash
  #!/bin/ksh
  #!/bin/aix
  #!/bin/zsh
  
  #!/usr/bin/env bash 
  ```

- These different shell binaries have different syntaxes for writing control statements.
- common linux shell commands 
  
  ```bash
  touch file      # Create a file with specified name.
  mkdir directory # create a new directory.
  cd directory    # Go to specified directory. 
  vim file        # Open specified file for reading/writing.
  cat             # Display content of the file on console.
  ls              # List the content of the present working directory 
  pwd             # Get the path of the current working directory.
  chmod           # Change mode. used for changing permissions.
  man             # Getting manuals of the programs  
  rm -rf folder   # Delete 'folder' recursively.
  nproc           # List number of CPUs on your machine.
  free            # Give free RAM memory stats.
  df              # Gives disk occupancy status.
  top             # Give process overview. 
  ps -ef          # process details in entire format.
  ```

- In shell scripting, **comments start with** `#`

- While writing shell script **always write description of the script** i.e. its metadata first. 

- Also, make use of `echo` statements for better understanding of the output.
  
  ```bash
  ###################
  # Author: Eknath
  # Date: 30 April 2025
  # This script outputs the node health
  # Version: v1
  ###################
  ``` 

- Options in Shell script
  ```bash
  # Set Debug mode of shell script on. It will print the command before printing its output.
  set -x            
  
  # When you are using 'pipe' in bash script please set the following two options at the beginning of the script.
  
  #1. Exits the script immediately when there is an error in bash script file.
  set -e            
  
  # However, 'set -e' will not stop the execution of the pipeline if an intermediate stage of the pipeline fails.
  # It will continue the execution of remaining pipeline stages. With only 'set -e' option set, the pipeline fails only when 
  # last stage of the pipeline fails.

  #2. This makes sure that execution stops when a pipeline stage fails.
  set -o pipefail     

  # All these parameters can also be combined into one sentence
  set -exo
  ```
## set -u (or its long form set -o nounset)
- It is a safety feature in shell scripts that makes the script exit immediately when it tries to use an unset variable.

### 🔍 Example with set -u:
```bash
#!/bin/bash
set -u
echo "Hello, $name"
```

- If name is not defined, the script will output:

  ```pgsql
  ./script.sh: line 4: name: unbound variable
  ```
And it will exit immediately.

### ❌ Without set -u:
```bash
#!/bin/bash
echo "Hello, $name"
```
- If name is unset, it would just print:

  ```Copy
  Hello,
  ```
- Silently failing — potentially dangerous in automation.

### 🛡️ Good practice:
- You can provide default values to avoid errors:

  ```bash
  echo "Hello, ${name:-Guest}"
  ```

- This prints Guest if $name is unset.

### 🧠 Summary
| Setting	            | Effect                                            |
| ------------------- | ------------------------------------------------- |
| `set -u`            | Script exits if an unset variable is used         |
| `set +u`            | Disables this strict behavior                     |
| Default workaround	| Use `${var:-default}` or test with `[[ -v var ]]` |

## Notes
- `pipe` command only redirects the output from `stdout` to the next command. 

- So, in case of command like `date` which outputs to `stdin` stream, `pipe` will not be able redirect its output to next command.
  
  ```bash
  date | echo "Today is"                 # Output will be just "Today is"
  ```

- Using `awk` to retrieve specific columns 
  ```
  ps -ef | awk -F" "  '{print $2}'       # awk prints second column.
  ```

- `If condition`
  
  ```bash
  a=10
  b=4
  
  if [ $a -gt $b ]
  then
    echo "a is greater than b"
  else
    echo "b is greater than a"
  fi  
  ```

- `if condition` in one line

  ```bash
  [ condition ] && command_if_true || command_if_false
  
  # OR
  [ -f /path/to/file.txt ] && echo "File exists." || echo "File does not exist."
  
  # OR
  if [ condition ]; then command_if_true; else command_if_false; fi
  ``` 
  - e.g. 
    
    ```bash
    if [ "$a" -eq "$b" ]; then echo "Equal"; else echo "Not equal"; fi
    ```

### Comparison Operators

- In `Bash`, following operators are used for numeric comparison 
  
  ```bash
  -lt (Less than), -gt (Greater than), -eq (Equal to), -le (Less or Equal), -ge (Greater/Equal), -ne (Not Equal)
  ```

- In `Bash`, following operators are used for string comparison 
  
  | Operator  | Usage Example	                        | Description                                            |
  | --------  | ------------------------------------- |--------------------------------------------------------|
  | `= or ==`	| [ `"$a"` =  `"$b"` ] or [[ `"$a"` == `"$b"` ]] | True if strings are equal (use == inside [[ ]])        |
  | `!=`      | [ `"$a"` != `"$b"` ]	                    | True if strings are not equal                          |
  | `<`       | [ `"$a"` \< `"$b"` ]	                    | True if string $a is lexicographically less than $b    |
  | `>`       | [ `"$a"` \> `"$b"` ]	                    | True if string $a is lexicographically greater than $b |
  | `-z`      | [ `-z` `"$a"` ]	                          | True if string is empty                                |
  | `-n`      | [ `-n` `"$a"` ]	                          | True if string is not empty                            |
  | `=~`      | [[ `"$a"` =~ `regex` ]]	                  | True if string matches the regular expression          |

#### Notes
- Always quote variables to avoid issues with spaces or empty values.
- When using `<` or `>`, escape them (`\<` or `\>`) inside `[ ]` to prevent shell redirection.
- Use `==` and `=~` only within `[[ ]]` for advanced comparisons like pattern matching and regex.
- For case-insensitive comparison, convert both strings to the same case using parameter expansion, e.g., `${a,,}`

#### Example 

  ```bash
  if [ "$a" = "$b" ]; then echo "Equal"; fi
  if [ "$a" != "$b" ]; then echo "Not equal"; fi
  if [ "$a" \< "$b" ]; then echo "a is less than b"; fi
  if [[ "$a" =~ ^[0-9]+$ ]]; then echo "a is a number"; fi
  ```

## `for` Loops
### 1. For Loop Over a List of Items  
- Iterates over a space-separated list of values (numbers or strings).

  ```bash
  for item in one two three; do
    echo $item
  done
  ```

### 2. For Loop Over a Range
- Uses brace expansion to iterate over a sequence of numbers or letters.

  ```bash
  for i in {1..5}; do
    echo $i
  done
  
  for letter in {a..e}; do
    echo $letter
  done

  # for i in {1..5}; do echo $i; done       # One line for loop

  ```

### 3. `C-Style` For Loop
- Similar to C language syntax, useful for numeric iteration with initialization, condition, and increment.

  ```bash
  for ((i=0; i<5; i++)); do
    echo $i
  done

  # for ((i=0; i<5; i++)); do echo $i; done   # One line for loop
  ```

### 4. For Loop Over Command Output
- Iterates over the output of a command, such as ls, find, or seq.

  ```bash
  for file in $(ls *.txt); do
    echo $file
  done
  
  for dir in $(find /path -type d); do
    echo $dir
  done
  
  for n in $(seq 1 10); do
    echo $n
  done
  ```

### 5. For Loop Over Array Elements
- Iterates through each element of an array.

  ```bash
  array=(apple banana cherry)
  for fruit in "${array[@]}"; do
    echo $fruit
  done
  ```

### 6. For Loop Over Array Indices
- Iterates through array indices using ${!array[@]}.

  ```bash
  array=(a b c)
  for idx in "${!array[@]}"; do
    echo "Index $idx: ${array[$idx]}"
  done
  ```
### 7. Infinite For Loop
- Runs endlessly until manually stopped (e.g., with break or CTRL+C).

  ```bash
  for (( ; ; )); do
    echo "Running..."
  done
  ```
### 8. Nested For Loops
- A for loop inside another for loop, useful for multi-dimensional data.

  ```bash
  for i in {1..3}; do
    for j in {a..c}; do
      echo "$i $j"
    done
  done
  ```
### 9. For Loop with `break` and `continue`
- `break` exits the loop early.
- `continue` skips to the next iteration.

  ```bash
  for i in {1..10}; do
    if [ $i -eq 5 ]; then
      break
    fi
    echo $i
  done
  
  for i in {1..10}; do
    if (( i % 2 == 0 )); then
      continue
    fi
    echo $i
  done
  ```
## Command substitution 
- Command substitution in Bash allows you to capture the output of a command and use it as part of another command — often inside echo, variable assignment, or other commands.

### 🔧 Syntax
- There are two ways to do command substitution:

```bash
$(command)     # Modern syntax (preferred)
`command`      # Old-style syntax
```

- Both do the same thing, but the modern `$(...)` is more readable and supports nesting.

### Example 1: Using with `echo`
```bash
echo "Today is $(date)"
date outputs the current date and time.
```
- `$(date)` gets replaced with that output.
- `echo` then prints the full message.

### Example 2: Assigning to a variable
```bash
now=$(date)
echo "Current time: $now"
```
- now contains the string output of date.

### Example 3: Nesting commands
```bash
echo "The number of files: $(ls | wc -l)"
"ls | wc -l" counts the number of files in the current directory.
```
- The result is embedded in the `echo`.

### Why use `$(...)` over backticks ?

```bash
echo "Result: $(command1 $(command2))"    # ✅ Easy
echo "Result: `command1 \`command2\``"    # 😵 Hard to read and escape
```

### Print the numbers divisible by 2 and 3
  
  ```bash
  for i in {1..100}; do  if [ $(expr $i % 2) -eq 0 ] && [ $(expr $i % 3) -eq 0 ]; then echo $i; fi ; done
  ```

### Print the numbers divisible by 2 and 3 but not by 15

  ```bash
  for i in {1..100}; do  if [ $(expr $i % 2) -eq 0 ] || [ $(expr $i % 3) -eq 0 ] && [ $(expr $i % 15) -ne 0 ]; then echo $i; fi ; done
  ```

### Iterate over the chars in a word
  
  ```bash
  word="hello"
  for (( i=0; i<${#word}; i++ )); do
    echo "${word:$i:1}"
  done

  # (OR)
  for(( i=0; i<${#word}; i++ ));  do   echo "${word:$i:1}"; done
  ```

### Count the number of 'i' in 'Mississippi'
- 
  ```bash
  word=Mississippi
  for(( i=0; i<${#word}; i++ )); do if [ "${word:$i:1}" == "i" ]; then ((count++)); fi; done ; echo $count
  ```
-  
  ```bash
  echo 'Mississippi' | grep -o "i" | wc -l
  ```
- 
  ```bash
  x=Mississippi
  grep -o "i" <<< $x | wc -l
  ```

## What is crontab in Linux?
- `crontab` (short for cron table) is a file that contains a list of commands to be run periodically on a schedule by the cron daemon.
- It is widely used for automating tasks like backups, updates, or running scripts.

### 🔧 Common crontab Commands
-
  |   Command    | Description                                                |
  | -----------  | ---------------------------------------------------------- |
  | `crontab -e` | Edit the current user's crontab file                       |
  | `crontab -l` | List current crontab entries                               |
  | `crontab -r` | Remove current crontab                                     |
  | `crontab -u` | username -e	Edit crontab for a different user (as root)   |

### 🧾 Crontab Syntax
  ```scss
  * * * * * command_to_run
  │ │ │ │ │
  │ │ │ │ └── Day of week (0 - 7) (Sunday is 0 or 7)
  │ │ │ └──── Month (1 - 12)
  │ │ └────── Day of month (1 - 31)
  │ └──────── Hour (0 - 23)
  └────────── Minute (0 - 59)
  ```

### ✅ Examples

  ```bash
  0 17 * * * /path/to/script.sh           # Run a script every day at 5 PM
  */15 * * * * /path/to/command           # Run every 15 minutes
  0 2 * * 0 /path/to/weekly_backup.sh     # Run at 2 AM on Sundays
  @reboot /path/to/startup_task.sh        # Run every time the system reboots (use @reboot)
  ```

### ⚠️ Tips
- Always use full paths in scripts or commands.
- Use `>> /path/to/logfile 2>&1` to capture output and errors.
- Make sure your script is executable ( `chmod +x script.sh` OR `chmod 755 script.sh` ).

## 🧱 Hard Link
- A hard link is an additional directory entry that points to the same inode (i.e., the actual file content) as the original file.
- Both the original file and the hard link are indistinguishable: they share the same data.
- Deleting the original file doesn't remove the data, as long as a hard link still exists.

### Example:
```bash
ln original.txt hardlink.txt
```

### Properties:
- Same inode number (`ls -i`)
- Same permissions
- Cannot link directories (except for special cases)
- Cannot span across different filesystems

## 🔗 Soft Link (Symbolic Link)
- A soft link is a special file that contains a path to another file or directory (like a shortcut).
- If the target file is deleted, the symlink becomes broken (dangling).
- Can link to directories and across filesystems.

### Example:
```bash
ln -s original.txt symlink.txt
```

### ✅ Properties:
- Different inode
- File type is "symbolic link"
- Can link directories
- Can span across filesystems

- Easily recognizable with `ls -l` (shows → target)
-
  ```bash
  echo "Hello" > file.txt
  ln file.txt hard.txt        # hard link
  ln -s file.txt soft.txt     # soft link
  ls -li                      # see inode numbers
  ```

### 📊 Quick Comparison Table
-
  | Feature	          | Hard Link	                 | Soft Link (Symlink)   |
  | ----------------- | -------------------------- |---------------------- |
  | Points to	        | File's inode (actual data) | File name (path)      |
  | Inode	            | Same as original	         | Different             |
  | Survives original | deletion	Yes	             | No (becomes broken)   |
  | Can link to dirs	| No (except by root)	       | Yes                   |
  | Cross filesystem	| No	                       | Yes                   |
  | Command	          | `ln file linkname`	       | `ln -s file linkname` |

## Disadvantages of Shell Scripting 
- Errors are frequent and costly, a single error can alter the command.
- The execution speed is slow.
- Large and complex tasks are not well suited to it.
- It provides minimal data Structures compared to other scripting languages.
- A new process is launched every time a new command is executed.

## 🔄 What is logrotate?
- logrotate is a Linux utility used to manage and rotate log files automatically. 
- It helps prevent log files from growing too large and consuming disk space by compressing, archiving, or deleting old logs based on rules you define.

### 🔧 Key Features:
- Automatically rotates, compresses, removes, and mails log files.
- Can be run daily, weekly, or monthly.
- Works with system logs, application logs, or custom logs.
- Supports post-rotate scripts to restart services after rotation.

### 📁 Configuration Files
#### 1. Global config file:

  ```bash
  /etc/logrotate.conf
  ```

#### 2. Per-app configs:

  ```bash
  /etc/logrotate.d/
  ```

### ✅ Basic Example (Custom Configuration)
- Create a file like `/etc/logrotate.d/myapp`:

  ```conf
  /var/log/myapp/*.log {
      daily
      rotate 7
      compress
      missingok
      notifempty
      copytruncate
      postrotate
      systemctl reload myapp
      endscript
  }
  ```

### 🔍 Explanation:
-  
  | Directive	    | Description                                                                |
  | --------------| -------------------------------------------------------------------------- |
  | daily         | Rotate logs daily                                                          |
  | rotate 7	    | Keep 7 old log files                                                       |
  | compress	    | Compress old logs with gzip                                                |
  | missingok	    | Skip if log file is missing                                                |
  | notifempty	  | Don’t rotate empty files                                                   |
  | copytruncate	| Truncate original file after copying (good for apps that keep files open)  |
  | postrotate	  | Run commands after rotation (e.g., restart a service)                      |

### 🔁 Run manually for testing:
```bash
logrotate -d /etc/logrotate.conf   # dry-run (show what would happen)
logrotate -f /etc/logrotate.conf   # force rotation
```