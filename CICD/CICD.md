# CICD (Continuous Integration Continuous Delivery)

Abhishek Veermalla [Video](Https://www.youtube.com/watch?v=CmVxoNkkACQ&list=PLdpzxOOAlwvLUH6ww022l7OZGakJYP9WY)

## Day 18 : Introduction to CICD 
- CICD helps in the atomization of the following steps which every application has to go through before getting delivered to the customer. 
  1. Unit Testing                         - checking the functionality of the newly developed code.
  2. Static Code Analysis                 - formatting of the code, adherence to the coding principles, removing warnings. 
  3. Code Quality/ Vulnerability Testing  - security checks
  4. Automation Testing                   - end to end testing of the code. 
  5. Reports                              - Testing Reports 
  6. Deployment                           - Deploying an application to the customer

- CICD gets executed whenever a developer pushes the code changes to a Version Control System (VCS)
- Jenkins is a legacy CICD orchestrator tool which helps/orchestrates the creation of CICD pipeline with the help of tools designed for specific tasks. 
- For example, in case of a Java application, Jenkins pipeline looks like this -
  
  ```
  Code Commit to VCS ➡ CICD Tool (Jenkins) ➡ 1. Maven (For Building Java Application)
                                            ➡ 2. JUnit/ JaCoCo (For Unit/Functional/Regression Testing of Java Applications)
                                            ➡ 3. Sonar (For code quality testing)
                                            ➡ 4. ALM - Application Lifecycle Management (For Reporting) 
                                                  Popular ALM tools include Atlassian Jira, Microsoft Azure DevOps, SpiraTeam, Jama Connect, and OpenText ALM Octane, among others. 
                                            ➡ 5. Kubernetes / Docker / EC2 Instance / Any Cloud Based VMs
                                            
                                             
  ```
- Devops Engineer will configure all of the above tools within Jenkins, so these tools executes the configured tasks whenever a code gets pushed to the repo.
- Jenkins can deploy an application to one of the three stages
  1. Development 
  2. Stage (Application is tested in staging stage before deploying it to the production, usually has less resources than production stage) 
  3. Production (The environment where customers are using the application and replicates the exact setup where you are deploying the application) 

- Jenkins can promote application to one of these environments with automatic approval or manual approval.
- Jenkins and Hudson are the legacy CI tools. 
- Jenkins is a binary which is installed on a machine, a master machine and keep on connecting EC2 instances depending upon load.
- Jenkins pipelines need to be run only when there are any code changes. However, Jenkins requires its instance to be run always. 
- So, to avoid this now a days GitHub actions, which is another CICD tool is used. GitHub action spins up a docker or kubernetes pod whenever a code is committed to a repo.
- This kubernetes pod or a docker container can be created on a runner, a worker node, on Azure cloud or EC2 or any kubernetes cluster, which runs CICD pipeline.
- These pods are deleted after finishing their tasks, thus saving the resources.
- Thus instead of creating a separate Jenkins server for each repo or team we can create a single GitHub action for all these repos which will launch pods and complete CICD pipeline.
- Following are the alternatives to the Jenkins CICD tool -
  1. GitHub Actions
  2. GitLab CI/CD
  3. CircleCI
  4. TeamCity
  5. Bamboo
  6. TravisCI
  7. CodeShip
- GitHub actions is a better tool than Jenkins as though Jenkins has support for the webhooks provided by Git, it is not event driven by default.  
- GitHub actions provides the feature where pipelines can be configured across multiple projects. 

## Explain the CI/CD pipeline implementation (Interview Question)

<br> <br>
<div style="text-align: center;">
<img src="CICD_example_flow.jpg" alt="CICD Flow" style="width:60%; height:auto; padding: 0 0" >
</div>
<br> <br>

- The CICD implementation starts with a VCS such as GitHub/GitLab and ends with the orchestrator such as Kubernetes.
- Whenever a code is committed to the repo by developer, the CICD orchestrator like Jenkins are triggered by the Git webhooks to execute the Jenkins pipeline.
- Jenkins pipeline does the task of continuous integration, which includes following sub-tasks that are included in the Jenkins File -

  1. Check out 
      - The entire code till that commit will be checked out. 
      
  2. Build & UT 
      - Build the code and run the unit test cases. 
      
  3. Code Scan 
      - Scan the code for security vulnerabilities, bugs. Example, SonarQube, SonarLint and SonarCloud tools are used for this.
      
  4. Image Build 
      - Build a docker/container image using Dockerfile from github
       
  5. Image Scan 
      - Scan the image for vulnerabilities
      
  6. Image Push 
      - Push the image to image registries such as DockerHub, query.io or ECR 

- Declarative Jenkins pipelines are preferred over Scripted Jenkins pipelines as they do not need much of the knowledge of groovy scripting.
- Image from the DockerHub is brought to kubernetes space inside `kubernetes manifests` which are again hosted on GitHub repo.
- Tools such as Argo CD or Git Ops tools such as flux CD these new changes will be deployed on kubernetes.
- Argo CD will be continuously watching the GitHub repo where Kubernetes YAML manifests files are stored and once it sees new commit, it will push the changes to the Kubernetes cluster.
- Instead of Argo CD even shell scripts, Ansible, Python scripts, kubeCTL binary or helm commands can be used to push the kubernetes manifests or Helm charts to the Kubernetes platform.

## Day 19 : Jenkins Zero to Hero | 3 Projects Live | Docker Agent
- 