# DevOps Zero to Hero Course 

## Day 1 | Fundamentals of DevOps 
### day-to-day activities of DevOps engineer 

### What is DevOps ?
- Devops is a culture/process of improving application delivery using 
  1. Automation 
  2. Quality 
  1. Continuous Monitoring 
  2. Continuous Testing 
  
- DevOps can employ different tools to achieve these tasks.
- The goal of DevOps engineer is to speed up the delivery process and reduce manual efforts.

### Why DevOps ?
- Prior to DevOps, the application delivery from developer to client included following steps 
  1. Developer will create an application and push it to the VCS (Version Control System)
  2. `Sys Admin` will create the server using Hypervisors like VMWare or Open Stack or Xen on bare metal.
  3. `Build and Release Engineer` will deploy the application code to server 
  4. `Server Admin` will finally create application server.

- Thus lot of manual efforts were involved in delivering application to the client. To fasten this entire process DevOps process was developed.

### DevOps Engineer Tasks ?
- DevOps culture started around 2014 and has became popular since last 5-6 years.
- Build and Release Engineers or Server Admins were the first to adopt this DevOps culture.
- DevOps engineers focus on automation, quality control and monitoring, testing of an application, setting up of CICD pipeline for speedy delivery of the applications. 

## Day 2 | Software Development Life Cycle (SDLC) 
- SDLC is the standard followed by software industry to design, develop and test with a end goal of delivering high quality product.
- Software development consists of following stages -
  1. Planning  - requirement gathering 
  2. Defining  - Define the requirements, create software requirement specification document
  3. Designing - Develop High Level Design (HLD), Low Level Design (LLD)
  4. Building  - Develop/write the code in suitable language, get peer reviewed and push to Git (Developers)
  5. Testing   - Pull the Git code to the server, Quality Assurance engineers will test the code (Quality Engineers)
  6. Deploying - Push the application to the server for usage by clients.
-  DevOps engineer fastens the delivery process and is closely working with Building, Testing and Deployment phases of the software by automating most of the tasks.
- Now a days, Agile methodology is used for software development.

## Day 3 | Virtual Machines 
- Hypervisor is a software which enables creation of virtual/logical servers on the bare metal or physical servers.
- VMware, Xen are few examples of popular hypervisors.
- All these virtual machines are completely isolated and are totally independent.
- EC2 is an example of a virtual machine instance.
- Virtual machines can even be created on the laptop using Oracle Virtualbox.

## Day 4 | AWS & Azure - Creating Virtual machines
- Virtual machines can be programmatically created on Amazon EC2 using `Amazon EC2 API` using scripts.
- Once the AWS EC2 API receives a valid (syntactically correct), authenticated (User should be valid) and authorized (User should have permissions for that service) request, API will return a EC2 instance.

- AWS API can be accessed through one of the following ways -
  1. AWS CLI (Command Line Interface)
  2. AWS API using programming languages (Boto3 in Python)
  3. AWS CFT (Cloud Formation Templates) using Template languages
  4. Terraform (it can be used for creating resources on any cloud platform such as Google/Amazon/Microsoft cloud)
  5. AWS CDK (Cloud Development Kit)
  
- Any new features will get supported first on the AWS CDK than the Terraform as it is their proprietary tool.
- Terraform is usually preferred by organizations using hybrid cloud pattern. Hybrid cloud patterns use multiple cloud providers. 
- **For example -** Google cloud is used for AI/ML/Kubernetes related tasks, RDS (Relational Database Service) on AWS.
- Azure Resource Manager is a Private Network Access (PNA) for Microsoft cloud, similar to AWS CFT for AWS.

## Day 5 | HOW TO CONNECT TO EC2 INSTANCE FROM WINDOWS LAPTOP

## Day 6 | AWS CLI Full Guide | How to connect to EC2 Instance from UI & Terminal | AWS CFT walk though
- `AWS Cli` is a command line tool for all the AWS services. 
- Download and install AWS Cli on windows and then you can execute AWS commands through your terminal.
  
  ```bash
  # Check AWS is installed on your machine 
  aws version 
  
  # Add Access Key and Secret to configure AWS Cli so that the commands you run locally will get executed on the AWS server.
  # Get credentials from 'security credentials' tab from your profile.

  aws configure
  ```

