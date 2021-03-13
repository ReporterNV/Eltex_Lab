#!/bin/bash

man bash | grep -Eo '\b[A-Za-z0-9]{4,}\b' | uniq -c | sort | head -n 3
