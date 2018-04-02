#!/usr/bin/env bash

tmpfs=$(df -h | grep tmpfs|grep mnt)
if [ -z "${tmpfs}" ]; then
    echo "TMPFS is not mounted at /tmp"
    echo "Attempting to mount now"
    sudo mkdir -p /mnt/tmp
    sudo chmod 777 /mnt/tmp
    sudo mount -t tmpfs -o size=500M tmpfs /mnt/tmp >/dev/null 2>&1
    if [ $? -gt 0 ]; then
        echo "Unable to mount tmpfs file system in /tmp/mnt"
    else
        echo "Mounted successfully"
    fi
else
    echo "TMPFS already mounted"
fi
