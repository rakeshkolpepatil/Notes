# How to setup Passwordless Authentication
You need to use your ssh key or password only once while setting the Passwordless Authentication. For all other subsequent accesses you do not need to specify keys explicitly. 

## EC2 Instances

### Using Public Key

```
ssh-copy-id -f "-o IdentityFile <PATH TO PEM FILE>" ubuntu@<INSTANCE-PUBLIC-IP>

# OR = copy key for the AWS server for setting up passwordless server access. Generate 'AnsibleNode1.pem' file while creating EC2 instance. 
ssh-copy-id -f -o IdentityFile=/mnt/c/Users/John/aws_server/AnsibleNode1.pem  ubuntu@172.90.91.150
```

- `ssh-copy-id` : This is the command used to copy your public key to a remote machine.
- `-f` : This flag forces the copying of keys, which can be useful if you have keys already set up and want to overwrite them.
- `"-o IdentityFile <PATH TO PEM FILE>"` : This option specifies the identity file (private key) to use for the connection. The `-o` flag passes this option to the underlying ssh command.
- `ubuntu@<INSTANCE-IP>` : This is the username (ubuntu) and the IP address of the remote server you want to access.

### Using Password 

1. You need to login to the AWS EC2 instance at least once to set Passwordless Authentication and do following steps to enable Password Authentication as it is disabled by default on EC2 instances.
  1. Go to the file `/etc/ssh/sshd_config.d/60-cloudimg-settings.conf`
  2. Update `PasswordAuthentication yes`
  3. Also `PasswordAuthentication yes` in `/etc/ssh/sshd_config` file
  4. Restart SSH -> `sudo systemctl restart ssh`
  5. Create password for the user account (`ubuntu` by default) -> `sudo passwd ubuntu`

2. Now, logout the machine and use the `ssh-copy-id` command without specifying any Identity file.
  
  ```bash
  ssh-copy-id ubuntu@172.90.91.150
  ```

3. Specify the password you had set for ubuntu on `172.90.91.150` 
4. Also make sure that you have created a default public private pair of ssh key in your `/home/ubuntu/.ssh` folder.
