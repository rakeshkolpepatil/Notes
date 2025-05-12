#!/bin/bash
##########################
# Author: Rakesh
# Date: 4 May 2025
# Version: v1 
# Usage: This script is used for tracking AWS Usage of S3, EC2, IAM and Lambda Functions
##########################

set -x 

# List s3 buckets
aws s3 ls > output

# List EC2 instances
aws ec2 describe-instances | jq '.Reservations[].Instances[].InstanceId' >> output

# list Lambda
aws lambda list-functions >> output

# list IAM users
aws iam list-users >> output