## Day-7 | Live AWS Project using SHELL SCRIPTING for DevOps | AWS DevOps project|
- Tracking `AWS resource` usage using shell script.

  ```bash
  #!/bin/bash
  ##########################
  # Author: Rakesh
  # Date: 4 May 2025
  # Version: v1 
  # Usage: This script is used for tracking AWS Usage of S3, EC2, IAM and Lambda Functions
  ##########################
  
  set -x 
  
  # List s3 buckets
  aws s3 ls
  
  # List EC2 instances
  aws ec2 describe-instances | jq '.Reservations[].Instances[].InstanceId'
  
  # list Lambda
  aws lambda list-functions
  
  # list IAM users
  aws iam list-users
  ```

## Day-8 | DevOps Zero to Hero | Shell Scripting Project Used In Real Time | GitHub API Integration
- Users interact with applications through UI, APIs or CLIs.

- These APIs can be integrated with numerous programming languages such as Python, Shell, Java, Rust etc using different modules cush as `curl` for `Shell Scriping` and `requests` for `Python`.
- These APIs are called using HTTP or GRPC protocols.
- API related information is provided by these applications in API reference documents.
- Below is a sample Shell script for API integration with github.
  
  ```bash
  #!/bin/bash
  
  # GitHub API URL
  API_URL="https://api.github.com"
  
  # GitHub username and personal access token
  USERNAME=$username
  TOKEN=$token
  
  # User and Repository information
  REPO_OWNER=$1
  REPO_NAME=$2
  
  # Function to make a GET request to the GitHub API
  function github_api_get {
      local endpoint="$1"
      local url="${API_URL}/${endpoint}"
  
      # Send a GET request to the GitHub API with authentication
      curl -s -u "${USERNAME}:${TOKEN}" "$url"
  }
  
  # Function to list users with read access to the repository
  function list_users_with_read_access {
      local endpoint="repos/${REPO_OWNER}/${REPO_NAME}/collaborators"
  
      # Fetch the list of collaborators on the repository
      collaborators="$(github_api_get "$endpoint" | jq -r '.[] | select(.permissions.pull == true) | .login')"
  
      # Display the list of collaborators with read access
      if [[ -z "$collaborators" ]]; then
          echo "No users with read access found for ${REPO_OWNER}/${REPO_NAME}."
      else
          echo "Users with read access to ${REPO_OWNER}/${REPO_NAME}:"
          echo "$collaborators"
      fi
  }
  
  # Main script
  
  echo "Listing users with read access to ${REPO_OWNER}/${REPO_NAME}..."
  list_users_with_read_access
  ```

## Day-9 | Git and GitHub | What is GIT ? | What is Version Control ?

### 📘 Software Version Control Systems (VCS)
- Software Version Control Systems are essential for collaboration, tracking changes, and managing multiple versions of software projects.
- They help teams work together efficiently, avoid code conflicts, and maintain a full history of code evolution.

### 🔄 Types of Version Control Systems
There are two main types:

#### 1. Centralized Version Control System (CVCS)
- In CVCS, the latest version of the project is stored on a central server.
- Developers pull (get) the latest version and push (submit) their changes to this central server.
- If the central server goes down, collaboration stops completely until it’s restored.
- There is limited support for offline work.

##### Examples:
1. CVS (Concurrent Versions System)
2. SVN (Apache Subversion)
3. Perforce

#### 2. Distributed Version Control System (DVCS)
- Every developer has a full copy of the repository, including its entire history.
- Developers can commit changes, create branches, and view logs offline.
- There is no single point of failure — any local copy can be used to restore the project.
- Developers can share changes peer-to-peer or through a central server.

##### Examples:
1. Git
2. Mercurial
3. Bazaar

###❗ Fork vs Clone
1. `Clone` : Copy a repository locally from any remote (common in all Git use).
2. `Fork`  : Copy a repository to your own account on platforms like GitHub to propose changes or personalize the project (usually followed by cloning).

### 🧠 Git and Hosting Platforms
- Git is a `free` and `open-source` `distributed version control system`, originally created by Linus Torvalds.

- It allows powerful features like branching, merging, rebasing, and staging.
- Git itself is command-line-based and does not provide collaboration features like issues, PRs, or web UIs.
- Hosting platforms like `GitHub`, `GitLab`, `Bitbucket` extend Git by offering:

  1. Web interface
  2. Pull Requests / Merge Requests
  3. Issue tracking
  4. Project boards
  5. CI/CD pipelines
  6. Access control and collaboration tools
  
### 📁 `.git` Directory in Git
- When you run `git init`, Git creates a hidden folder named `.git` in the root of your repository.

