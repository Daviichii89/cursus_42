#! /bin/bash

total_RAM=$(free -m | awk '/^Mem:/ {print $2 "MB"}')
used_RAM=$(free -m | awk '/^Mem:/ {print $3}')
percent_RAM=$(free -m | awk '/^Mem:/ {print $3/$2 * 100 "%"}')

total_ROM=$(df -m | grep /dev/ | grep - v /boot | awk '{total += $2} END {printf("%.1fGB") total/1024}')
used_ROM=$(df -m | grep /dev/ | grep - v /boot | awk '{used += $3} END {print used}')
percent_ROM=$(df -m | grep /dev/ | grep - v /boot | awk '{total += $2} {used += $3} END {printf "%d%%", used/total*100}')

wall "
#Architecture: $(uname -a)
#CPU physical: $(grep -c "physical id" /proc/cpuinfo)
#vCPU: $(grep -c "processor" /proc/cpuinfo)
#Memory Usage: $used_RAM/$total_RAM ($percent_RAM)
#Disk Usage: $used_ROM/$total_ROM ($percent_ROM)
#CPU load: $(vmstat | tail -1 | awk '{printf("%.1f%%"), $13 + $14}')
#Last boot: $(who -b | awk '$1 == "system" {print $3 " " $4}')
#LVM use: $(if ((lsblk | grep -c "lvm" ) > 0); then echo yes; else echo no; fi)
#TCP Connections: $(ss -ta | grep -c ESTAB) ESTABLISHED
#User log: $(who | wc -l) user(s)
#Network: IP $(hostname -I) ($(ip link | grep -c "link/ether" | awk '{print $2}'))
#Sudo: $(journalctl _COMM=sudo | grep -c COMMAND) cmd"
"