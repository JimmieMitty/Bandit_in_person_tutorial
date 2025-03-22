#!/bin/bash

# Define the remote server and destination path
REMOTE_USER="pal"
REMOTE_HOST="10.234.6.53"
REMOTE_PATH="/home/pal/F1-_2025_Driver-interaction"

# Copy the entire bandit-movement-controller directory excluding build, devel, and TiagoMovementController.jpeg
rsync -av --exclude='build' --exclude='devel' tutorial "$REMOTE_USER@$REMOTE_HOST:$REMOTE_PATH"