- This folder contains all the metadata and history Git needs to track changes.
- If you delete `.git`, the repository becomes untracked — Git will no longer recognize it as a repo.

### 📂 Structure of `.git` Directory
Here's a breakdown of key files and folders inside `.git`:

#### 1. `HEAD`
- A file that points to the current branch reference (usually something like **refs/heads/main**).
- It tells Git what your current working branch is.
- Example contents:

  ```bash
  ref: refs/heads/main
  ```

#### 2. `config`
- Contains repository-specific configurations, such as:
  - User identity
  - Remote URLs
  - Push/pull behavior

- Example settings:

  ```ini-
  [user]
      name = Your Name
      email = your.email@example.com
  ```

#### 3. `hooks/`
- Contains client-side scripts triggered by Git actions such as commits, merges, etc.

- You can use hooks to:
  - Enforce commit message formats
  - Prevent commits with sensitive data (e.g., passwords or tokens)
  - Run linters or tests before allowing commits
- By default, Git provides sample hook scripts with `.sample` extensions.

#### 4. `objects/`
- Stores all Git content: files, commits, trees, blobs, etc., as objects identified by SHA-1 hashes.

- This is the core of Git’s storage mechanism.
- The structure is optimized for deduplication and integrity checking.

#### 5. `refs/`
- Stores references to commit objects, such as:
  - Branches (`refs/heads/`)
  - Tags (`refs/tags/`)
  - Remote branches (`refs/remotes/`)

- These files point to the latest commit SHA on each ref.

### 🛠️ Common Git Commands

```bash
git init                    # Initialize a new Git repository.
git clone <url>             # Clone a remote repository to local machine.
git status                  # Show the status of files in the working directory.

git status --ignored        # See ignored files

# Before adding a file for staging area always check the changes done to that file using 'git diff' command.
git add <file>              # Stage a specific file for commit. OR start tracking changes in 'file'
git add .                   # Stage all changes.

git commit -m "message"     # Commit staged changes with a message.
git log                     # View the commit history.
git log <branch-name>       # View Log of a Specific Branch

git diff                    # Show changes between working directory and staged area.
git branch                  # List all branches.
git branch <name>           # Create a new branch.

git checkout <name>         # Switch to a specific branch.
git checkout -b <name>      # Create and switch to a new branch.

# If you've modified a file but haven't committed it, and want to discard the changes and restore it to the last committed version
git checkout -- <filename>
(OR) git restore <filename> # This command is preferred in newer versions of Git.
                            # This does NOT remove the file from Git.
                            # It discards any uncommitted changes to the file.
                            # Cannot be undone easily, so use it carefully.

git merge <branch>          # Merge another branch into the current branch.
git pull                    # Fetch and merge changes from the remote repository.
git push                    # Push local commits to the remote repository.

git reset --hard commitId   # To go to the specific commit 

# Standard Git workflow 
git add && git commit -m "Commit Message" && git push

# Display the URLs associated with the remote repositories for your Git project.
git remote -v
(or) git remote --verbose
                # "origin" is the default name given to the remote repository when you clone a repo.
                # "fetch" URL is used to pull (fetch) data from the remote.
                # "push" URL is used to push your changes to the remote.
                # Used to check where your code is being pushed to or pulled from.
                # Useful before changing the remote URL or pushing to a different remote.

# To add a new remote repository to your local Git repository
git remote add <name> <url>
git remote add origin https://github.com/username/repo.git
                # 'origin': a short name for the remote (commonly used as the default).
                # https://github.com/username/repo.git: the URL of the remote repository.

# To change the remote URL later
git remote set-url origin <new-url>
```

## Day-10 | Git Branching Strategy | Real World Example | DevOps Interview Question
- Branches that are created to implement new features are called as `Feature Branch` and are merged with `main/master` branch once feature gets implemented.
- `Release Branches` contain the final code that is built and delivered/shipped to the customer.
- `Master Branch` is being developed actively is always kept up to date.
- `Hot fix Branches` are created to fix the bugs, are usually short lived and are merged with Master and release branches to keep them updated by integrating solution to the bugs.

### 🔀 What is a Branch?
- **A branch** in Git is a **lightweight movable pointer** to a commit.
- It allows developers to **work in isolation** on new features, bug fixes, or experiments without affecting the main codebase.
- Once the work is complete and tested, it can be **merged** back into the main codebase.

### 🚗 Real-World Example
> Imagine a company like **Uber** is adding a **Bike Hiring** service to its existing **Car Hiring** application:

