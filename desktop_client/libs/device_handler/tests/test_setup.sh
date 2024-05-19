#!/bin/bash 
FILE_TO_BE_CREATED="$1"/existing_file
touch "$FILE_TO_BE_CREATED"

ROOT_OWNED_FILE="$1"/root_owned_file
touch "$ROOT_OWNED_FILE"
chmod -r "$ROOT_OWNED_FILE"
