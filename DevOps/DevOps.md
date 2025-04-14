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
  2. AWS API using languages (Boto3 in Python)
  3. AWS CFT (Cloud Formation Templates) using Template languages
  4. Terraform (it can be used for creating resources on any cloud platform such as Google/Amazon/Microsoft cloud)
  5. AWS CDK (Cloud Development Kit)
  
- Any new features will get supported first on the AWS CDK than the Terraform as it is their proprietary tool.
- Terraform is chosen in organization where hybrid cloud pattern is used. For example - Google cloud is used for AI/ML/Kubernetes related tasks, RDS (Relational Database Service) on AWS.
- Azure Resource Manager is a Private Network Access (PNA) for Microsoft cloud, similar to AWS CFT for AWS.
- 