- A new branch is created to **implement this feature**.
- Developers build and test the feature **independently** on this branch.
- Once the implementation is stable, the branch is **merged back into** `main` **or** `develop`.

### 🛠️ Types of Git Branches (Git Flow Strategy)

#### 1. `main / master` Branch
- The main production-ready branch.

- Always contains **stable**, tested code that can be deployed.
- Releases are tagged from this branch.

> 💡 In modern workflows, `main` is preferred over `master`.

#### 2. `develop` Branch (optional but common in Git Flow)
- Integrates completed features before they are released.

- Acts as a staging area for testing and validation.
- Regularly merged into `main` during a release.

#### 3. `feature/<feature-name>` Branch
- Created from `develop` (or sometimes `main`) for developing a single feature.

- Isolated workspace for developers.
- Deleted after being merged into `develop` (and tested).
- Naming convention: `feature/bike-hiring`, `feature/login-auth`.

#### 4. `release/<version>` Branch
- Created from `develop` when preparing a release.

- Used for final bug fixes, documentation, and testing before deploying.
- Merged into both `main` and `develop` after release.
- Example: `release/v1.2.0`.

#### 5. `hotfix/<issue>` Branch
- Created from `main` to fix critical issues in production.

- Fast patch branch that is merged back into both `main` and `develop` to keep them in sync.
- Example: `hotfix/crash-on-login`.

### 💬 **"How do you manage Git branches in a CI/CD pipeline?"**
- “We follow Git Flow: use `feature` branches for development, `develop` for integration testing, `release` for staging, and `main` for production. 
- Hotfixes are patched directly from `main` and merged back. 
- This ensures separation of concerns and continuous integration.”


## Day-11 | Git Interview Q&A and Commands for DevOps | Real World Example

### 🔁 `Git clone` Vs `Git Fork`
### 🔁 git clone
- **Clones i.e. Downloads an existing repository** (local or remote) to your machine.
- It's a **Git command**.
- You **do not need GitHub access rights** to clone a public repository.
- It includes:
  - All branches
  - Complete history
  - Working directory

### ✅ Example:
```bash
git clone https://github.com/octocat/Hello-World.git
```

### 🍴 Fork
- Creates a copy of someone else's repository in your own GitHub account.
- It's **not a Git command** – it's a **GitHub/GitLab/Bitbucket feature**.
- Useful when:
  - You don’t have write access to the original repo
  - You want to propose changes via pull requests
- After forking, you typically clone your fork using `git clone`.

### ✅ Fork Workflow:
1. Fork the repo on GitHub
2. Clone the fork:

    ```bash
    git clone https://github.com/your-username/Hello-World.git
    ```

### 🔍 Summary Table
-
  | Feature	            | `git clone`                     | `fork`                                |
  | ------------------- | ------------------------------- | --------------------------------------|
  | Command or Feature?	| Git command	                    | GitHub feature                        |
  | Purpose	            | Copy repo to local system	      | Copy repo to your GitHub account      |
  | Access Rights	      | No GitHub write access needed	  | Used when you don’t have write access |
  | Allows PRs?	        | (Pull Request) Not directly     | Yes, used to make PRs to original repo|
  | Typical Usage	      | Internal team collaboration	    | Open-source contribution              |


## 🔀 `git merge` vs `git rebase` vs `git cherry-pick`

  | Feature / Purpose	     | `git merge`                             | `git rebase`                           |`git cherry-pick`|
  | ---------------------  | -------------------------------------   | -------------------------------------- | --------------- |
  | Main Use	             | Combine two branches together           | Move a branch to start from a new base	| Copy specific commit(s) to another branch |
  | Preserves history	     | ✅ Yes                                 | ❌ No – rewrites history	             | ✅ Yes (but can create duplicate commits) |
  | Creates merge commit	 | ✅ Yes (unless `--no-commit` or `--squash`) | ❌  No (linear history)           | ❌ No |
  | Ideal for	             | Collaborative feature integration	     | Cleaner linear history (rebasing your own branches) | Backporting or applying specific changes |
  | Risk	                 | Low                                     | Medium (rewriting history = risk for shared branches) |	Low |

### 🔁 `git merge`
- Merges one branch into another.

  ```bash
  # Merge 'feature' into 'main'
  git checkout main
  git merge feature
  ```
- Keeps full history (with a merge commit).
- Useful in team workflows.

### 🔄 `git rebase`
- Re-applies commits from one branch on top of another base branch.

  ```bash
  # Rebase 'feature' onto 'main'
  git checkout feature
  git rebase main
  ```
