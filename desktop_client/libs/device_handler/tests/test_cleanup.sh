#!/bin/bash
FILE_TO_BE_REMOVED="$1"/existing_file
rm -f "$FILE_TO_BE_REMOVED"

ROOT_OWNED_FILE_TO_BE_REMOVED="$1"/root_owned_file
rm -f "$ROOT_OWNED_FILE_TO_BE_REMOVED"
