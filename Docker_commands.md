# DOCKER 

- Docker provides the ability to package and run an application in a loosely isolated environment called a container. 
- The isolation and security allows you to run many containers simultaneously on a given host. 
- Containers are lightweight and contain everything needed to run the application, so you do not need to rely on what is currently installed on the host. 
- You can easily share containers while you work, and get ensured that everyone you share the image with gets the same container that works in the same way

## INSTALLATION 
  ```
  https://docs.docker.com/desktop             # Docker Desktop is available for Mac, Linux and Windows
  https://docs.docker.com                     # Check out our docs for information on using Docker
  https://github.com/docker/awesome-compose   # View example projects that use Docker
  ```
##  IMAGES 
- Docker file describes all the dependencies/things that a container needs.
- Docker images are a lightweight, standalone, executable package of software that includes everything needed to run an application: code, runtime, 
  system tools, system libraries and settings.
  
  ```bash
  
  # Build an Image from the default 'Dockerfile' present in current directory, give 'myName' name to image and version 01.
  # You can also add or tag an image name and version to an existing image id.
  docker build -t myName:01 .

  # Suppress output during the build process (quiet mode)
  docker build --quiet -t myName:01 .

  # Build a Docker image using a custom Dockerfile name. Replace 'CustomDockerfile' with your custom Dockerfile name
  docker build -t myName:01 -f CustomDockerfile .

  # To create an image of next version of the 'myName' app. Issue this command after making desired changes to the 
  # codebase. Most of the time 'Dockerfile' will remain the same.
  docker build -t myName:02   			          
                                                
  # Build a Docker Image from a Dockerfile without using cache (forces a fresh build)
  docker build -t <image_name> . –no-cache  	

  # Build a Docker image with a build-time variable
  # Replace 'VERSION=10' with your desired variable and value
  docker build --build-arg VERSION=10 -t myName:01 .

  # Build a specific stage from a multi-stage Dockerfile
  # Replace 'mytarget' with the desired stage name
  docker build --target mytarget -t myName:01 .

  # List local images
  docker images 		      	                  
  
  # List all Docker images with detailed information (includes size, creation date, etc.)
  docker images --all

  # Filter images by repository name (e.g., show only images from 'myRepo')
  docker images myRepo

  # Display only the IDs of Docker images
  docker images --quiet
  
  # Show untagged (dangling) images
  docker images --filter "dangling=true"

  # Use a custom format to display image details (e.g., show only repository and tag)
  docker images --format "{{.Repository}}:{{.Tag}}"

  # List images sorted by size
  docker images --format "{{.Repository}}:{{.Tag}} {{.Size}}" | sort -k2 -h

  # Delete an Image named 'image_name' and tag '01'. You can also specify image Id here.
  docker rmi <image_name:01> 	                
  
  # Remove multiple Docker images by name or ID
  docker rmi image1 image2 image3

  # Forcefully remove an image even if it is in use by a container
  docker rmi -f myName:01

  # Remove an image without deleting untagged parent images
  docker rmi --no-prune myName:01

  # Remove dangling (untagged) images
  docker rmi $(docker images -f "dangling=true" -q)

  # Remove all images from the system (use with caution)
  docker rmi $(docker images -q)

  # Remove images created before a specific image
  docker rmi $(docker images --filter "before=myName:01" -q)

  # Remove all unused images
  docker image prune 		                      
  ```

## DOCKER HUB 
- Docker Hub is a service provided by Docker for finding and sharing container images with your team. 
- Learn more and find images at https://hub.docker.com
  
  ```bash
  # Login into Docker using the username and password that you use for dockerhub.com
  docker login -u <username>   		          
  (OR) docker login
  
  # Publish an image to Docker Hub, <username> - your username on 'dockerhub.com'.  
  docker push <username>/<image_name>:tag	  
  
  # Search Hub for an image, <image_name> should be as specified on 'dockerhub.com'.
  docker search <image_name>		           

  # Pull an image from a Docker Hub
  docker pull <username>/<image_name>:<tag>

  # Logout from Docker Hub (useful for switching accounts or security)
  docker logout

  # Save a Docker image as a tar file (useful before pushing to Docker Hub)
  docker save -o <file_name>.tar <image_name>:<tag>

  # Load a saved image tar file (useful for importing before pushing to Docker Hub)
  docker load -i <file_name>.tar

  # Inspect an image pulled from Docker Hub (to view metadata or debug issues)
  docker inspect <image_name>:<tag>

  # Tag a local image before pushing to Docker Hub
  docker tag <local_image_name>:<local_tag> <username>/<image_name>:<tag>
  ```

