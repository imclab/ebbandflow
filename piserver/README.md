piserver README
====================

piserver runs on a raspberry pi or local computer, connected to arduino through Serial

Some useful commands for working with piserver (scanning for ip address, etc)


port scan:
http://www.cyberciti.biz/networking/nmap-command-examples-tutorials/
http://hackertarget.com/nmap-cheatsheet-a-quick-reference-guide/
nmap -sP 192.168.1.0/24



my ip addy 192.168.0.22   (old ip)

pings to see if host is up:
nmap -sn 192.168.0.22/24

sudo nmap -sP 192.168.0.22/24

ssh pi@192.168.0.17

"sudo poweroff" shuts down; "sudo reboot" reboots