- Produces a **linear history** (no merge commits).
- Often used to tidy up commit history **before merging** via PR.

#### ⚠️ Don’t rebase public/shared branches.

### 🎯 `git cherry-pick`
- Apply one (or more) `specific commits` from another branch.

  ```bash
  # Pick a commit from 'feature' into 'main'
  git checkout main
  git cherry-pick <commit-hash>
  ```
- Great for `backporting` fixes.
- Only moves selected commits (not entire branches).

### 🚀 Example Use Case Comparison
Suppose you have:

  ```mathematica
  main:     A---B---C
  feature:           D---E
  ```
- `git merge feature` (on `main`) gives:

  ```css
  A---B---C-------F
           \     /
            D---E
  ```

- `git rebase main` (on `feature`) makes:

  ```mathematica
  A---B---C---D'---E'
  ```

- `git cherry-pick D` (on `main`) makes:

  ```mathematica
  A---B---C---D'
  ```

## 🔄 `git fetch` vs `git pull`

| Feature                        | `git fetch`                                          | `git pull`                                   |
| ------------------------------ | ---------------------------------------------------- | -------------------------------------------- |
| **What it does**               | Downloads changes from remote, **but doesn't merge** | Downloads **and merges** changes from remote |
| **Affects working directory?** | ❌ No                                                 | ✅ Yes – updates files                        |
| **Safe for inspection**        | ✅ Yes – lets you inspect before applying             | ❌ No – applies changes immediately           |
| **Command combo**              | Standalone                                           | Equivalent to `git fetch` + `git merge`      |


### 🧪 `git fetch` (Safe & Inspect)

```bash
git fetch origin
```

* Downloads updates to remote-tracking branches like `origin/main`.
* Does **not** modify your current working branch.
* You can inspect the differences first:

```bash
git diff main origin/main
```

To update your branch manually:

```bash
git merge origin/main
```

### ⚡ `git pull` (Fetch + Merge)
```bash
git pull origin main
```

* Fetches latest changes from remote and **merges** into current branch.
* Immediately changes your working directory.
* Use with caution if you have local changes.

### 👨‍🔧 Use Case Advice
-
  | Situation                                      | Recommended Command       |
  | ---------------------------------------------- | ------------------------- |
  | Just want to see what’s new on remote          | `git fetch`               |
  | Ready to bring remote changes into your branch | `git pull`                |
  | Need to inspect or resolve conflicts manually  | `git fetch` + `git merge` |

- Great — let’s compare `git pull` vs `git pull --rebase`, which differ in **how** they integrate remote changes into your local branch:


## 🔁 `git pull` vs `git pull --rebase`

| Feature           | `git pull` (default)                 | `git pull --rebase`                   |
| ----------------- | ------------------------------------ | ------------------------------------- |
| **Mechanism**     | `git fetch` + `git merge`            | `git fetch` + `git rebase`            |
| **History style** | Creates a merge commit if needed     | Rewrites local commits onto new base  |
| **Commit graph**  | Can be non-linear (merge commits)    | Linear history (cleaner)              |
| **Conflicts**     | Resolved during merge                | Resolved during rebase (step-by-step) |
| **Ideal for**     | Team merges, preserving full history | Personal branches, cleaner PR history |

### 🔧 Example
Assume this situation:

```
origin/main:    A---B
your branch:        C---D
```

* `git pull` would result in:

  ```
  A---B-------M
       \     /
        C---D
  ```

  (merge commit `M` is created)

* `git pull --rebase` would result in:

  ```
  A---B---C'---D'
  ```

  (`C` and `D` are reapplied on top of `B`)

### ✅ Pros & Cons

#### `git pull`

* ✅ Safe for shared branches
* ❌ Messy history with many merges

#### `git pull --rebase`

* ✅ Clean, linear commit history
* ❌ Can be dangerous if rebasing shared/public branches


### 💡 Tip
- To make rebase the default:
  ```bash
  git config --global pull.rebase true
  ```

- To temporarily override it:

  ```bash
  git pull --no-rebase  # fallback to merge
  ```

- Here's a clear comparison between `.git` and `.gitignore` — both are essential but serve completely different purposes in a Git project:

## 📁 `.git` vs 📄 `.gitignore`