## Docker File  
- Docker file has instructions to create a Docker image
- Following is an example of a sample Docker file
  
  ```bash    
  FROM node                       # Selects the latest Node.js image as the base for your Docker image.
                                  # You can specify a version if needed, e.g., FROM node:14. 

  WORKDIR /myapp                  # Sets the working directory in the container to /myapp.
                                  # All subsequent commands will be executed from this directory unless changed.

  COPY . .                        # Copies the contents of the local directory (where the Dockerfile resides) into the container's working directory (/myapp).
  (OR)
  COPY package*.json ./           # Copy all the files starting with "package" string and ending with "json" string to container's current directory.
  (OR)
  COPY --from=installer /app ./   # In a multi-stage build, copies files from the /app directory of the installer stage into the current directory (./) of the current stage.

  RUN npm install                 # The created image should have npm packages installed already. Command to add dependencies of the app 
                                  # to the image. This command is run while building an image from docker file while 'CMD' commands are run
                                  # while creating container from an image. 

  EXPOSE 3000                     # Exposes port 3000 from the container to the host, allowing incoming connections.
                                  # Note that this does not automatically map the port on the host; you need to use -p with docker run for that.

  CMD [ "npm", "start" ]          # CMD runs the specified command while creating a container from an image. It is an entry point to the container.
                                  # Specifies the default command to run when the container is started.
                                  # This command is executed when the container is created from the image and can be overridden with docker run.  

  VOLUME /myapp/logs              # VOLUME: Mounts a volume at a specified location in the container.

  ENV NODE_ENV=production         # ENV: Sets environment variables in the container.

  ARG BUILD_VERSION=1.0           # ARG: Defines build-time variables that can be passed during the build process.

  USER node                       # USER: Sets the user to run the container as.

  HEALTHCHECK --interval=30s --timeout=5s --retries=3  CMD curl --fail http://localhost:3000/healthcheck || exit 1
                                  # HEALTHCHECK: Specifies a command to check the health of the container.

  ENTRYPOINT [ "npm", "start" ]   # ENTRYPOINT: Similar to CMD, but it is not easily overridden when running the container.

  ```

- Once you create a docker file as described above inside a directory, to build it and create an image, execute following commands in same directory
  ```bash
  docker build .              # '.' means 'Dockerfile' is present in the current directory. or else specify the path of the directory where 'dockerfile' is present. Create an image from docker file.

  docker image ls             # To list out the created images.
  docker run <IMAGE_ID>       # Command to create a container by running the image created by 'docker build .' command. 
  ```

