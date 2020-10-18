#!/bin/bash

ieliek="$(date '+%d-%m-%Y')"
git init
git config user.name "andrisstuks"
git add .
git commit -m "$ieliek"
git push origin master