| Feature             | `.git`                                          | `.gitignore`                                        |
| ------------------- | ----------------------------------------------- | --------------------------------------------------- |
| **Type**            | Directory (hidden folder)                       | Text file                                           |
| **Purpose**         | Stores Git's internal tracking data and history | Specifies which files/folders Git should ignore     |
| **Created by**      | Automatically when `git init` is run            | Created manually (or via template)                  |
| **Tracked by Git?** | No (Git ignores its own metadata)               | Yes (can be committed to the repo)                  |
| **Safe to delete?** | ❌ No – deleting it removes all version history  | ✅ Yes – Git will start tracking ignored files again |

### 🔍 Details

#### 🗂️ `.git`
* Hidden directory in every Git repository.
* Contains:

  * `HEAD` pointer to current branch
  * `objects/` with commits, blobs, trees
  * `refs/` for branches/tags
  * `config`, `logs`, and more
* If you delete `.git`, **your entire repo becomes unversioned**.

#### 🚫 `.gitignore`

* Plain text file listing patterns to exclude from tracking.
* Examples:

  ```gitignore
  *.log
  node_modules/
  secret.env
  ```
* Helps avoid committing:

  * Build artifacts
  * OS-specific files (e.g., `.DS_Store`, `Thumbs.db`)
  * API keys or config files

### ✅ Example Usage

  ```bash
  # Create .gitignore
  echo "node_modules/" >> .gitignore
  echo "*.log" >> .gitignore
  
  # See ignored files
  git status --ignored
  ```

## `Pre-commit hooks`  Vs `Post-commit hooks`
- 
  | Feature                  | `pre-commit` Hook                                 | `post-commit` Hook                              |
  | ------------------------ | ------------------------------------------------- | ----------------------------------------------- |
  | **When it runs**         | *Before* a commit is created                      | *Immediately after* a commit is made            |
  | **Can stop commit?**     | ✅ Yes – can reject the commit                    | ❌ No – the commit has already happened        |
  | **Typical Use Cases**    | - Code formatting<br>- Linting<br>- Running tests | - Notifications<br>- Logging<br>- Triggering CI |
  | **Location**             | `.git/hooks/pre-commit`                           | `.git/hooks/post-commit`                        |
  | **Exit status matters?** | ✅ Yes – non-zero exit cancels commit             | 🚫 No – exit code is ignored                   |


### ✅ Example Use Cases

#### `pre-commit`
* Prevent bad code from being committed:

  ```bash
  #!/bin/bash
  eslint .
  if [ $? -ne 0 ]; then
    echo "Lint errors detected. Commit aborted."
    exit 1
  fi
  ```

#### `post-commit`
* Notify user or trigger an action:

  ```bash
  #!/bin/bash
  echo "Commit successful. Message was:"
  git log -1 --pretty=%B
  ```

### 📁 Where to place them?
- Hooks are placed in the `.git/hooks/` directory of your repo.
- They must be **executable**:

  ```bash
  chmod +x .git/hooks/pre-commit
  chmod +x .git/hooks/post-commit
  ```

## what is webhook ?
- A **webhook** is a way for one application to **send real-time data** to another application when a specific event happens — **without** needing the receiving app to constantly poll for updates.

## 🧠 In Simple Terms
> A webhook is like **"event-driven push notification"** between two systems.

## 🔧 How It Works

1. **You register a URL** (called a *webhook endpoint*) with a service.
2. When an **event** occurs (e.g., a GitHub commit, payment received, form submitted), the service sends an **HTTP POST** request to your webhook URL.
3. Your server **receives and processes** this data immediately.

## 📦 Real-World Examples
-
  | Service | Event Trigger        | Webhook Action                             |
  | ------- | -------------------- | ------------------------------------------ |
  | GitHub  | Code pushed to repo  | Notify CI server (e.g., Jenkins, CircleCI) |
  | Stripe  | Payment successful   | Update customer record in your app         |
  | Slack   | New message received | Post it to a database or dashboard         |
  | Shopify | Order placed         | Notify fulfillment system                  |


## 🔐 Security Practices
* Use **secret tokens** in headers to verify source.
* Limit IPs or use HMAC signatures.
* Validate payload before processing.

## 🔁 Webhooks vs API Polling
- 
  | Feature        | Webhook             | Polling                 |
  | -------------- | ------------------- | ----------------------- |
  | Triggered by   | Events              | Scheduled intervals     |
  | Resource usage | Low (only on event) | High (regular requests) |
  | Real-time      | ✅ Yes               | ❌ Delayed               |


## `git stash`
### 🧰 `git stash` — Temporary Storage for Your Work
- `git stash` is a Git command that **temporarily saves (or stashes)** your uncommitted changes (both tracked and untracked), so you can **work on something else**, and then **reapply them later**.