## CONTAINERS 
- A container is a runtime instance of a docker image. A container will always run the same, regardless of the infrastructure.
- Containers isolate software from its environment and ensure that it works uniformly despite differences for instance between development and staging.

  ```bash
  # Start the docker daemon
  docker -d                                                     

  # Get help with Docker. Can also use –help on all subcommands
  docker --help                                                 
  # (OR) 
  docker ps --help                                              # Get help on 'ps' command of docker.
  # (OR) 
  docker image --help                                           # Get help on 'image' command of docker.
  
  docker info                                                   # Display system-wide information
  docker stats                                                  # Display a live stream of resource usage statistics for running Docker containers. 
                                                                # It provides real-time data on CPU, memory, network I/O, and block I/O usage for each container.

  systemctl start docker.service
  (OR) systemctl start docker                                   # Start docker service manually

  systemctl status docker.service                               # Get status of docker service
  (OR) systemctl status docker                                  

  sudo systemctl enable docker                                  # To configure Docker to start automatically at boot

  sudo usermod -aG docker $USER                                 # Add your user to the Docker group to avoid permission issues.

  docker run --name <container_name> <image_name>		            # Create and run a container from an image 'image_name', with a custom name 'container_name'
  docker run --rm  <image_name>		                              # '--rm' switch will remove the container immediately after it is stopped, so that we will not be 
                                                                  required it to remove manually, by issuing command 'docker rm <container_name>'

  docker top <containerId/Name>                                 # Display the running processes within a Docker container

  docker run -p <host_port>:<container_port> <image_name>	      # Run a container with and publish a container’s port(s) to the host
  (Or) docker run -P <image_name>	                              # Run a container from image 'image_name' and publish its all ports to the host

  docker start|stop <container_name> (or <container-id>)	      # Start or stop an existing container

  docker inspect <container_name> (or <container_id>)	          #  To inspect a running container. Returns low level details of a container in JSON format. System administrators 
                                                                   can use this command to monitor resource usage and configurations of running containers. By using the "--format" 
                                                                   option, scripts can automate tasks based on specific attributes of Docker objects.

  docker run -d <image_name>		                                # Run a container in the background i.e. detached mode
  docker rm <container_name>		                                # Remove a stopped container

  docker logs -f <container_name>	                              # Fetch and follow the logs of a container named <container_name> in real-time
  (OR) docker logs <container_id> --follow
  (OR) docker logs <container_id> -f
  
  Switches with logs command - 
                                  --tail or -n                  # To view the last N number of log lines
                                  --timestamps or -t            # To include timestamps
                                  --since or -s                 # To view logs since a specific timestamp
                                  --until or -u                 # To view logs before a specific timestamp
                                  docker logs <container_id> | grep <pattern>

  docker exec -it <container_name> sh	                          # Open a shell inside a running container. This executes the program like 'sh' specified 
                                                                # in the command after running the container. 
                                                                # '-it' switch stands for 'interactive terminal' which binds to terminal to the running container.
                                                                # -i: Keeps STDIN open for interactive input.
                                                                # -t: Allocates a pseudo-TTY (terminal) for the session.
                                                                # sh: Specifies the shell to open. If sh is unavailable, you can use alternatives like bash.

  # Run Commands in a Container:
  # Execute any command inside a running container without disrupting its operation.

  docker exec <container_name> <command>

  # Example:
  # Lists the contents of the /app directory inside the container.

  docker exec my_container ls /app


  # Start an Interactive Bash Shell:
  # If bash is available in the container, it can be used instead of sh.

  docker exec -it <container_name> /bin/bash

  # Run Commands as a Specific User:
  # Execute commands with non-root privileges by specifying a user.

  docker exec -u <username_or_uid> <container_name> whoami

  # Set Environment Variables for Commands:
  # Pass environment variables to commands executed inside the container.

  docker exec -e MY_VAR=value <container_name> echo $MY_VAR

  # Run Commands in Detached Mode:
  # Execute commands in the background without attaching to the terminal.

  docker exec -d <container_name> <command>

  # Specify Working Directory:
  # Run commands from a specific directory inside the container.

  docker exec -w /myapp <container_name> ls

  # Debugging and Troubleshooting:
  # Start an interactive shell session for debugging or inspecting container internals without stopping its operation.

  docker exec -it <container_name> /bin/bash

  # Run Complex Commands:
  # Use sh -c to execute chained or complex commands inside the container.

  docker exec -it <container_name> sh -c "echo Hello && echo World"

  # Inspect Running Processes:
  # View processes running inside the container.
  docker exec <container_name> ps aux

  # Execute Maintenance Tasks:
  # Run one-off scripts like migrations or backups directly inside containers.

  docker exec <container_name> /scripts/migrate.sh

  docker ps		                                                  # Displays only the containers that are actively running on the Docker host.

  docker ps --all	                                              # List All Containers, includes stopped, paused, exited, and dead containers in the output.
  (Or) docker ps -a
  
  docker ps -q	                                                # List all docker containers (running and stopped), List Only Container IDs:

  docker ps --latest                                            # Displays details of the most recently created container, regardless of its state.

  docker ps --last <number>                                     # Shows details of a specified number of recently created containers.

  docker diff                                                   # View the differences between the container's filesystem and its base image
                                                                    Output indicates -
                                                                                    'A' for added files or directories
                                                                                    'C' for changed files or directories
                                                                                    'D' for deleted files or directories

  docker container stats	                                      #   View resource usage stats

  docker port <containerId>                                     #   Display the port mappings for the container with the ID 'containerId'

  docker rename Old_name New_name                               #   Rename the container named 'Old_name' to 'New_name'

  docker commit ad9f71ce3a04 myNewImage:latest                  #   This command will create a new Docker image named 'myNewImage:latest' from the changes made to 
                                                                    the container with the ID 'ad9f71ce3a04'
 
  docker run --add-host myhost:192.168.1.100 myimage            #   Create a new Docker container from the myimage image and add a host entry for myhost with the IP 
                                                                    address 192.168.1.100
                                                                    - Host entries are used to map hostnames to IP addresses.
                                                                    - They are stored in the '/etc/hosts' file within the container.
 
  docker tag <imageId> name:version                             #   Gives name 'name' and version 'version' to the image with id 'imageId'.
                                                                    You can also use this command to change the tag/name associated with the existing image.
                                                                    I think it will not rename the tag but create a copy of the existing image with new tag.

  docker scout quickview <user_name>/<repo_name>:<tag>          #   View a summary of image vulnerabilities and recommendations 
  e.g. -
          docker scout quickview rakeshpatil/kubetutorial:v1

  docker system prune -a                                    #   This command is used to clean up unused Docker resources and reclaim disk space.
                                                                Purpose: The command is designed to remove all unused containers, networks, images
                                                                (both dangling and unreferenced), and optionally volumes. This helps in freeing up 
                                                                storage space that Docker might be using unnecessarily. 
                                                                    
                                                                Using docker system prune -a can be quite destructive, especially on systems where multiple projects 
                                                                are using shared resources. It is advisable to ensure that no critical images or containers are 
                                                                inadvertently removed. 
                                                                  
  docker container prune                                    #   To remove stopped containers.

  docker attach <container_id_or_name>                      # To attach to a running Docker container's terminal session.
  docker exec -it <container_name_or_id> bash               # Open a new shell with docker
  
  # Detach from container without stopping
  ctrl+P, ctrl+Q

  # Reattach to container later
  docker attach my-container

  # Exit and stop the container
       exit
  (or) ctrl + d
  (or) ctrl + c, ctrl + d                                   # stop the running process and exit.
  ```    
