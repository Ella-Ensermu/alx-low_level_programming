#!/bin/bash

# Replace <repository_url> with the actual repository URL
repository_url="https://github.com/Ella-Ensermu/alx-low_level_programming.git"

# Clone the repository
git clone "$repository_url" || {
    # Check if the error is related to permission denied (403)
    if [ $? -eq 128 ]; then
        echo "Permission denied. Check your credentials and repository access."
    else
        echo "An error occurred while cloning the repository."
    fi
}