### ✅ Why Use `git stash`?
- Imagine you're working on something, but:
  - You need to switch branches to fix a bug.
  - You don’t want to commit your half-done changes.
  - You don’t want to lose your work.

- That’s where `git stash` helps.

### 🔧 Basic Commands
- 
  | Command                                 | Description                                 |
  | --------------------------------------- | ------------------------------------------- |
  | `git stash`                             | Stash tracked changes (default)             |
  | `git stash -u` or `--include-untracked` | Also stashes untracked files                |
  | `git stash list`                        | View all stashes                            |
  | `git stash pop`                         | Apply latest stash and remove it            |
  | `git stash apply`                       | Apply latest stash but **keep it** in stash |
  | `git stash drop`                        | Delete a specific stash                     |
  | `git stash clear`                       | Remove all stashes                          |

### 🧪 Example Workflow

```bash
# You made some changes...
git status

# But you want to quickly switch branches
git stash           # Save your changes
git checkout other-branch
# Work, fix things...

git checkout main
git stash pop       # Bring back your changes
```

### 📁 What Gets Stashed?

* Tracked file changes (modified or staged)
* Use `-u` to include untracked files
* Ignored files are NOT included by default

### How to amend a commit in git
- To **amend a commit in Git**, you use:

  ```bash
  git commit --amend
  ```

- This command lets you **modify the most recent commit** — whether to:
  * Change the commit message,
  * Add or remove files,
  * Or both.

### ✏️ Change Only the Commit Message
- 
  ```bash
  git commit --amend
  ```

* This opens your default editor (like Vim).
* You can change the commit message.
* Save and close to finish.

### ➕ Add Files to the Last Commit

1. Stage the new or changed files:

   ```bash
   git add <file>
   ```

2. Then amend:

   ```bash
   git commit --amend
   ```

- This updates the last commit to include the newly staged files.

### ⚠️ Warning on Amending Public Commits
- If you've already pushed the original commit to a remote:

  * Amending rewrites history.
  * You must **force push**:

    ```bash
    git push --force
    ```

> 🔥 Only do this if you're sure no one else is working on that branch!

## How to resolve merge conflict in git ?
### 🔧 How to Resolve a Merge Conflict in Git
- Merge conflicts happen when **two branches have changes in the same part of a file**, and Git can’t automatically decide which one to keep.

### 🪜 Steps to Resolve a Merge Conflict

### ✅ 1. **Trigger the Merge**

```bash
git merge <branch-name>
```

> If there’s a conflict, Git stops the merge and marks the conflicted files.


### 🔍 2. **Check Conflicted Files**

```bash
git status
```

> Shows files with **merge conflicts**.

### ✏️ 3. **Edit the Conflicted Files**

Git will mark conflicts like this:

```diff
<<<<<<< HEAD
your changes from current branch
=======
their changes from merging branch
>>>>>>> feature-branch
```

* Keep what you want.
* Remove the conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`).

### ✅ 4. **Stage the Resolved Files**

```bash
git add <file>
```

### 🧩 5. **Complete the Merge**

```bash
git commit
```

> If you ran `git merge` directly, Git may auto-create a merge commit message.


### ⏱ Example Workflow

```bash
git checkout main
git pull origin main

git checkout feature
git merge main     # conflict occurs