## Docker Filter 

```bash
# Filter by Name:
# Lists containers whose names match a specific substring.

docker ps --filter "name=<container_name>"

# Filter by Image Ancestor:
# Displays containers created from a specific image or its descendants.

docker ps --filter "ancestor=<image_name>:<tag>"

# Filter by Status:
# Filters containers based on their status (e.g., running, exited, paused, etc.).

docker ps --filter "status=<status>"

# Filter by Exit Code:
# Lists containers that exited with a specific status code.

docker ps --all --filter "exited=<code>"

# Filter by Volume Mounts:
# Shows containers that mount a specific volume or path.

docker ps --filter "volume=/path/to/directory"  

# List Containers Before/After Specific Container:
# Filter containers based on their creation time relative to another container.

docker ps --filter "before=<container_name>"
docker ps --filter "since=<container_name>"

# Display Full Output Without Truncation:
# Prevents truncation of long fields like commands or names in the output.

docker ps --no-trunc

# Display Container Sizes:
# Shows file sizes associated with each container (useful for debugging storage issues).

docker ps --size
```

## Customized Output 
```bash
# Format Output Using Go Templates:
# Specify columns to display using a custom format.

docker ps --format "table {{.Names}}\t{{.Image}}\t{{.Status}}"

# Example formats:
# Display only names and IDs:

docker ps --format "{{.ID}}: {{.Names}}"
```

##  Docker Volumes  :- Nice Video for file sharing between computer and container - https://www.youtube.com/watch?v=gyddZyc8r48

```bash
docker volume --help                                          # Displays all the commands that can work with 'docker volume' 

docker volume ls                                              # Displays all the volumes 
  
docker run -v HOSTDIR:TARGETDIR image

docker run -v ~/:/usr/share/nginx/html nginx                  # Map the local directory into the container directory.

docker run -it --rm -v myvolume:/myapp/  containerId          # Creates a volume named 'myvolume' on host machine which is managed entirely by docker for storing the
                                                              # data generated by container 'containerId'. The data is stored inside directory '/myapp/' in that volume.
                                                              # The data remains persistent even after 'containerId' stops or is deleted. 
                                                              # Useful when you want to save the data generated by container.
```

## Docker Bind Mounts  
- When a container code is dependent on external file which gets updated continuously even while container is running, we can use docker bind mounts.
- I think this is paid feature and not available for free users. 
  
  ```bash
  docker run -it -v ~/:/usr/share/nginx/html nginx            # Map the local directory into the container directory. When using this on windows, you need to 
                                                              # check file paths by using autocompletion.  
  ```
  
## Notes [Video](https://www.youtube.com/watch?v=3c-iBn73dDE)

### Container ?
- A way to package application with all the necessary dependencies and configuration.
- Is a portable artifact that can be easily shared and moved around.
- Makes development and deployment more efficient.
- Container images are stored in public or private repository. The official repository for storing images is Docker hub.
- Most of the famous applications have their images on Docker hub.
- Container has its own isolated environment with OS layer, packaged with all needed configuration and dependencies so you just need one docker command to install the app.
- Containers enable to have multiple versions of the same application running on the same machine.
- Because of the containers operations team do not need to do any environment variable setup on servers.
- Usually, containers are made from layers of images, mostly linux base image as it is small in size (alpine:3.10) and application image on the top.

## Notes [Video](https://www.youtube.com/watch?v=OhnTMWmfTBE)

- Dockerfile  
  - It is simple text file with instructions to build an image.

- Image  
  - It is single file with all dependencies and libraries to run the program.

- Container  
  - Instance of an image.

- Docker Registry  
  - It is private or public central repository for storing and sharing docker images e.g. Docker hub or private registry
  
