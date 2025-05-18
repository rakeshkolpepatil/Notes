# File management in Linux

## File and Directory Management

1. **`ls`** – Lists files and directories in the current location.
2. **`\`**  – Root of file system.
3. **`cd /path/to/directory`** – Changes the working directory.
4. **`cd .. `** – Changes the working directory to parent directory.

5. **`pwd`** – Prints the current working directory.
6. **`mkdir new_folder`** – Creates a new directory.
7. **`rmdir empty_folder`** – Removes an empty directory.
8. **`touch file.txt`** – Creates a file.
9. **`rm file.txt`** – Deletes a file.
10. **`rm -r folder`** – Deletes a folder and its contents.

11. **`cp file1.txt file2.txt`** – Copies `file1.txt` to `file2.txt`.
12. **`cp -r dir1 dir2`** – Copies a directory recursively.
13. **`mv old_name new_name`** – Moves or renames a file or directory.

## File Viewing and Editing

11. **`cat file.txt`** – Displays file content.

12. **`tac file.txt`** – Displays file content in reverse order.

13. **`less file.txt`** – Opens a file for viewing with scrolling support.
14. **`more file.txt`** – Similar to `less`, but only moves forward.
15. **`head -n 10 file.txt`** – Displays the first 10 lines of a file.
16. **`tail -n 10 file.txt`** – Displays the last 10 lines of a file.
17. **`nano file.txt`** – Opens a simple text editor.
18. **`vi file.txt`** – Opens a powerful text editor.
19. **`echo 'Hello' > file.txt`** – Writes text to a file, overwriting existing content.
20. **`echo 'Hello' >> file.txt`** – Appends text to a file without overwriting.

## ` find  command `
- Used to search for files and directories in a directory hierarchy based on various criteria such as `name`, `type`, `size`, `permissions`, `modification time`, and more.

### Basic Syntax
```text
find [path] [options] [expression]
```
- `[path]` : Directory where the search starts (e.g., `/`, `.`, `/home/user`)
- `[options]/[expression]` : Criteria for finding files (e.g., `-name`, `-type`, `-size`)

### Commonly Used Options and Examples

  | Option/Expression |  Description	                                     |  Example                                |
  | ----------------- |--------------------------------------------------- | --------------------------------------- |
  |    `-name`        |  Search by file name (case-sensitive)	             | `find /home -name "file.txt" `          |
  |    `-iname`       |  Search by file name (case-insensitive)	           | `find . -iname "*.jpg"`                 |
  |    `-type`        |  Search by type (f=file, d=directory, l=symlink)	 | `find /var -type d`                     |
  |    `-size`        |  Search by file size (+ for greater, - for less)	 | `find . -size +10M`                     |
  |    `-mtime`       |  Search by modification time (in days)	           | `find . -mtime -7`                      |
  |    `-atime`       |  Search by last access time (in days)	             | `find . -atime -1`                      |
  |    `-ctime`       |  Search by last status change (in days)	           | `find . -ctime -2`                      |
  |    `-user`        |  Search by file owner	                             | `find /tmp -user alice`                 |
  |    `-group`       |  Search by group	                                 | `find /data -group staff`               |
  |    `-perm`        |  Search by permissions	                           | `find . -perm 755`                      |
  |    `-empty`       |  Search for empty files/directories	               | `find . -empty`                         |
  |    `-exec`        |  Run a command on each found file	                 | `find . -name "*.log" -exec rm {} \;`   |
  |    `-delete`      |  Delete found files (use with caution)	           | `find . -name "*.tmp" -delete`          |
  |    `-maxdepth`    |  Limit search depth	                               | `find . -maxdepth 2 -name "*.conf"`     |
  |    `-mindepth`    |  Minimum search depth	                             | `find . -mindepth 2 -name "*.sh"`       |
  |    `-prune`       |  Exclude directories	                             | `find . -path "./dir" -prune -o -print` |

### Practical Examples
  
  ```bash
  # Find a file by exact name:
  # (Suppresses permission errors)
  find / -name "Foo.txt" 2>/dev/null
  
  # Find files by partial/case-insensitive name:
  find / -iname "*foo*txt" 2>/dev/null
  
  # Find all files larger than 1 MB:
  find /path/to/search -size +1M
  
  # Find files modified in the last 7 days:
  find . -type f -mtime -7
  
  # Find and delete all .tmp files:
  find . -name "*.tmp" -delete
  
  # Find files and execute a command (e.g., list files containing "example" text):
  find /home/user -type f -exec grep -l "example" {} +
  ```

### Combining Criteria
- You can combine multiple criteria using logical operators:
  
  ```
  # AND (default) :- 
  find . -type f -name "*.txt" -size +1M
  
  # OR :-
  find . -name "file1.txt" -o -name "file2.txt"
  
  # NOT :-
  find . ! -name "*.log"
  ```