# resolve files manually...
git add .
git commit         # finalize merge
```

### 🛠️ Tools to Help

* **VS Code**, **Sublime Merge**, or **GitKraken** highlight and simplify conflict resolution.
* `git mergetool` can also open a graphical merge tool.

<br>
<br>

## Day 12 | Deploy and expose your First App to AWS | Feat. Kunal Verma | Live Project 
- After making the node application available locally on AWS machine, to access over internet globally, you need to add inbound rule for the port range and IP addresses that you want to allow to access your website.

- `0.0.0.0/0` CIDR range will allow anybody on the internet to access your website.

<br>
<br>

## Day 13 | Top 15 AWS Services that Every DevOps Engineers should learn 
> 🚀 AWS offers over **200+ services**, but the following **15 core services** are essential for DevOps engineers to build, deploy, monitor, and scale applications on the AWS cloud.

### **1. EC2 (Elastic Compute Cloud)**
- Scalable virtual machines used to host applications.
- You can define the OS, CPU, memory, and storage.
- Supports auto-scaling, load balancing, and custom AMIs.

### **2. VPC (Virtual Private Cloud)**
- Allows creation of isolated network environments within AWS.
- Key components:

  - **CIDR Blocks / Subnets** – Define IP ranges and logical segmentation.
  - **Security Groups** – Act as virtual firewalls for EC2 instances.
  - **NACLs (Network ACLs)** – Optional stateless firewalls for subnets.
  - **Internet Gateway / NAT Gateway** – For controlling internet access.

### **3. EBS (Elastic Block Store)**
- Persistent block storage volumes for EC2.
- Can be attached/detached from instances.
- Supports SSD, HDD, and IOPS-optimized volumes.

### **4. S3 (Simple Storage Service)**
- Object storage for files, logs, backups, static websites.
- Features:

  - **Versioning**, **Lifecycle Policies**, and **Bucket Policies**.
  - **Default encryption** using SSE (Server Side Encryption).
  - Supports hosting of **static websites**.

### **5. IAM (Identity and Access Management)**
- Manages **users, roles, policies**, and **permissions**.
- Supports MFA (Multi-Factor Authentication) and federated access.
- Fine-grained access control using JSON-based IAM policies.

### **6. CloudWatch**
- Centralized monitoring and observability platform.
- Features:

  - **Metrics**, **Logs**, **Alarms**, **Dashboards**, and **Events**.
  - Can trigger Lambda functions or auto-scaling based on thresholds.

### **7. Lambda**
- **Serverless compute** service to run code without provisioning servers.
- Suitable for:

  - Real-time file processing (e.g., from S3).
  - Automation and integrations (e.g., triggered by API Gateway, CloudWatch).
  - Lightweight backend tasks.
  - AWS Lambda functions are used for short actions which are created, executed and tear down automatically.

### **8. AWS Code Suite (CI/CD Services)**
- **AWS CodePipeline** – Orchestrates the CI/CD workflow.
- **AWS CodeBuild** – Builds and tests source code.
- **AWS CodeDeploy** – Automates deployment to EC2, Lambda, or ECS.
- ⚠️ *Note:* These services are **AWS-specific**; for portability, tools like Jenkins, GitHub Actions, or GitLab CI/CD may be preferred in multi-cloud environments.

### **9. AWS Config**
- Tracks and audits resource configurations.
- Helps in **compliance auditing** and **resource inventory tracking**.
- Can alert on drift from desired configurations.

### **10. AWS Budgets & Cost Explorer**
- Cost tracking and budgeting tools.
- Use **Budgets** to set alerts for cost or usage thresholds.
- **Cost Explorer** provides visualizations and forecasting for AWS spend.

### **11. AWS KMS (Key Management Service)**
- Manages encryption keys and integrates with most AWS services.
- Supports:
  - **Automatic key rotation**.
  - **Customer-managed keys (CMKs)**.
  - Secure integration with S3, EBS, RDS, Lambda, etc.

### **12. CloudTrail**
- Records **all API activity** and **account-level events**.
- Used for Operational Risk Auditing
- Essential for **security auditing**, **compliance**, and **incident response**.
- Works across all AWS services.

### **13. Amazon EKS (Elastic Kubernetes Service)**
- Fully managed **Kubernetes** service by AWS.
- Supports:
  - Integration with IAM for RBAC.
  - Auto-scaling worker nodes.
  - Seamless deployment of containerized apps with kubectl.

### **14. Amazon ECS & AWS Fargate**
- **ECS (Elastic Container Service)** – AWS-native container orchestration (an alternative to kubernetes).
- **Fargate** – Serverless compute engine for containers.
- Use ECS + Fargate to run containers **without managing EC2 instances**.

### **15. ELK Stack (ElasticSearch, Logstash, Kibana)**
- Often deployed on AWS for log aggregation and analysis.
- Used for:

  - Real-time **log ingestion**, **visualization**, and **search**.
  - Detecting errors, performance issues, and security anomalies.
- Can also use **Amazon OpenSearch** (managed version of Elasticsearch).
- Microservices emit lot of logging data.
- Retrieving common errors from these logs require efficient logging and search services.

### ✅ Additional Services to Consider:
- **Route 53** – DNS and traffic routing.
- **RDS / Aurora** – Managed relational databases.
- **Secrets Manager** – Secure storage for credentials and API keys.
- **CloudFormation / Terraform** – Infrastructure as Code (IaC).
- **Amazon SSM (System Manager)** – Manage EC2 instances securely without SSH.

<br>



## **Day-15 | Ansible Zero to Hero**







## Day-16 | Infrastructure as Code | #terraform #IaC