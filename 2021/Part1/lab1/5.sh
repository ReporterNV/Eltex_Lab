#!/bin/bash/

echo "Choose programm:"
echo "1)nano"
echo "2)vi"
echo "3)links"
echo "4)quit"

read -r;
case "$REPLY" in 
1) 
nano
;;
2) 
vi
;;
3) 
links # install it 
;;
4)
exit 0;
;;
esac
