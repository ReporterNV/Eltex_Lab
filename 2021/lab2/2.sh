#!/bin/bash

cat /var/log/Xorg.0.log | grep "II" | sed 's/(II)/Information:/' > full.log
cat /var/log/Xorg.0.log | grep "WW" | sed 's/(WW)/Warning:/' >> full.log
cat full.log

