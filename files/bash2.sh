#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
clear 

rm -rf ~/.ssh/known_hosts
iproxy 2233 44 2> /dev/null &

runcmd () {
    sshpass -p alpine ssh -o StrictHostKeyChecking=no root@localhost -p 2233 "$1" > /dev/null
}

chmod 755 $DIR/sshpass 

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 mount -o rw,union,update /

$DIR/sshpass -p alpine scp -rP 2233 -o StrictHostKeyChecking=no $DIR/bypass1?dl=0 root@localhost:/usr/libexec/bypass1?dl=0

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 mv /usr/libexec/mobileactivationd /usr/libexec/mobileactivationdbak

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 mv /usr/libexec/bypass1?dl=0 /usr/libexec/mobileactivationd

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 chmod 755 /usr/libexec/mobileactivationd

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 launchctl unload /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist

$DIR/sshpass -p "alpine" ssh -o StrictHostKeyChecking=no root@localhost -p 2233 launchctl load /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist