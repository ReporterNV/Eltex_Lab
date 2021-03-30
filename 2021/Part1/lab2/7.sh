#!/bin/bash

man bash | grep -Eo '\b[A-Za-z]{4,}\b' | sort | uniq -c | sort -r | head -n3
